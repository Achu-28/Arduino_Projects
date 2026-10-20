int pin=A0;
float V2=0.0;

void setup()
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop()
{
  V2=analogRead(pin);
  
  float AV2= (V2/1023)*5;
  
  
  
  Serial.println(AV2);
  delay(1000);
}