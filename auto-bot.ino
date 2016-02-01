#include <SoftwareSerial.h>
#include <AFMotor.h>

//Define Motor
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);
AF_DCMotor Motor3(3);
AF_DCMotor Motor4(4);

char comand = '0';

void setup() {
  
  
  Serial1.begin(9600); //Bluetooth

  Motor1.setSpeed(255);
  Motor2.setSpeed(255);
  Motor3.setSpeed(255);
  Motor4.setSpeed(255);
  
}

void loop() {
  
  if ( Serial1.available() ) 
  {  
      ch = Serial1.read();
      //Serial.write(ch);                       
  }
  
  if (ch == 'z')
  {        
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);                  
    Motor3.run(FORWARD);
    Motor4.run(FORWARD);
    ch = '0';
  }

  if (ch == 'x')
  {          
    Motor1.run(BACKWARD);
    Motor2.run(BACKWARD);     
    Motor3.run(BACKWARD);
    Motor4.run(BACKWARD);
    ch = '0';
  }

  if (ch == 'p')
  {       
    Motor1.run(RELEASE);
    Motor2.run(RELEASE);
    Motor3.run(RELEASE);
    Motor4.run(RELEASE);
    ch = '0';
  }
  

  
}  

