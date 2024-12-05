#include <Meccanoid.h>

const int chainPin = 8;  // PWM pin for the motor chain
Chain chain(chainPin);

MeccanoServo motor1;
MeccanoServo motor2;
MeccanoServo motor3;

void setup() {
  Serial.begin(9600);
  Serial.println("Meccano Smart Motor Test");

  motor1 = chain.getServo(0);
  motor2 = chain.getServo(1);
  motor3 = chain.getServo(2);

  Serial.println("Waiting for motors to connect...");
}

void loop() {
  chain.update();

  testMotorConnection();
  if (allMotorsConnected()) {
    testMotorMovement();
    testMotorColors();
    
    Serial.println("All tests completed. Waiting 10 seconds before repeating...");
    delay(10000);
  }
}

void testMotorConnection() {
  static unsigned long lastCheckTime = 0;
  if (millis() - lastCheckTime > 1000) {
    lastCheckTime = millis();
    Serial.println("Checking motor connections...");
    Serial.print("Motor 1: "); Serial.println(motor1.isConnected() ? "Connected" : "Disconnected");
    Serial.print("Motor 2: "); Serial.println(motor2.isConnected() ? "Connected" : "Disconnected");
    Serial.print("Motor 3: "); Serial.println(motor3.isConnected() ? "Connected" : "Disconnected");
  }
}

bool allMotorsConnected() {
  return motor1.isConnected() && motor2.isConnected() && motor3.isConnected();
}

void testMotorMovement() {
  Serial.println("Testing motor movement...");
  
  int positions[] = {0, 90, 180};
  for (int pos : positions) {
    Serial.print("Moving all motors to position: "); Serial.println(pos);
    motor1.setPosition(pos);
    motor2.setPosition(pos);
    motor3.setPosition(pos);
    chain.update();
    delay(2000);
  }
}

void testMotorColors() {
  Serial.println("Testing motor LED colors...");
  
  struct Color { byte r; byte g; byte b; };
  Color colors[] = {{1,0,0}, {0,1,0}, {0,0,1}, {1,1,0}, {1,0,1}, {0,1,1}, {1,1,1}};
  
  for (Color color : colors) {
    Serial.print("Setting color to R:"); Serial.print(color.r);
    Serial.print(" G:"); Serial.print(color.g);
    Serial.print(" B:"); Serial.println(color.b);
    
    motor1.setColor(color.r, color.g, color.b);
    motor2.setColor(color.r, color.g, color.b);
    motor3.setColor(color.r, color.g, color.b);
    chain.update();
    delay(1000);
  }
}