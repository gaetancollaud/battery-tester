#ifndef _SOUND_H
#define _SOUND_H

#include <Arduino.h>

#include "constants.h"

class Sound{
public:
	Sound();

	void init();

	void loop(unsigned long nowMs, unsigned long dtMs);

    void play(unsigned long duration);

private:
    unsigned long stopPlaying;
    unsigned long nowMs;
    bool playing;
    bool on;

};
#endif