#ifndef _STATEMANAGER_H
#define _STATEMANAGER_H

#include <Arduino.h>

#include "constants.h"

class StateManager{
public:
	StateManager();

	void init();

	void loop(unsigned long nowMs, unsigned long dtMs);


private:
    void readSerial();

};
#endif