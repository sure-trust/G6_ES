/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
*/
#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(0, 1, 2, 3, 4, 5);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'7','8','9','/'},  
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int num1 = 0;
int num2 = 0;
char operation = '+';
int result = 0;
bool inputNum2 = false;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Calculator");
  delay(500);
  lcd.clear();
  lcd.print("Num1:");
}

void loop() {
  char key = keypad.getKey();
  
  if (key != NO_KEY) {
    if (key >= '0' && key <= '9') {
      if (!inputNum2) {
        num1 = num1 * 10 + (key - '0');
        lcd.setCursor(6, 0);
        lcd.print(num1);
      } else {
        num2 = num2 * 10 + (key - '0');
        lcd.setCursor(6, 1);
        lcd.print(num2);
      }
    } else if (key == '+' || key == '-' || key == '*' || key == '/') {
      operation = key;
      inputNum2 = true;
      lcd.setCursor(0, 1);
      lcd.print("Num2:");
    } else if (key == '=') {
      calculateResult();
      lcd.setCursor(0, 1);
      lcd.print("Result: ");
      lcd.print(result);
    } else if (key == 'C') {
      clearCalculator();
    }
  }
}

void calculateResult() {
  switch (operation) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      if (num2 != 0) {
        result = num1 / num2;
      } else {
        lcd.setCursor(0, 1);
        lcd.print("Error: Div by 0");
        delay(2000);
        clearCalculator();
        return;
      }
      break;
  }
  num1 = result;
  num2 = 0;
  inputNum2 = false;
}

void clearCalculator() {
  num1 = 0;
  num2 = 0;
  operation = '+';
  result = 0;
  inputNum2 = false;
  lcd.clear();
  lcd.print("Num1:");
  lcd.setCursor(0, 1);
  lcd.print("       ");
}