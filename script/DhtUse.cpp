#include "DhtUse.h"

void DHTMain::setDHT(uint8_t pin, uint8_t type) {
	dht = new DHT(pin, type);
	dht->begin();
}

void DhtController::checkData() {
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

void AnalogTemperature::init(int Pin) {
	pin = Pin;
	checkData();
	timer = 151;
}

void AnalogTemperature::checkData() {
	timer++;
	if (timer > 150) {
		timer = 0;
		float val = round(analogRead(pin));
		if (lastData != val) {
			lastData = val;
			newData = true;
		}
	}
}

String AnalogTemperature::temp() {
	float mv = (lastData / 1024.0) * 5000;
	float cel = mv / 10;
	return String(String(round(cel)) + String("C"));
}