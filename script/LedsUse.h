// LedsUse.h

#ifndef _LEDSUSE_h
#define _LEDSUSE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class LedUse{
public:
	void init(int Pin);
	void changeState(int state);
private:
	int pin;
};


class TrafficLights {
public:
	void init(int pinR1, int pinY1, int pinG1, int pinR2, int pinY2, int pinG2);
	void Use(int startY,int startR,int startSecondY,int endSecondY);
	void setColors(int status1, int status2, int status3, int status4, int status5, int status6);
private:
	unsigned long timer;
	bool firstLights;
	int pin[6];
	LedUse led[6];
};


#endif

