int led1=11;
int led2=10;
int led3=9;
int led4=8;

int number;
int temp;

void setup()
{
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  Serial.println("enter the num");
}

void loop()
{
  while(Serial.available() == 0){
    
  }
  
  number=Serial.parseInt();
  temp=number;
  
  while(Serial.available()>0){
    Serial.read();}
  digitalWrite(led1,temp%2);
  temp=temp/2;
  
  digitalWrite(led2,temp%2);
  temp=temp/2;
  
  digitalWrite(led3,temp%2);
  temp=temp/2;
  
  digitalWrite(led4,temp%2);
  temp=temp/2;
  
  temp=number;
  delay(500);
  
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
  digitalWrite(led4,0);
  
  delay(500);
}