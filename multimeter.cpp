#include "multimeter.h"

Multimeter::Multimeter(){
}


void Multimeter::init(){
    pinMode(PIN_BATTERY, INPUT);
    pinMode(PIN_REF, INPUT);
}

void Multimeter::loop(unsigned long nowMs, unsigned long dtMs){
    this->timeAcc += dtMs;
    for(int i=0; i<READING_PER_LOOP;i++){
        this->read(nowMs);
        delay(1);
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

void Multimeter::read(unsigned long nowMs){
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
        Serial.println(this->refVoltage);

        this->readingCount = 0;
        this->batterySum = 0.0;
        this->refSum = 0.0;
    }
}
