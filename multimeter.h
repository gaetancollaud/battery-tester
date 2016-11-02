#ifndef _MULTIMETER_H
#define _MULTIMETER_H

#include "constants.h"

class Multimeter{
public:
	Multimeter();

	void init();

	void loop(unsigned long dtMs);

    float getVoltage();

private:


};
#endif