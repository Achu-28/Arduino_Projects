// C++ code

#include <IRremote.hpp>
//
int speedpin = 6;  //enable pin
int dir1pin = 5;   //input pin
int dir2pin = 4;   //input pin
 
int receiverpin = 2;  //receiverpin

int motorspeed = 0;

void setup()
{
  pinMode(speedpin, OUTPUT);
  pinMode(dir1pin,OUTPUT);
  pinMode(dir2pin,OUTPUT);
  
  IrReceiver.begin(receiverpin,ENABLE_LED_FEEDBACK);
  
  Serial.begin(9600);
}

void loop()
{
  if(IrReceiver.decode()){
    int data = IrReceiver.decodedIRData.command;
    
    Serial.println(data);
    
    switch(data){ 
      
      if(motorspeed > 255){
        motorspeed = 255;
      }
      
      if(motorspeed < -255){
        motorspeed = -255;
      }
      
      case 0:  // power button for turing on the full speed in one direction
        digitalWrite(dir1pin,HIGH);
        digitalWrite(dir2pin,LOW);
      	
      	motorspeed = 255;
      	analogWrite(speedpin,motorspeed);
      	break;
      
      case 1:  // vol+ for increasing the speed
      	motorspeed = motorspeed + 15;
      
        analogWrite(speedpin,motorspeed);
      	break;
      
      case 2:  // func button for stopping
        motorspeed = 0;
      	analogWrite(speedpin,motorspeed);
      	break;
      
      case 4: // rewine button for changing the direction
      	digitalWrite(dir1pin,LOW);
      	digitalWrite(dir2pin,HIGH);
     	break;
      
      case 6: //fastforward for changing the direction
      	digitalWrite(dir1pin,HIGH);
        digitalWrite(dir2pin,LOW);
      	break;
      
      case 9:  // vol- for decreasing the motorspeed;
        motorspeed = motorspeed - 15;
      	analogWrite(speedpin,motorspeed);
        break;
      
      if(motorspeed > 255){  
        motorspeed = 255;
      }
      
      if(motorspeed < -255){
        motorspeed = -255;
      }	
    }
    
    IrReceiver.resume();
  }
}