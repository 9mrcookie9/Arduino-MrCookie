// System.h
#ifndef _System_h_
#define _System_h_

#include <math.h>
#include "DhtUse.h"
#include "LcdUse.h"
#include "ButtonUse.h"
#include "LedsUse.h"
#include "NetworkUse.h"
#include "PhotoresistorUse.h"
#include "OtherAnalogSensorsUse.h"

class SystemMain{
public:
  void Init(void);
  void Setup(void);
  void Update(void);
  int lcdRefreshTimer;
private:
  static byte Mac[];
  DhtController dhtController;
  LcdController lcdController;
  NetworkController networkController;
  TrafficLights trafficLightController;
  AnalogTemperature analogTempController;
  ButtonMain buttonFirst;
  ButtonMain buttonRestetLcd;
  RGBLed rgbLed;
  Photoresistor photoresistor;
  SoilMoistureSensor soilMoistureSensor;
};
#endif

