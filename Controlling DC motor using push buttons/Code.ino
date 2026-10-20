
int dirpin1=7;
int dirpin2=8;
int speedpin=9;

int lpush=12;
int rpush=13;

int motorspeed=0;

void setup()
{
  pinMode(dirpin1,OUTPUT);
  pinMode(dirpin2,OUTPUT);
  pinMode(speedpin,OUTPUT);
  
  pinMode(lpush,INPUT_PULLUP);
  pinMode(rpush,INPUT_PULLUP);
  
}

void loop()
{
  digitalWrite(dirpin1,HIGH);
  digitalWrite(dirpin2,LOW);
    
  int lpush_val=digitalRead(lpush);
  int rpush_val=digitalRead(rpush);
  
  if(motorspeed > 255){
    motorspeed=255;
  }
  
  if(motorspeed < 0){
    motorspeed=0;
  }

  if(lpush_val == 0){
    motorspeed-=5;
    
  }
  
  if(rpush_val == 0){
	motorspeed+=5;
      }
  
  
  analogWrite(speedpin,motorspeed);

  delay(250);
}