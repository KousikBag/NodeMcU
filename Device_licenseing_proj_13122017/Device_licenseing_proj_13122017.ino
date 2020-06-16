 /* TCP/IP communication ESP8266WiFi
 * Copyright (C) 2017 http://www.projetsdiy.fr - https://www.diyprojects.io
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <ESP8266WiFi.h>
const char* ssid     = "Kousik";      // SSID
const char* password = "kousik19cemk";      // Password
//const char* host = "192.168.43.174";  // LOCALIP serveur Herculex
const char* host = "130.211.230.125";  // Phalguni Server
const int   port = 8888;            // Port serveur - Server Port
const int   watchdog = 5000;        // Fréquence du watchdog - Watchdog frequency
unsigned long previousMillis = millis(); 
 
void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server_resp();
}
 
void loop() {
 // unsigned long currentMillis = millis();
 
//  if ( currentMillis - previousMillis > watchdog ) {
//    previousMillis = currentMillis;
//    WiFiClient client;
//  
//    if (!client.connect(host, port)) {
//      Serial.println("connection failed");
//      return;
//    }
// 
//    String url = "/watchdog?command=watchdog&uptime=";
//    url += String(millis());
//    url += "&ip=";
//    url += WiFi.localIP().toString();
    
    // Envoi la requete au serveur - This will send the request to the server
//    client.print("DeviceNAME;Devicetype;vendo_details;9004061579;xyzc23dfqwe1ab23");
//    unsigned long timeout = millis();
//    while (client.available() == 0) {
//      if (millis() - timeout > 5000) {
//        Serial.println(">>> Client Timeout !");
//        client.stop();
//        return;
//      }
//    }
  
    // Read all the lines of the reply from server and print them to Serial

  //}
}
void server_resp(){

  WiFiClient client;
  
    if (!client.connect(host, port)) {
      Serial.println("connection failed");
      return;
    }
   client.print("DeviceNAME;Devicetype;vendo_details;9004061579;xyzc23dfqwe1ab23");
    while(client.available()){
      String line = client.readStringUntil('\n');
      Serial.print(line);
    }
}

