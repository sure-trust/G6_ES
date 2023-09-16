#include <LiquidCrystal.h>
#include <Servo.h>

Servo myservo1;

int ir_s1=2;
int ir_s2=4;

int Total=5;
int space;

int flag1=0;
int flag2=0;
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

void setup() {
  pinMode(ir_s1,INPUT);
  pinMode(ir_s2,INPUT);

  myservo1.attach(3);
  myservo1.write(100);

  lcd.begin(16,2);
  lcd.setCursor (0,0);
  lcd.print(" car parking ");
  lcd.setCursor (0,1);
  lcd.print(" system ");
  delay (2000);
  lcd.clear();

  space=Total;
}

void loop(){

  if(digitalRead (ir_s1)==0 && flag1==0){
    if(space>0){flag1=1;
    if(flag2==0){myservo1.write(0);space=space-1;}
    }else{
      lcd.setCursor (0,0);
      lcd.print(" sorry not space");
      lcd.setCursor (0,1);
      lcd.print(" available ");
      delay(1000);
      lcd.clear();
    }
  }

  if(digitalRead(ir_s2)==0 && flag2==0){flag2=1;
  if(flag1==0){myservo1.write(0);space=space+1;}
  }

  if(flag1==1 && flag2==1){
    delay(1000);
    myservo1.write(100);
    flag1=0,flag2=0;
  }

lcd.setCursor(0,0);
lcd.print(" Total space: ");
lcd.print(Total);

lcd.setCursor(0,1);
lcd.print("Have space: ");

lcd.setCursor(0,1);
lcd.print(" Have space: ");
lcd.print(space);
}