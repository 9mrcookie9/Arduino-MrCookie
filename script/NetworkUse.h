// NetworkUse.h
#ifndef _NETWORKUSE_h_
#define _NETWORKUSE_h_

#include <arduino_uip-master/UIPEthernet.h>
#include <arduino_uip-master/UIPServer.h>
#include <arduino_uip-master/UIPClient.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class Network {
public:
    void Init(uint8_t mac[],char* dns = "www.google.com", int pin = 8);
    void Init(byte ip[],byte gw[],byte dns[]);
};
class NetworkController {
public:
    Network network;
};
#endif

