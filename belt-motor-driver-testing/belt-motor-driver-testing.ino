#include <BeltMotorDriver.h>

const int BELT_MOTOR_FWD = 5;

BeltMotorDriver mBeltMotorDriver(BELT_MOTOR_FWD);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("loop()");
  delay(2000);
  Serial.println("driveForwad()");
  mBeltMotorDriver.driveForward();
  delay(3000);
  Serial.println("stopMotor()");
  mBeltMotorDriver.stopMotor();
  delay(3000);
  Serial.println("slowly increase speed");
  for(int i = 0; i < 255; ++i){
    mBeltMotorDriver.driveForward(i);
    delay(50);
  }
  Serial.println("stopMotor()");
  mBeltMotorDriver.stopMotor();
  delay(2000);
  Serial.println("slowly decrease speed");
  for(int i = 255; i > 0; --i){
    mBeltMotorDriver.driveForward(i);
    delay(50);
  }
  Serial.println("stopMotor()");
  mBeltMotorDriver.stopMotor();
  delay(2000);

}
