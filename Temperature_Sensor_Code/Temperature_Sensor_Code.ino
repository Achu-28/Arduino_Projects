#include <LiquidCrystal.h>

int rs=7;
int en=8;

int db4=9,db5=10,db6=11,db7=12;

float temp;
int temppin=A0;

LiquidCrystal lcd(rs,en,db4,db5,db6,db7);

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  
}

void loop()
{
  int v = analogRead(temppin);
  float V = (5.0/1023)*v;
  
  temp = (V-0.5)*100;
  
  lcd.setCursor(0,0);
  lcd.print("temperature: ");
  lcd.print(temp);
  
}