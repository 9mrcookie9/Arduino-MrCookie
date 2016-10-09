#include "System.h"

byte SystemMain::Mac[6] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };

void SystemMain::Init(void) {
    Serial.begin(57600);
    Serial.println("INIT: START");
    buttonFirst.Init(3);
    buttonRestetLcd.Init(10, 5);
    //rgbLed.Init(5, 6, 7);
    dhtController.dht.setDHT(2);
    lcdController.lcdClass.SetLcd();
    analogTempController.Init(A0);
    photoresistor.Init(A1);
    soilMoistureSensor.Init(A2);
    Serial.println("INIT: END");
    //ETHERNET
}

void SystemMain::Setup(void) {
    Serial.println("SETUP: START");
    lcdRefreshTimer = 200;
    //lcdController.lcdClass.HelloWorld_Debug(0,1);
    Serial.println("SETUP: END");
}

void SystemMain::Update(void) {
    lcdController.ScreenRefresh(lcdRefreshTimer);
    analogTempController.Update();
    dhtController.Update();
    photoresistor.Update();
    soilMoistureSensor.Update();
    if (buttonRestetLcd.State())
        lcdController.lcdClass.PrintS("", 0, 0, true);
    if (buttonFirst.State())
        lcdController.lcdClass.PrintS("B:1", 7,1);
    else
        lcdController.lcdClass.PrintS("B:0", 7,1);
    lcdController.lcdClass.PrintS(String("L:" + photoresistor.sPercentValue() + " "), 11, 1);
    if (buttonRestetLcd.State() || dhtController.bLastDataChanged || lcdController.bClearScreen || analogTempController.bNewData) {
        lcdController.lcdClass.PrintS(String("T:" + dhtController.sTemperature + "," + analogTempController.sTemperature() + "  " + "W:" + dhtController.sHumidity));
        lcdController.lcdClass.PrintS(soilMoistureSensor.sStatus(), 0, 1);
        /*  rgbLed.SetColor(
              float((photoresistor.fLogicValue() >= 0.5) ? (255 * (photoresistor.fLogicValue())) : 0),
              float(0),
              float((photoresistor.fLogicValue() <= 0.5) ? (255 * (1 - photoresistor.fLogicValue())) : 0));
          */dhtController.bLastDataChanged = false;
        buttonRestetLcd.SetState(false);
    }
    lcdController.bClearScreen = false;
}


