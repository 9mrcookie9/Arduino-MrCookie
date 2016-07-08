// PhotoresistorUse.h
#ifndef _PHOTORESISTORUSE_h_
#define _PHOTORESISTORUSE_h_
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class Photoresistor{
public:
    void Init(int iAnalogPin);
    void Update();
    String sPercentValue();
    int iValue;
    ///From 0 to 1
    float fLogicValue();
private:
    int iPin;
};
#endif