#include "System.h"

void SystemMain::Init(void) {
    Serial.begin(9600);
    lcdController.lcdClass.SetLcd();
    dhtController.dht.setDHT(2);
    analogTempController.Init(0);
    buttonFirst.Init(3);
    buttonRestetLcd.Init(8,5);
    rgbLed.Init(5, 6, 7);
    photoresistor.Init(3);
}

void SystemMain::Setup(void) {
    lcdRefreshTimer = 200;
    //	lcdController.lcdClass.HelloWorld_Debug(0,1);
}

void SystemMain::Update(void) {
    lcdController.ScreenRefresh(lcdRefreshTimer);
    analogTempController.Update();
    dhtController.Update();
    photoresistor.Update();
    if (buttonRestetLcd.State())
        lcdController.lcdClass.PrintS("",0,0,true);
    if(buttonFirst.State())
        lcdController.lcdClass.PrintS("B:1",11);
    else
        lcdController.lcdClass.PrintS("B:0",11);        
    lcdController.lcdClass.PrintS(String("L:"+photoresistor.sPercentValue()+" "), 11 ,1);
    if (buttonRestetLcd.State() || dhtController.bLastDataChanged || lcdController.bClearScreen || analogTempController.bNewData) {
        lcdController.lcdClass.PrintS(String("T:" + dhtController.sTemperature + "," + analogTempController.sTemperature()));
        lcdController.lcdClass.PrintS(String("W:" + dhtController.sHumidity), 0, 1);
        rgbLed.SetColor(
            float((photoresistor.fLogicValue() >= 0.5) ? (255 * (photoresistor.fLogicValue())) : 0),
            float(0),
            float((photoresistor.fLogicValue() <= 0.5) ? (255 * (1 - photoresistor.fLogicValue())) : 0));
        dhtController.bLastDataChanged = false;
        buttonRestetLcd.SetState(false);
    }
    lcdController.bClearScreen = false;
}


