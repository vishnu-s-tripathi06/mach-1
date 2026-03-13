
#include <Arduino.h>
#include <WiFi.h>

#define WIFI_SSID "Vishnu"
#define WIFI_PASSWORD "om123456"

bool isConnected = false;

void setup() {
  Serial.begin(921600);
  Serial.print("\n\n");
  Serial.println("Starting vishnu ji's device...");
  Serial.print("\n");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED && !isConnected) {
    Serial.println("Connected");
    Serial.println(WiFi.localIP());
    isConnected = true;
  }

  else if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Not connected");
    isConnected = false;
    delay(1000);
  }
}




