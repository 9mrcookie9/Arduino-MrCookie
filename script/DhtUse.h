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
    void Update();
    String Humidity;
    String Temperature;
    float lastHumidity;
    float lastTemperature;
};

class AnalogTemperature {
public:
    void Init(int pin);
    void Update();
    String sTemperature();
    bool bNewData;
private:
    unsigned long iTimer;
    int iPin;
    float iLastData;
};

#endif

