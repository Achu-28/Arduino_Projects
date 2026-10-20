#include <LiquidCrystal.h>

int rs=7;
int en=8;

int db4=9,db5=10,db6=11,db7=12;

float a,b,d;

int flag_a=1,flag_b=1;

LiquidCrystal lcd(rs,en,db4,db5,db6,db7);

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  
}

void loop()
{
  if(flag_a==1){       // to display the msg only once
    lcd.setCursor(0,0);
  	lcd.print("Enter 1st no:");
    
    flag_a++;
  }
  
  while(Serial.available() == 0){  // waiting untill i input the value
    
  }
  
  while(Serial.available()>0){   // checking the serial monitor for the value
    a = Serial.parseFloat();
    
    lcd.setCursor(0,1);
    lcd.print("                 ");
    lcd.setCursor(0,1);
    lcd.print(a);
    
  }
  
  delay(1000);
  lcd.clear();	  // clearing
  
  if(flag_b==1){
    lcd.setCursor(0,0);
  	lcd.print("Enter 2nd no:");
    
    flag_b++;
  }
  
  while(Serial.available() == 0){
    
  }
  
  while(Serial.available()>0){
    b = Serial.parseFloat();
    
    lcd.setCursor(0,1);
    lcd.print("                 ");
    lcd.setCursor(0,1);
    lcd.print(b);
    
  }
  
  delay(1000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Enter Operation");
  
  while(Serial.available() == 0){
    
  }
  
  while(Serial.available()>0){
    
    char c = Serial.read();
    lcd.setCursor(0,1);
    lcd.print(c);
    delay(1000);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("The Result");
      
    switch(c){
      
      case '+':
        d = a+b;
      	lcd.setCursor(0,1);
        lcd.print(d);
        delay(3000);
        break;
      
      case '-':
        d = a-b;
      	lcd.setCursor(0,1);
        lcd.print(d);
        delay(3000);
        break;
      
      case '*':
        d = a*b;
      	lcd.setCursor(0,1);
        lcd.print(d);
        delay(3000);
        break;
      
      case '/':
        d = a/b;
      	lcd.setCursor(0,1);
        lcd.print(d);
        delay(3000);
        break;
      
      default:
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Invalid Input");
        delay(3000);
        break;  
    }
  }
  flag_a=1;
  flag_b=1;
  lcd.clear();
}