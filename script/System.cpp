#include "System.h"

void SystemMain::Init(void){
	lcdController.lcdClass.SetLcd();
	dhtController.dht.setDHT(13);
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

	trafficLightController.Use(1000,1100,1250,1400);

	if(buttonFirst.State)
	    lcdController.lcdClass.PrintS("true ",10);
	else
		lcdController.lcdClass.PrintS("false",10);

	lcdController.lcdClass.PrintS(tempManual(0),10,1);
	if(dhtController.lastDataChanged == true || lcdController.clearScreen){
		lcdController.lcdClass.PrintS(String("T:"+dhtController.Temperature));
		lcdController.lcdClass.PrintS(String("W:"+dhtController.Humidity),0,1);
		dhtController.lastDataChanged = false;
	}
	
	if(lcdController.clearScreen == true){
		lcdController.clearScreen = false;
	}
}

String SystemMain::tempManual(int pin) {
	float val = analogRead(pin);
	float mv = (val / 1024.0) * 5000;
	float cel = mv / 10;
	return String(String(cel)+String("C"));
}





