// 
// 
// 

#include "LedsUse.h"

void LedUse::Init(int id) {
	iPin = id;
	pinMode(iPin,OUTPUT);
}

void LedUse::changeState(int state) {
	if (iPin == 0) { //CODE: L0C
		String errorCode = String("iPin == 0! ErrorCode: L0C"); 
		if (Serial.available() != 0)
			Serial.print(errorCode);
		return;
	}
	digitalWrite(iPin, state);
}


void TrafficLights::init(int iPinR1, int iPinY1, int iPinG1, int iPinR2, int iPinY2, int iPinG2) {
	iPin[0] = iPinR1;
	iPin[1] = iPinY1;
	iPin[2] = iPinG1;
	iPin[3] = iPinR2;
	iPin[4] = iPinY2;
	iPin[5] = iPinG2;

	for (int i = 0; i < 6; i++) {
		led[i].Init(iPin[i]);
	}
}

void TrafficLights::setColors(int status[6]) {
	for (int i = 0; i < 6; i++) {
		led[i].changeState(status[i]);
	}
}

void TrafficLights::Use(int startY, int startR, int startSecondY, int endSecondY) {
	iTimer++;
	int status[6]{0,0,0,0,0,0}; // |0 R| , |1 Y| , |2 G| , |3 R| , |4 Y| , |5 G| 

	if (iTimer < startY) {
		if (bFirstLights) {
			status[0] = 1;
			status[5] = 1;
		}
		else {
			status[2] = 1;
			status[3] = 1;
		}
	}else  if (iTimer >= startY && iTimer < startR) {
		status[1] = 1;
		status[4] = 1;
	}else if (iTimer >= startR && iTimer < startSecondY) {
		status[0] = 1;
		status[3] = 1;
	}else if (iTimer >= startSecondY && iTimer <= endSecondY) {
		if (bFirstLights) {
			status[2] = 1;
			status[3] = 1;
		}
		else {
			status[0] = 1;
			status[4] = 1;
		}
	} else {
            bFirstLights = !bFirstLights;
			iTimer = 0;
	}
	setColors(status);
}