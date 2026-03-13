#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pirPin = 2;
int bulbPin = 8;
int alarmPin = 9;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(bulbPin, OUTPUT);
  pinMode(alarmPin,OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Motion System");
  lcd.setCursor(0, 1);
  lcd.print("Ready");

  delay(2000);
  lcd.clear();
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    digitalWrite(bulbPin, HIGH);  // Bulb ON
    digitalWrite(alarmPin,HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Motion Detected");
    lcd.setCursor(0, 1);
    lcd.print("Bulb ON        ");
  } else {
    digitalWrite(bulbPin, LOW);   // Bulb OFF
    digitalWrite(alarmPin,LOW);
    lcd.setCursor(0, 0);
    lcd.print("No Motion      ");
    lcd.setCursor(0, 1);
    lcd.print("Bulb OFF       ");
  }

  delay(300);
}