#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);


#define MQPin A0
#define red 9
#define green 10
#define buzzer 11

void setup() {
  lcd.begin(16,2);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buzzer,OUTPUT);
  lcd.setCursor(0,1);
  lcd.print("DETECTOR-EIF");
  delay(1000);
  lcd.clear();
}
void loop(){

 int gas_value=digitalRead(MQPin);

 if(gas_value==HIGH)
 {
 digitalWrite(green,LOW);
 digitalWrite(buzzer,HIGH);
 ledon();
 lcdon();

 }
 else
 {
  lcdoff();
  
 }

 }

 void ledon()
 {
  digitalWrite(red,HIGH);
   delay(200);
   digitalWrite(red,LOW);
   delay(200);
 }

 void lcdon()
 {
  lcd.setCursor(0,0);
  lcd.print("GAS DETECTED");
  lcd.setCursor(0,1);
  lcd.print("ALERT ALERT!!");
  delay(200);
  lcd.clear();
 } 

void lcdoff()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" NO GAS ");
  lcd.setCursor(0,1);
  lcd.print("DEFECTED ");
  delay(200);
}


    
