// DhtUse.h

#ifndef _DHTUSE_h
#define _DHTUSE_h

#include <DHT.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class DHTMain {
public:
	void setDHT(uint8_t pin, uint8_t type = DHT11);
	DHT* dht;
};

class DhtController {
public:
	DHTMain dht;
	bool lastDataChanged;
	void checkData();
	String Humidity;
	String Temperature;
	float lastHumidity;
	float lastTemperature;
};

class AnalogTemperature {
public:
	void init(int pin);
	void checkData();
	String temp();
	bool newData;
private:
	unsigned long timer;
	int pin;
	float lastData;
};

#endif

