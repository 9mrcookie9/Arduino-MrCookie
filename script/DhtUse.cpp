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
