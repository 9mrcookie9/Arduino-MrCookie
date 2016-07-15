#include <math.h>
#include <Wire.h>
#include "System.h"

SystemMain logic;

void setup() {
    logic.Init();
    logic.Setup();
}

void loop() {
    _delay_ms(1);
    logic.Update();
}