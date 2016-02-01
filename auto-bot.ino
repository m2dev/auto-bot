/*
  Auto-Bot Arduino based Bot.
  Arduino MEGA + L293D Shield + MINI DC GearBox X4 + HC-05 Bluetooth
  
  Author: Matias Micheltorena (@matiargs)
  Version: 1.0.0
*/

#include <SoftwareSerial.h>
#include <AFMotor.h>

//Define Motor variables.
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);
AF_DCMotor Motor3(3);
AF_DCMotor Motor4(4);

//Define command variable
char cmd = '0';

void setup() {

  //Open serial communications at 9600 baudrate for second serial interface
  Serial1.begin(9600); 

  //Define motor speed @255
  Motor1.setSpeed(255);
  Motor2.setSpeed(255);
  Motor3.setSpeed(255);
  Motor4.setSpeed(255);  
  
}

void loop() {

  //Verify connection available
  if ( Serial1.available() ) 
  {  
      //Read incoming char    
      cmd = Serial1.read();                           
  }

  //First attemp to control the actions of the bot, this need a little refactor.
  
  //Go Fordward
  if (ch == 'z')
  {        
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);                  
    Motor3.run(FORWARD);
    Motor4.run(FORWARD);       
  }

  //Go Backward
  if (ch == 'x')
  {          
    Motor1.run(BACKWARD);
    Motor2.run(BACKWARD);     
    Motor3.run(BACKWARD);
    Motor4.run(BACKWARD);   
  }

  //Stop - Brake
  if (ch == 'p')
  {       
    Motor1.run(RELEASE);
    Motor2.run(RELEASE);
    Motor3.run(RELEASE);
    Motor4.run(RELEASE);
    
  }
  
  /*Beacuse this is running inside the loop function, 
   we need to set the command to '0' to prevent continous invoking the function run */
   ch = '0'; 
  
}  

