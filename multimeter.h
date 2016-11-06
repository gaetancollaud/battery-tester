#ifndef _MULTIMETER_H
#define _MULTIMETER_H

#include "constants.h"

#define READING_PER_LOOP 10
#define READINGS 100
#define READINGS_REVERSE 0.01

class Multimeter{
public:
	Multimeter();

	void init();

	void loop(unsigned long nowMs, unsigned long dtMs);

    float getBatteryVoltage();
    float getRefVoltage();
    float getCurrentMa();
    float getCapacity();

private:
    unsigned long timeAcc = 0;
    int readingCount = 0;
    float batterySum;
    float refSum;

    float batteryVoltage=10;
    float refVoltage;
    float currentMa;
    float capacity;

    void read(unsigned long nowMs);


};
#endif