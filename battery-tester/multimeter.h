#ifndef _MULTIMETER_H
#define _MULTIMETER_H

#include "constants.h"

#define READING_PER_LOOP 10
#define READINGS 100
#define READINGS_REVERSE 0.01

#define CAPACITY_DELAY 1000
//CAPACITY_HOUR = CAPACITY_DELAY/3600000
#define CAPACITY_BYHOUR 0.00027777777

class Multimeter{
public:
	Multimeter();

	void init();

	void loop(unsigned long nowMs, unsigned long dtMs);

    float getBatteryVoltage();
    float getRefVoltage();
    float getCurrentMa();
    float getCapacity();

    void setRunning(bool running);

private:
    unsigned long lastAccCapacity;
    bool running;
    int readingCount;
    float batterySum;
    float refSum;

    float batteryVoltage;
    float refVoltage;
    float currentMa;
    float capacity;

    void read();
    void computeCapacity(unsigned long nowMs);


};
#endif
