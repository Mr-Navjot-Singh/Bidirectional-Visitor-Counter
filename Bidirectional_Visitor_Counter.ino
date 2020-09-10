/*
 * This code counts the number of persons entered in a room.
 * If there is number of persons more than 0 entered the room, the fan will turn on.
 * If persons inside the room are 0, then fan will go OFF.
 * Two IR sensors are required for this project, one detect entry and another one will detect exit.
 */

#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
#define in 8
#define out 9
#define fan 10
int count=0;
void setup()
{
  lcd.begin(16,2);
  lcd.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(fan, OUTPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0,1);
  lcd.print(count);
}
void loop()
{  
  int in_value = digitalRead(in);
  int out_value = digitalRead(out);
  if(in_value == LOW)
  {
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }

  if(out_value == LOW)
  {
    count--;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }


  if(count==0)
  {
    lcd.clear();
    digitalWrite(fan, LOW);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Fan is Off");
    delay(200);
  }

  else
  {
    digitalWrite(fan, HIGH);
  }
}
