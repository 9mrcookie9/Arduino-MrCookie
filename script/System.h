// System.h
#ifndef _System_h_
#define _System_h_

#include <math.h>
#include "DhtUse.h"
#include "LcdUse.h"
#include "ButtonUse.h"
#include "LedsUse.h"

class SystemMain{
public:
  void Init(void);
  void Setup(void);
  void Update(void);
  int lcdRefreshTimer;
  String tempManual(int pin);
private:
  DhtController dhtController;
  ButtonMain buttonFirst;
  LcdController lcdController;
  TrafficLights trafficLightController;
};

#endif

