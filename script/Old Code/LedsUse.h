// LedsUse.h

#ifndef _LEDSUSE_h
#define _LEDSUSE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class RGBLed {
public:
    void Init(int iPinR,int iPinG,int iPingB);
    void SetColor(int iR,int iG,int iB);
    void SetColor(float fR,float fG,float fB);
private:
    int iPinR;
    int iPinG;
    int iPinB;
};

class LedUse{
public:
	void Init(int iPin);
	void changeState(int iState);
private:
	int iPin;
};

class TrafficLights {
public:
	void Init(int iPinR1, int iPinY1, int iPinG1, int iPnR2, int iPinY2, int iPinG2);
	void Use(int iStartY,int iStartR,int iStartSecondY,int iEndSecondY);
	void setColors(int status[6]);
private:
	unsigned long iTimer;
	bool bFirstLights;
	int iPin[6];
	LedUse led[6];
};
#endif

