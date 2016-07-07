// 
// 
// 

#include "LcdUse.h"


void LcdMain::SetLcd(uint8_t id, int width, int height) {
	lcd = new LiquidCrystal_I2C(id, width, height);
	lcd->init();
	lcd->clear();
}

void LcdMain::HelloWorld_Debug(int x, int y) {
	lcd->setCursor(x, y);
	lcd->print("Hello World!");
}

void LcdMain::Print(uint8_t text, int x, int y, bool clearLcd) {
	if (clearLcd)
		lcd->clear();
	lcd->setCursor(x, y);
	lcd->print(text);
}
void LcdMain::PrintS(String text, int x, int y, bool clearLcd) {
	if (clearLcd)
		lcd->clear();
	lcd->setCursor(x, y);
	lcd->print(text);
}
void LcdController::ScreenRefresh(int refreshTime) {
	iTimer++;
	if (iTimer > refreshTime) {
        iTimer = 0;
		lcdClass.lcd->clear();
		bClearScreen = true;
	}
}