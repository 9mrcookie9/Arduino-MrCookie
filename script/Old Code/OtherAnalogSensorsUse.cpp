#include "OtherAnalogSensorsUse.h"

void SoilMoistureSensor::Init(int pin) {
    iPin = pin;
}

void SoilMoistureSensor::Update() {
     iValue = analogRead(iPin);
}

String SoilMoistureSensor::sStatus() {
    if (iValue > 600)
        return "Sucho.";
    else if (iValue > 150)
        return "Wilgo.";
    else
        return "Mokro.";
}

int SoilMoistureSensor::iStatus() {
    if (iValue > 600)
        return 0;
    else if (iValue > 150)
        return 1;
    else
        return 2;
}
