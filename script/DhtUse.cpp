#include "DhtUse.h"

void DHTMain::setDHT(uint8_t pin, uint8_t type) {
	dht = new DHT(pin, type);
	dht->begin();
}

void DhtController::Update() {
    if ((dht.dht->readTemperature() != iLastTemperature || dht.dht->readHumidity() != iLastHumidity) && !bLastDataChanged) {
        bLastDataChanged = true;
        iLastTemperature = dht.dht->readTemperature();
        iLastHumidity = dht.dht->readHumidity();

        //If temp or humidity is smaller than very low number, its propably not connected to board!
        sTemperature = (round(iLastTemperature) > -99999) ? String(String(round(iLastTemperature)) + "C") : String("E#01");
        sHumidity = (round(iLastHumidity) > -99999) ? String(String(round(iLastHumidity)) + "%") : String("E#01");
	}
}

void AnalogTemperature::Init(int Pin) {
    iPin = Pin;
	Update();
	iTimer = 151;
}

void AnalogTemperature::Update() {
    iTimer++;
	if (iTimer > 150) {
        iTimer = 0;
		float val = round(analogRead(iPin));
		if (iLastData != val) {
            iLastData = val;
			bNewData = true;
		}
	}
}

String AnalogTemperature::sTemperature() {
	float mv = (iLastData / 1024.0) * 5000;
	float cel = mv / 10;
    return (100 > cel)?String(String(round(cel)) + String("C")):String("E#01");
}