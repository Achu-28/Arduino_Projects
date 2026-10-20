int ledpin=12;
int buttonpin=7;
int buttonread;

int lastno=1,currentno;

int ledstate=0;

void setup()
{
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin,INPUT);
}

void loop()
{
  buttonread=digitalRead(buttonpin);
  
  currentno=buttonread;
  
  if(lastno==1 && currentno ==0){
    delay(2);
    
    if(digitalRead(buttonpin)==0){
      ledstate=!ledstate;
      digitalWrite(ledpin,ledstate);
    }
  }
  lastno=currentno;
}
