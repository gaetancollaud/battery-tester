#ifndef _STATEMANAGER_H
#define _STATEMANAGER_H

#include <Arduino.h>

#include "constants.h"
#include "multimeter.h"
#include "sound.h"

#define END_SOUND_DURATION 10000

enum State{
    INIT,
    DISCHARGING,
    PAUSED,
    DISCHARGED,
    CHARGING,
    CHARGED
};


static inline const char *stringFromState(enum State f)
{
    static const char *strings[] = {
        "Init",
        "",
        "Pause",
        "Discharged",
        "Charging",
        "Charged"
    };

    return strings[f];
}

class StateManager{
public:
	StateManager(Multimeter* multimeter, Sound* sound);

	void init();

	void loop(unsigned long nowMs, unsigned long dtMs);

    State getState();

private:
    State state;
    Multimeter* multimeter;
    Sound* sound;

    void readSerial();
    void applyState();
    void nextStates();

};
#endif
