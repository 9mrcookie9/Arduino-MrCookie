#include "Arduino.h"
#include <math.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class LcdMain{
public:
  LiquidCrystal_I2C* lcd;
  void SetLcd(uint8_t port = 0x20,int width = 16,int height = 2);
  void PrintS(String t,int x = 0,int y = 0,bool lcdClear = false);
  void Print(uint8_t t,int x = 0,int y = 0,bool lcdClear = false);
  
  void HelloWorld_Debug(int x = 0,int y = 0);
};

class DHTMain{
public:
  void setDHT(uint8_t pin, uint8_t type = DHT11);
  DHT* dht;
};


class LcdController{
public:
  void ScreenRefresh(int timer);
  LcdMain lcdClass;
  bool clearScreen;
private:
  unsigned long timer;
};

class ButtonMain{
public:
  void Use(int buttonPinId,LcdController lcdController);
  bool State;
private:
  unsigned long timer;
  int buttonState;
  int lastState;
};

class DhtController{
public:
  DHTMain dht;
  bool lastDataChanged;
  void checkData();
  String Humidity;
  String Temperature;
  float lastHumidity;
  float lastTemperature;
};

class SystemMain{
public:
  void Init(void);
  void Setup(void);
  void Update(void);
private:
  DhtController dhtController;
  ButtonMain buttonFirst;
  LcdController lcdController;
};



