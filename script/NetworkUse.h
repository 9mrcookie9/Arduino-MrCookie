// NetworkUse.h
#ifndef _NETWORKUSE_h_
#define _NETWORKUSE_h_
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class Network {
public:
    void Init();
};
class NetworkController {
public:
    void Init();
private:
    Network* network;
};
#endif

