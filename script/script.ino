#include <math.h>
#include <Wire.h>
#include "System.h"
#include "DhtUse.h"
#include "LcdUse.h"
#include "ButtonUse.h"
#include "LedsUse.h"
#include "NetworkUse.h"
#include "PhotoresistorUse.h"

SystemMain main;

void setup(){
    main.Init();
    main.Setup();
}

void loop(){
	_delay_ms(1);
    main.Update();
}