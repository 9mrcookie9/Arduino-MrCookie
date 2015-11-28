// 
// 
// 

#include "LedsUse.h"

void LedUse::init(int id) {
	pin = id;
	pinMode(pin,OUTPUT);
}

void LedUse::changeState(int state) {
	if (pin == 0) { //CODE: L0C
		String errorCode = String("Pin == 0! ErrorCode: L0C"); 
		if (Serial.available() != 0)
			Serial.print(errorCode);
		return;
	}
	digitalWrite(pin, state);
}


void TrafficLights::init(int pinR1, int pinY1, int pinG1, int pinR2, int pinY2, int pinG2) {
	pin[0] = pinR1;
	pin[1] = pinY1;
	pin[2] = pinG1;
	pin[3] = pinR2;
	pin[4] = pinY2;
	pin[5] = pinG2;

	for (int i = 0; i < 6; i++) {
		led[i].init(pin[i]);
	}
}

void TrafficLights::setColors(int status1, int status2, int status3, int status4, int status5, int status6) {
	led[0].changeState(status1);
	led[1].changeState(status2);
	led[2].changeState(status3);
	led[3].changeState(status4);
	led[4].changeState(status5);
	led[5].changeState(status6);
}

void TrafficLights::Use(int startY, int startR, int startSecondY, int endSecondY) {
	timer++;
	int status[6]{0,0,0,0,0,0}; // |0 R| , |1 Y| , |2 G| , |3 R| , |4 Y| , |5 G| 

	if (timer < startY) {
		if (firstLights) {
			status[0] = 1;
			status[5] = 1;
		}
		else {
			status[2] = 1;
			status[3] = 1;
		}
	}else  if (timer >= startY && timer < startR) {
		status[1] = 1;
		status[4] = 1;
	}else if (timer >= startR && timer < startSecondY) {
		status[0] = 1;
		status[3] = 1;
	}else if (timer >= startSecondY && timer <= endSecondY) {
		status[1] = 1;
		status[4] = 1;
	} else {
			firstLights = !firstLights;
			timer = 0;
	}
	setColors(status[0], status[1], status[2], status[3], status[4], status[5]);
}