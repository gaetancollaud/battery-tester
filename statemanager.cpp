#include "statemanager.h"

StateManager::StateManager(Multimeter* multimeter) : multimeter(multimeter){
    this->state = INIT;
}

void StateManager::init(){
    pinMode(PIN_MOSFET, OUTPUT);
    pinMode(PIN_CHARGING, INPUT);

    digitalWrite(PIN_MOSFET, LOW);
}

void StateManager::loop(unsigned long nowMs, unsigned long dtMs){
    this->nextStates();
    this->readSerial();
    this->applyState();
}

State StateManager::getState(){
    return this->state;
}

void StateManager::readSerial(){
    while(Serial.available()){
        char read = Serial.read();
        switch(read){
            case '1':
            this->state = DISCHARGING;
            break;
            case '0':
            this->state = PAUSED;
            break;
        }
    }
}

void StateManager::nextStates(){
    if(digitalRead(PIN_CHARGING) == LOW){
        this->state = CHARGING;
    }else if(this->multimeter->getBatteryVoltage() <= VOLTAGE_MIN){
        Serial.print("voltage too low :");
        Serial.println(this->multimeter->getBatteryVoltage());
        this->state = DISCHARGED;
    } else if(this->state == INIT){
        this->state = DISCHARGING;
    } else if(this->state == CHARGING){
        this->state = DISCHARGING;
    }
}

void StateManager::applyState(){
     bool discharging = this->state==DISCHARGING;
    digitalWrite(PIN_MOSFET, discharging  ? HIGH : LOW);
    this->multimeter->setRunning(discharging);
}