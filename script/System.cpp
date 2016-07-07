#include "System.h"

void SystemMain::Init(void){
	Serial.begin(9600);
	lcdController.lcdClass.SetLcd();
	dhtController.dht.setDHT(13);
	analogTempController.Init(0);
	trafficLightController.Init(2, 3, 4, 5, 6, 7);
    buttonFirst.Init(12);
    networkController.Init();
}

void SystemMain::Setup(void){
	lcdRefreshTimer = 200;
//	lcdController.lcdClass.HelloWorld_Debug(0,1);
}

void SystemMain::Update(void){
	lcdController.ScreenRefresh(lcdRefreshTimer);
	analogTempController.Update();
	dhtController.Update();
	trafficLightController.Use(1000,1100,1250,1400);

	if(buttonFirst.State())
	    lcdController.lcdClass.PrintS("true ",10);
	else
		lcdController.lcdClass.PrintS("false",10);

	if (analogTempController.bNewData || lcdController.bClearScreen) {
		lcdController.lcdClass.PrintS(String("T:"+analogTempController.sTemperature()), 10, 1);
	}
	if(dhtController.lastDataChanged || lcdController.bClearScreen){
		lcdController.lcdClass.PrintS(String("T:"+dhtController.Temperature));
		lcdController.lcdClass.PrintS(String("W:"+dhtController.Humidity),0,1);
		dhtController.lastDataChanged = false;
	}
    lcdController.bClearScreen = false;
}


