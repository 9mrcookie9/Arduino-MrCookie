// System.h
#ifndef _System_h_
#define _System_h_

#include <math.h>
#include "DhtUse.h"
#include "LcdUse.h"
#include "ButtonUse.h"

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

#endif

