#include <LiquidCrystal.h>

 const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);// LCD pins: RS, E, D4, D5, D6, D7
int rainSensorPin = A5;
int motorPin = 1;
int motorStatus = LOW;

void setup() {
  lcd.begin(16, 2); // Initialize the LCD
  pinMode(rainSensorPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  int rainStatus = digitalRead(rainSensorPin);

  if (rainStatus == HIGH) {
    motorStatus = HIGH;
    digitalWrite(motorPin, motorStatus);
    lcd.clear();
    lcd.print("Motor=ON");
    lcd.setCursor(0,1);
    lcd.print("Raining");
    

  } else {
    motorStatus = LOW;
    digitalWrite(motorPin, motorStatus);
    lcd.clear();
    lcd.print("Motor=OFF");
    lcd.setCursor(0,1);
    lcd.print("Not raining");
    
  }
  
  delay(1000); // Delay for stability
}