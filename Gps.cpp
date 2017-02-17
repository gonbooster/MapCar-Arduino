#include "Gps.h"

TinyGPS gps;
//Serial2 on pins 17 (RX) and 16 (TX)

void smartdelay(unsigned long ms)
{
 unsigned long start = millis();
  do 
  {
    while (Serial2.available())
      gps.encode(Serial2.read());
  } while (millis() - start < ms);
}


void gpsSetup()
{           
 Serial2.begin(9600); 
}
String getCoords()
{
  float flat, flon=0;
  unsigned long age = 0;
  gps.f_get_position(&flat, &flon, &age);
  smartdelay(50);
  return ":"+String(flat,4)+":"+String(flon,4)+":";
}

