#include "display.h"

Display::Display(U8GLIB_SH1106_128X64* u8g, Multimeter* multimeter, StateManager* stateManager) :
    u8g(u8g), multimeter(multimeter), stateManager(stateManager){

}

void Display::init(){
}

void Display::loop(unsigned long nowMs, unsigned long dtMs){
//    if(nowMs>this->nextDraw){
//        this->nextDraw = nowMs + DRAW_DELAY_MS;
        this->update();
//    }
}

void Display::draw(){
    u8g->setFont(u8g_font_fub14r); // select font
    float volt = this->multimeter->getBatteryVoltage();
    float ma = this->multimeter->getCurrentMa();
    State state = this->stateManager->getState();

    float capacity = 5878.587;

    u8g->drawStr(0, 20, "Volt: ");   // put string of display at position X, Y
    if(state==DISCHARGING){
        u8g->drawStr(0, 40, "Curr: ");
    }else{
        char* stateStr = stringFromState(state);
        u8g->drawStr(0, 40, stateStr);
    }
    u8g->drawStr(0, 60, "mAh: ");
    u8g->setPrintPos(58,20);        // set position
    u8g->drawStr(0, 20, "Volt: ");
    u8g->print( volt,2);  // display Battery Voltage in Volt
    u8g->println("V");
    if(state==DISCHARGING){
        u8g->setPrintPos(58,40);        // set position
        u8g->print( ma,1);  // display current in mA
        u8g->println("mA");
    }
    u8g->setPrintPos(58, 60);        // set position
    u8g->print( capacity ,1);     // display capacity in mAh
}

void Display::update(){
    unsigned long s = millis();
    if(!this->nextPage){
        u8g->firstPage();
    }
    this->draw();
    this->nextPage = u8g->nextPage();

    s = millis() - s;
}

