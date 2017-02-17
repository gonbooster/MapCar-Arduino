 #include "Wifi.h"
#include "Drive.h"

void setup()
{
  Serial.begin(115200);
  //GPS SETUP
    gpsSetup();
  //WIFI SETUP
  wifiSetup();
  //DRIVE SETUP
  driveSetup();
}

void loop() 
{
  WIFI();
}
