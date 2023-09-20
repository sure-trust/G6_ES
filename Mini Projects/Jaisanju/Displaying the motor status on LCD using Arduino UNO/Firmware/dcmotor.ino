#include <LiquidCrystal.h>

// LCD Display setup
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Pin for the push button
const int buttonPin = A5;

// Pin for analog motor control
const int motorPin = 1;

// Variables
int motorState = 0;
int lastButtonState = HIGH;
int buttonState;

void setup() {
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT);
  analogWrite(motorPin, motorState); // Set initial motor state
  updateLCD();
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      motorState = 255 - motorState; // Toggle motor state (0 to 255 and vice versa)
      analogWrite(motorPin, motorState);
      updateLCD();
    }
  }
  lastButtonState = buttonState;
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Motor: ");
  if (motorState == 0) {
    lcd.print("OFF");
  } else {
    lcd.print("ON");
}
}
