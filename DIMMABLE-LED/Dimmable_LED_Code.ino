int pin=A0;
int v;
float V;

void setup()
{
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  v=analogRead(A0);
  V=(5.0/1023.0)*v;
  
  Serial.println(V);
  delay(500);
  
}
