// C++ code
//
int dirpin1=7;
int dirpin2=8;
int speedpin=9;

int ypin=A1;

int motorspeed;

void setup()
{
  pinMode(dirpin1,OUTPUT);
  pinMode(dirpin2,OUTPUT);
  pinMode(speedpin,OUTPUT);
  pinMode(ypin,INPUT);
}

void loop()
{
  int yval=analogRead(ypin);

  if(yval >= 512){
    digitalWrite(dirpin1,HIGH);
    digitalWrite(dirpin2,LOW);
    motorspeed=map(yval,512,1023,0,255);
  }

  if(yval<512){
    digitalWrite(dirpin1,LOW);
    digitalWrite(dirpin2,HIGH);
    motorspeed=map(yval,512,0,0,255);
  }

  analogWrite(speedpin,motorspeed);
}