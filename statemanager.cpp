#include "statemanager.h"

StateManager::StateManager(){
}

void StateManager::init(){
    pinMode(PIN_MOSFET, OUTPUT);
    digitalWrite(PIN_MOSFET, LOW);
}

void StateManager::loop(unsigned long nowMs, unsigned long dtMs){
    this->readSerial();
}

void StateManager::readSerial(){
    while(Serial.available()){
        char read = Serial.read();
        switch(read){
            case '1':
            Serial.println("discharging");
            digitalWrite(PIN_MOSFET, HIGH);
            break;
            case '0':
            Serial.println("stop");
            digitalWrite(PIN_MOSFET, LOW);
            break;
        }
    }
}