// Gps.h

#ifndef _GPS_h
#define _GPS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <TinyGPS.h>
void smartdelay(unsigned long ms);
void gpsSetup();
String getCoords();
#endif
