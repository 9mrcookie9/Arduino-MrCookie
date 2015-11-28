#include "System.h"

void SystemMain::Init(void){
	Serial.begin(9600);
	lcdController.lcdClass.SetLcd();
	dhtController.dht.setDHT(13);
	analogTempController.init(0);
	trafficLightController.init(2, 3, 4, 5, 6, 7);
}

void SystemMain::Setup(void){
	lcdRefreshTimer = 200;
//	lcdController.lcdClass.HelloWorld_Debug(0,1);
}

void SystemMain::Update(void){
	lcdController.ScreenRefresh(lcdRefreshTimer);
	dhtController.checkData();
	buttonFirst.Use(12);

	analogTempController.checkData();

	trafficLightController.Use(1000,1100,1250,1400);

	if(buttonFirst.State)
	    lcdController.lcdClass.PrintS("true ",10);
	else
		lcdController.lcdClass.PrintS("false",10);

	if (analogTempController.newData || lcdController.clearScreen) {
		lcdController.lcdClass.PrintS(analogTempController.temp(), 10, 1);
	}
	if(dhtController.lastDataChanged || lcdController.clearScreen){
		lcdController.lcdClass.PrintS(String("T:"+dhtController.Temperature));
		lcdController.lcdClass.PrintS(String("W:"+dhtController.Humidity),0,1);
		dhtController.lastDataChanged = false;
	}
	
	if(lcdController.clearScreen == true){
		lcdController.clearScreen = false;
	}
}






