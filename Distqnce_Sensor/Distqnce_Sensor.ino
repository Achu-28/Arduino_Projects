#include <LiquidCrystal.h>

int rs=7;
int en=8;

int db4=9,db5=10,db6=11,db7=12;
LiquidCrystal lcd(rs,en,db4,db5,db6,db7);

int trigpin = 6;
int echopin = 5;
int buttonpin = 4;

int lastno=1,currno;

int flag = 1;  // for toglling

void setup()
{
  lcd.begin(16,2);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(buttonpin,INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  
  float timetaken = pulseIn(echopin,HIGH);  // from trigpin to echo pin
  float time = timetaken/2;  // from the object to the echopin
  
  float distance = time * 0.000343; // distance from the object
  
  currno = digitalRead(buttonpin);
  
  if(lastno == 1 && currno == 0){
    flag = !flag;
    if(flag == 0){
      
  	  Serial.print("Distance:");
 	  Serial.println(distance);
  
  	  lcd.setCursor(0,0);
      lcd.print("Target Distance:");
  	  lcd.setCursor(0,1);
  	  lcd.print(distance);
    }
    
    else{
      Serial.println("LCD Turned OFF...");
      lcd.clear();
    }
  }
  lastno = currno;  //updating the last no...
}