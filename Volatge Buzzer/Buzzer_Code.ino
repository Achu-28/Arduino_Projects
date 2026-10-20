//
int potenpin=13;
int buzzpin=12;
int v;

void setup()
{
  pinMode(potenpin, OUTPUT);
  pinMode(buzzpin, OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop()
{
    digitalWrite(potenpin,HIGH);
    int v=analogRead(A0);
    
    Serial.println(v);
  	delay(500);
    
    if(v>=1000){
      digitalWrite(buzzpin,HIGH);
      delay(15);
      digitalWrite(buzzpin,LOW); 
  }
}