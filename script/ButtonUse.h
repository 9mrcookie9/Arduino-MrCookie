// ButtonUse.h

#ifndef _BUTTONUSE_h
#define _BUTTONUSE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ButtonMain {
public:
	void Use(int buttonPinId);
	bool State;
private:
	unsigned long timer;
	int buttonState;
	int lastState;
};

#endif

