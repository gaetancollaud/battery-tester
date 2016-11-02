#include "multimeter.h"

Multimeter::Multimeter(){
}


void Multimeter::init(){
}

void Multimeter::loop(unsigned long dtMs){
analogRead(PIN_BATTERY);
analogRead(PIN_REF)
}

float Multimeter::getVoltage(){
    return 5.1;
}
