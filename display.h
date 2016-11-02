#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <U8glib.h>
#include <Arduino.h>

#include "constants.h"
#include "multimeter.h"

#define DRAW_DELAY_MS 200

class Display{
public:
	Display(U8GLIB_SH1106_128X64* u8g, Multimeter* multimeter);

	void init();

	void loop(unsigned long nowMs, unsigned long dtMs);

private:
    unsigned long nextDraw=0;
    bool nextPage = false;

    U8GLIB_SH1106_128X64* u8g;
    Multimeter* multimeter;

    void draw();
    void update();

};
#endif