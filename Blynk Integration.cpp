#include <Arduino.h>
#include <WiFi.h>
/*
#define BLYNK_TEMPLATE_ID "TM4ycO_"
#define BLYNK_TEMPLATE_NAME "In4hon"
#define BLYNK_AUTH_TOKEN "YOUR_TOKEN"*/

#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp32.h>



char ssid[] = "Ad2";
char pass[] = "Fdi";

int ledPin = 2;

BLYNK_WRITE(V0) {
  int value = param.asInt();

  if (value == 1) {
    digitalWrite(ledPin, HIGH);
    Serial.println("ON ✅");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("OFF ❌");
  }
}

BLYNK_CONNECTED() {
  Serial.println("✅ Blynk Connected!");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("\n✅ WiFi Connected");

  Blynk.config(BLYNK_AUTH_TOKEN);
  Blynk.connect();
}

void loop() {
  Blynk.run();
}
