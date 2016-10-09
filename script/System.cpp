#include "System.h"

byte SystemMain::Mac[6] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };

void SystemMain::Init(void) {
    Serial.begin(57600);
    Serial.println("INIT: START");
    Serial.println("INIT: END");
}

void SystemMain::Setup(void) {
    Serial.println("SETUP: START");
    Serial.println("SETUP: END");
}

void SystemMain::Update(void) {
  
}


