#include <Meccanoid.h>

const int chainPin = 3;

Chain chain(chainPin);

MeccanoServo shoulderPitchMotor;
MeccanoServo shoulderRollMotor;
MeccanoServo elbowMotor;

void setup() {
  Serial.begin(9600);

  shoulderPitchMotor = chain.getServo(0); // Motor ID 0 for shoulder pitch
  shoulderRollMotor = chain.getServo(1); // Motor ID 1 for shoulder roll
  elbowMotor = chain.getServo(2);        // Motor ID 2 for elbow

  Serial.println("Waiting for motors to connect...");
}

void loop() {
  // updates the motor chain
  chain.update();

  // Check if all motors are connected
  if (shoulderPitchMotor.isConnected() && 
      shoulderRollMotor.isConnected() && 
      elbowMotor.isConnected()) {
    
    // Check if data is available from the computer
    if (Serial.available() > 0) {
      // Read incoming data as a string
      String data = Serial.readStringUntil('\n');
      
      // angle parser; assuming that the incoming data is in string format. will need to clarify in meeting
      int commaIndex1 = data.indexOf(',');
      int commaIndex2 = data.lastIndexOf(',');

      if (commaIndex1 > 0 && commaIndex2 > commaIndex1) {
        int angle1 = data.substring(0, commaIndex1).toInt();         // Shoulder pitch angle
        int angle2 = data.substring(commaIndex1 + 1, commaIndex2).toInt(); // Shoulder roll angle
        int angle3 = data.substring(commaIndex2 + 1).toInt();       // Elbow angle

        // basically takes the parsed data and constrains it to an angle ranges within motors use
        shoulderPitchMotor.setPosition(constrain(angle1, 0, 180));
        shoulderRollMotor.setPosition(constrain(angle2, 0, 180));
        elbowMotor.setPosition(constrain(angle3, 0, 180));
      }
    }
  } else {
    Serial.println("Motors not yet connected...");
    delay(500); // Wait before retrying
  }
}