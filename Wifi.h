// Wifi.h

#ifndef _WIFI_h
#define _WIFI_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Drive.h"
#include "Gps.h"
#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspServer.h>

#define WIFI_PORT 400 

void wifiSetup();
void WIFI();
#endif
