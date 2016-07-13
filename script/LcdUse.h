// LcdUse.h

#ifndef _LCDUSE_h
#define _LCDUSE_h

#include "Libs\LiquidCrystal_I2C\LiquidCrystal_I2C.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class LcdMain {
public:
    LiquidCrystal_I2C* lcd;
    void SetLcd(uint8_t port = 0x20, int width = 16, int height = 2);
    void PrintS(String t, int x = 0, int y = 0, bool lcdClear = false);
    void Print(uint8_t t, int x = 0, int y = 0, bool lcdClear = false);
    void HelloWorld_Debug(int x = 0, int y = 0);
};

class LcdController {
public:
    void ScreenRefresh(int iTimer);
    LcdMain lcdClass;
    bool bClearScreen;
private:
    unsigned long iTimer;
};
#endif

