// System.h
#ifndef _System_h_
#define _System_h_

#include <math.h>
#include "DhtUse.h"
#include "LcdUse.h"
#include "ButtonUse.h"
#include "LedsUse.h"
#include "Network.h"

class SystemMain{
public:
  void Init(void);
  void Setup(void);
  void Update(void);
  int lcdRefreshTimer;
private:
  DhtController dhtController;
  LcdController lcdController;
  NetworkController networkController;
  TrafficLights trafficLightController;
  AnalogTemperature analogTempController;
  ButtonMain buttonFirst;
};

#endif

