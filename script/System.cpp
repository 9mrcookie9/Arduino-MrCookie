#include "System.h"

void SystemMain::Init(void){
	lcdController.lcdClass.SetLcd();
	dhtController.dht.setDHT(3);
}

void SystemMain::Setup(void){
//	lcdController.lcdClass.HelloWorld_Debug(0,1);
}

void SystemMain::Update(void){
	lcdController.ScreenRefresh(200);
	dhtController.checkData();
	buttonFirst.Use(2);

	if(buttonFirst.State)
	    lcdController.lcdClass.PrintS("true ",10);
	else
		lcdController.lcdClass.PrintS("false",10);

	if(dhtController.lastDataChanged == true || lcdController.clearScreen){
		lcdController.lcdClass.PrintS(String("T:"+dhtController.Temperature));
		lcdController.lcdClass.PrintS(String("W:"+dhtController.Humidity),0,1);
		dhtController.lastDataChanged = false;
	}
	
	if(lcdController.clearScreen == true){
		lcdController.clearScreen = false;
	}
}





