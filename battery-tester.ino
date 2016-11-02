
#include <U8glib.h>

#include "multimeter.h"
#include "display.h"
#include "statemanager.h"

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI

unsigned long lastLoop = 0;

Multimeter multimeter;
Display display(&u8g);
StateManager stateManager;

void setup(){
    Serial.begin(115200);

    multimeter.init();
    display.init();
    stateManager.init();
}

void loop(){
    unsigned long now = millis();
    unsigned long dtMs = now - lastLoop;

    multimeter.loop(dtMs);
    display.loop(now, dtMs);
    stateManager.loop(dtMs);

    lastLoop = now;
}