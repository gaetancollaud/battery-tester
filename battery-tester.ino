
#include <U8glib.h>

#include "multimeter.h"
#include "display.h"
#include "statemanager.h"

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI

unsigned long lastLoop = 0;

Multimeter multimeter;
StateManager stateManager(&multimeter);
Display display(&u8g, &multimeter, &stateManager);

void setup(){
    Serial.begin(115200);

    multimeter.init();
    display.init();
    stateManager.init();
}

void loop(){
    unsigned long nowMs = millis();
    unsigned long dtMs = nowMs - lastLoop;

    multimeter.loop(nowMs, dtMs);
    display.loop(nowMs, dtMs);
    stateManager.loop(nowMs, dtMs);

    lastLoop = nowMs;
}