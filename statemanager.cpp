#include "statemanager.h"

StateManager::StateManager(){
}

void StateManager::init(){
    pinMode(PIN_MOSFET, OUTPUT);
    digitalWrite(PIN_MOSFET, LOW);
}

void StateManager::loop(unsigned long dtMs){
}