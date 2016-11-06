#include "multimeter.h"

Multimeter::Multimeter(){
  this->lastAccCapacity = 0;
  this->running = false;
  this->readingCount = 0;
  this->batterySum = 0;
  this->refSum = 0;
  this->batteryVoltage = 10;
  this->refVoltage = 10;
  this->currentMa = 0;
  this->capacity = 0;
}

void Multimeter::init(){
    pinMode(PIN_BATTERY, INPUT);
    pinMode(PIN_REF, INPUT);
}

void Multimeter::loop(unsigned long nowMs, unsigned long dtMs){
    for(int i=0; i<READING_PER_LOOP;i++){
        this->read();
        delay(1);
    }
    if(!this->running){
        //while not running keep the last time acc to now
        this->lastAccCapacity = nowMs;
    }else{
        computeCapacity(nowMs);
    }
}

float Multimeter::getBatteryVoltage(){
    return this->batteryVoltage;
}
float Multimeter::getRefVoltage(){
    return this->refVoltage;
}
float Multimeter::getCurrentMa(){
    return this->currentMa;
}
float Multimeter::getCapacity(){
    return this->capacity;
}

void Multimeter::setRunning(bool v){
    this->running = v;
}

void Multimeter::read(){
    this->readingCount++;
    this->batterySum += analogRead(PIN_BATTERY);
    this->refSum += analogRead(PIN_REF);
    if(this->readingCount>=READINGS){
        this->batterySum *= READINGS_REVERSE;
        this->refSum *= READINGS_REVERSE;
        this->batteryVoltage = this->batterySum * REF_VOLTAGE *0.001953125;
        this->refVoltage = this->refSum * REF_VOLTAGE * 0.001953125;
        this->currentMa = (this->batteryVoltage - this->refVoltage) / RESISTANCE_OHM * 1000;

        Serial.print(this->batteryVoltage);
        Serial.print("\t");
        Serial.print(this->currentMa);
        Serial.print("\t");
        Serial.println(this->capacity);

        this->readingCount = 0;
        this->batterySum = 0.0;
        this->refSum = 0.0;
    }
}

void Multimeter::computeCapacity(unsigned long nowMs){
    unsigned long nextAcc = this->lastAccCapacity + CAPACITY_DELAY;
    if(nowMs>=nextAcc){
        this->capacity += this->currentMa * CAPACITY_BYHOUR;
        this->lastAccCapacity = nextAcc;
    }
}
