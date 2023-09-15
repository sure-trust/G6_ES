#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int lowTank = A3, quTank = A2, halfTank = A1, fullTank = A0;
int motor = 13;
int i, j, k, l;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Tank Status.........");

  pinMode(fullTank, INPUT);
  pinMode(halfTank, INPUT);
  pinMode(quTank, INPUT);
  pinMode(lowTank, INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  i = digitalRead(fullTank);
  j = digitalRead(halfTank);
  k = digitalRead(quTank);
  l = digitalRead(lowTank);

  if (i == 1 && j == 1 && k == 1 && l == 1) {
    lcd.setCursor(0, 0);
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(' ');
    lcd.setCursor(5, 0);
    lcd.print("FULL.............");
    lcd.setCursor(0, 1);
    lcd.print("MOTOR is OFF                ");
    digitalWrite(motor, LOW);
  } else if (i == 0 && j == 1 && k == 1 && l == 1) {
    lcd.setCursor(0, 0);
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(char('_'));
    lcd.print(' ');
    lcd.setCursor(5, 0);
    lcd.print("HALF...........");
    lcd.setCursor(0, 1);
    lcd.print("MOTOR is OFF                ");
    digitalWrite(motor, LOW);
  } else if (i == 0 && j == 0 && k == 1 && l == 1) {
    lcd.setCursor(0, 0);
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print("_");
    lcd.print("_");
    lcd.print(' ');
    lcd.setCursor(5, 0);
    lcd.print("QUARTER.............");
    lcd.setCursor(0, 1);
    lcd.print("MOTOR is ON                ");
    digitalWrite(motor, HIGH);
  } else if (i == 0 && j == 0 && k == 0 && l == 1) {
    lcd.setCursor(0, 0);
    lcd.print(char(219));
    lcd.print("_");
    lcd.print("_");
    lcd.print("_");
    lcd.print(' ');
    lcd.setCursor(5, 0);
    lcd.print("LOW.............");
    lcd.setCursor(0, 1);
    lcd.print("MOTOR is ON                ");
    digitalWrite(motor, HIGH);
  } else if (i == 0 && j == 0 && k == 0 && l == 0) {
    lcd.setCursor(0, 0);
    lcd.print("_");
    lcd.print("_");
    lcd.print("_");
    lcd.print("_");
    lcd.print(' ');
    lcd.setCursor(5, 0);
    lcd.print("EMPTY.............");
    lcd.setCursor(0, 1);
    lcd.print("MOTOR is ON                ");
    digitalWrite(motor, HIGH);
  } else {
    digitalWrite(motor, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Fail!");
    lcd.setCursor(0, 1);
    lcd.print("NEED CHECK-UP.........");
  }
}
