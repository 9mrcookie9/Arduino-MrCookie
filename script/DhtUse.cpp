#include "DhtUse.h"

void DHTMain::setDHT(uint8_t pin, uint8_t type) {
	dht = new DHT(pin, type);
	dht->begin();
}

void DhtController::Update() {
	if ((dht.dht->readTemperature() != lastTemperature || dht.dht->readHumidity() != lastHumidity) && !lastDataChanged) {
		lastDataChanged = true;
		lastHumidity = dht.dht->readHumidity();
		lastTemperature = dht.dht->readTemperature();

		Temperature = String(round(dht.dht->readTemperature()));
		Temperature = String(Temperature + "C");
		Humidity = String(round(dht.dht->readHumidity()));
		Humidity = String(Humidity + "%");
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
	return String(String(round(cel)) + String("C"));
}