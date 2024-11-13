#include <Meccanoid.h>
#include <Servo.h>

const int meccanosPin = 8; //this is for one daisy chain of meccano motors (max 4 motors in one chain). change according to arduino pin being used. must be PWM pin
const int mg90Pin = 9; //this is for the elbow motor. cannot be daisy chained

Chain mecchain(int meccanosPin);
MeccanoServo servo1 = mecchain.getServo(0); // servo with id 0 (closest to pin)
MeccanoServo servo2 = mecchain.getServo(1); // servo with id 1 


void setup() {

  Serial.begin(9600); 

  //wait for both motors to connect
  while (!servo1.isConnected() || !servo2.isConnected()) { 
    meccchain.update();
    delay(100);
  }

  Serial.println("Meccano Motors Connected!");

}

void loop() {

  chain.update()

  //Recieve shoulder angles and elbow angle from pose estimation system... should return one shoulderangleY, one shoulderangleZ, and one elbowAngle nums.

  
  //remap angles if not in range of use.
  int servo1Position = map(shoulderangleY, 0, 180, 0, 180)  


  if (servo1.justConnected()) {
    servo1.setposition(int servo1Position)
  }

  // put your main code here, to run repeatedly:

}
