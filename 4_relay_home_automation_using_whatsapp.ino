#include <ESP8266WiFi.h>
#include <ThingESP.h>

ThingESP8266 thing("sharvin03062013", "controlLEDesp32", "sharvin");

// Pin definitions - using active-low logic (0 = ON, 1 = OFF)
const int LIGHT1 = D1;
const int LIGHT2 = D2;
const int LIGHT3 = D3;
const int LIGHT4 = D4;

void setup()
{
  Serial.begin(115200);
  pinMode(LIGHT1, OUTPUT);
  pinMode(LIGHT2, OUTPUT);
  pinMode(LIGHT3, OUTPUT);
  pinMode(LIGHT4, OUTPUT);
  
  // Initialize all lights to OFF
  digitalWrite(LIGHT1, 1);
  digitalWrite(LIGHT2, 1);
  digitalWrite(LIGHT3, 1);
  digitalWrite(LIGHT4, 1);
  
  thing.SetWiFi("YOUR WIFI SSID", "YOUR WIFI PASSWORD");
  thing.initDevice();
}

String HandleResponse(String query)
{
  // Convert query to lowercase for case-insensitive comparison
  query.toLowerCase();
  
  if (query == "light1 on") {
    digitalWrite(LIGHT1, 0);
    return "Done: Light1 Turned ON";
  }
  else if (query == "light1 off") {
    digitalWrite(LIGHT1, 1);
    return "Done: Light1 Turned OFF";
  }
  else if (query == "light2 on") {
    digitalWrite(LIGHT2, 0);
    return "Done: Light2 Turned ON";
  }
  else if (query == "light2 off") {
    digitalWrite(LIGHT2, 1);
    return "Done: Light2 Turned OFF";
  }
  else if (query == "light3 on") {
    digitalWrite(LIGHT3, 0);
    return "Done: Light3 Turned ON";
  }
  else if (query == "light3 off") {
    digitalWrite(LIGHT3, 1);
    return "Done: Light3 Turned OFF";
  }
  else if (query == "light4 on") {
    digitalWrite(LIGHT4, 0);
    return "Done: Light4 Turned ON";
  }
  else if (query == "light4 off") {
    digitalWrite(LIGHT4, 1);
    return "Done: Light4 Turned OFF";
  }
  else if (query == "light1 status") {
    return digitalRead(LIGHT1) ? "Light1 is OFF" : "Light1 is ON";
  }
  else if (query == "light2 status") {
    return digitalRead(LIGHT2) ? "Light2 is OFF" : "Light2 is ON";
  }
  else if (query == "light3 status") {
    return digitalRead(LIGHT3) ? "Light3 is OFF" : "Light3 is ON";
  }
  else if (query == "light4 status") {
    return digitalRead(LIGHT4) ? "Light4 is OFF" : "Light4 is ON";
  }
  else if (query == "all status") {
    String status = "Light Status:\n";
    status += "Light1: " + String(digitalRead(LIGHT1) ? "OFF" : "ON") + "\n";
    status += "Light2: " + String(digitalRead(LIGHT2) ? "OFF" : "ON") + "\n";
    status += "Light3: " + String(digitalRead(LIGHT3) ? "OFF" : "ON") + "\n";
    status += "Light4: " + String(digitalRead(LIGHT4) ? "OFF" : "ON");
    return status;
  }
  else {
    return "Invalid command. Valid commands are: light1/2/3/4 on/off/status, all status";
  }
}

void loop()
{
  thing.Handle();
}