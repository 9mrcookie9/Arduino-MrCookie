#include "Photoresistor.h"

void Photoresistor::Init(int iAnalogPin) {
    iPin = iAnalogPin;
}

void Photoresistor::Update() {
    iValue = analogRead(iPin);
}

float Photoresistor::fLogicValue() {
    return iValue * 0.001;
}

String Photoresistor::sPercentValue() {
    return String(String(round(fLogicValue()*100)) + "%");
}
