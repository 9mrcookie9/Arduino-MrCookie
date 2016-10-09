// OtherAnalogSensorsUse.h

#ifndef _OTHERANALOGSENSORSUSE_h
#define _OTHERANALOGSENSORSUSE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class SoilMoistureSensor {
public:
    void Init(int iAnalogPin);
    void Update();
    String sStatus();
    int iStatus();
    int iValue;
private:
    int iPin;
};

#endif

