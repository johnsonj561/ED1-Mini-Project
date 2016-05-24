#include <BeltMotorDriver.h>

BeltMotorDriver mMotor(2, 3, 4);
void setup() {
  //write to console for debug
  Serial.begin(9600);
}

void loop() {
  Serial.println("in loop()");
  delay(3000);
  
  mMotor.driveForward();
  delay(3000);
  
  Serial.println("fade led up");
  for(int i = 0; i < 255; ++i){
    mMotor.driveReverse(i);
    delay(100);
  }
  mMotor.disableMotor();
  delay(2000);
  
  Serial.println("fade led down");
  for(int i = 255; i > 0; --i){
    mMotor.driveReverse(i);
    delay(100);
  }
  mMotor.disableMotor();
  delay(3000);
  
  Serial.println("enableMotor(), was last on Reverse");
  mMotor.enableMotor();
  delay(3000);
  
  Serial.println("attempting driveForwad(-2), should default to driveForward(255)");
  mMotor.driveForward(-2);
  delay(3000);
  
  Serial.println("disableMotor()");
  mMotor.disableMotor();
  delay(3000);
  
  Serial.println("blinkingLEDs test");
  for(int i = 0; i < 100; ++i){
    mMotor.driveForward();
    delay(100);
    mMotor.driveReverse();
    delay(100);
    mMotor.disableMotor();
    delay(100);
  }
}
