#include <BeltSwingArm.h>

const int SWING_ARM = 3;
const int SWING_ARM_MIN = 60;
const int SWING_ARM_MAX = 120;

BeltSwingArm mBeltSwingArm(SWING_ARM, SWING_ARM_MIN, SWING_ARM_MAX);

void setup() {
  Serial.begin(9600);
  //must attach() in setup
  mBeltSwingArm.attach();

}

void loop() {
  Serial.println("loop()");
  delay(2000);
  Serial.println("swingLeft()");
  mBeltSwingArm.swingLeft();
  delay(4000);
  Serial.println("swingRight()");
  mBeltSwingArm.swingRight();
  delay(4000);
}
