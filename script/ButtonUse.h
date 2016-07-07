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
    void Init(int iPinId,int iTimerLimit = 10);
    bool State();
private:
    bool bState;
	unsigned long iTimer;
    unsigned long iTimerLimit;
	int iActualState;
	int iLastState;
    int iPin;
};

#endif

