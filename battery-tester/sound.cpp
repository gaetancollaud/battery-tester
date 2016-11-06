#include "statemanager.h"

Sound::Sound(){
    this->playing = false;
    this->on = false;
}

void Sound::init(){
    pinMode(PIN_BUZZER, OUTPUT);
    digitalWrite(PIN_BUZZER, LOW);
}

void Sound::loop(unsigned long nowMs, unsigned long dtMs){
    this->nowMs = nowMs;
    if(this->playing){
        if(nowMs > this->stopPlaying){
            this->playing = false;
        }else{
            this->on = !this->on;
            digitalWrite(PIN_BUZZER, this->on ? HIGH : LOW);
        }
    }else{
        digitalWrite(PIN_BUZZER, LOW);
    }
}

void Sound::play(unsigned long duration){
    this->stopPlaying = this->nowMs + duration;
    this->playing = true;
}


