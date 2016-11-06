#ifndef _STATEMANAGER_H
#define _STATEMANAGER_H

#include <Arduino.h>

#include "constants.h"
#include "multimeter.h"

enum State{
    INIT,
    DISCHARGING,
    PAUSED,
    DISCHARGED,
    CHARGING,
    CHARGED
};


static inline char *stringFromState(enum State f)
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
	StateManager(Multimeter* multimeter);

	void init();

	void loop(unsigned long nowMs, unsigned long dtMs);

    State getState();

private:
    State state;
    Multimeter* multimeter;

    void readSerial();
    void applyState();
    void nextStates();

};
#endif