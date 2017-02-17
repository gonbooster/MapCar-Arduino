#include "Wifi.h"
WiFiEspServer server(WIFI_PORT);
WiFiEspClient client;
// Serial3 on pins 15 (RX) and 14 (TX)
char ssid[] = "GDP";
char pass[] = "1234567890";

void wifiSetup(){
  Serial3.begin(19200);
  WiFi.init(&Serial3);  
  //WiFi.beginAP(ssid, 10, pass, 3); //Create wifi
  WiFi.begin(ssid, pass); //Connect to wifi
  Serial.println("Access point started");
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  server.begin();
}
void WIFI()
{    
  client = server.available();
      while (client) {//When recive data...
        String trash = client.readStringUntil(':');
        String g = client.readStringUntil(':');
        int th = client.readStringUntil(':').toInt();
        int st = client.readStringUntil(';').toInt();
        //Serial.println(":"+g+":"+th+":"+st+";");
          runG(g);
          runTH(th);
          runST(st);
          client.print(getCoords());
      }
      calm();
}



