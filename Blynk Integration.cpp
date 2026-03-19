#include <Arduino.h>
#include <WiFi.h>
/*
#define BLYNK_TEMPLATE_ID "TMP88ycO_"
#define BLYNK_TEMPLATE_NAME "Inn8888hon"
#define BLYNK_AUTH_TOKEN "YO888EN"*/

#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp32.h>



char ssid[] = "Airtel_Mach2";
char pass[] = "FN217000_i";

int ledPin = 2;
//int pirPin = 27;
//int pirLedPin = 4;   // second LED

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
  // pinMode(pirPin, INPUT);
  //pinMode(pirLedPin, OUTPUT);

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
  /*
   int motion = digitalRead(pirPin);

  // Send motion status to Blynk (V2)
  Blynk.virtualWrite(V2, motion);

  if (motion == HIGH) {
    Serial.println("🚶 Motion Detected!");
    digitalWrite(pirLedPin, HIGH);
  } else {
    Serial.println("No Motion");
    digitalWrite(pirLedPin, LOW);
  }

  delay(500);*/
}
