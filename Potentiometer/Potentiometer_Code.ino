int pin=A0;
float V;

void setup()
{
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int v=analogRead(A0);
  
  V=(5.0/1023.0)*v;
  
  Serial.println(V);
  delay(500);
}