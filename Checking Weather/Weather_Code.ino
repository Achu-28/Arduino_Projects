#include <Servo.h>

Servo myServo;

int photopin=A0;
int servopin=11;

int photoread;
int angle;

void setup()
{
  pinMode(photopin, INPUT);
  pinMode(servopin,INPUT);
  myServo.attach(servopin);
  
  Serial.begin(9600);
}

void loop()
{
  photoread=analogRead(A0);
  angle=map(photoread,0,1023,0,180);
  
  Serial.println(photoread);
  
  myServo.write(angle);
  delay(500);
  
  
}