#include <math.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "System.h"
#include "DhtUse.h"
#include "LcdUse.h"
#include "ButtonUse.h"

SystemMain mainClass;

void setup(){
  mainClass.Init();
  mainClass.Setup();
}

void loop(){
  mainClass.Update();
}

