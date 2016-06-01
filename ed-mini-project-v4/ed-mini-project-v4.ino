#include <ColorDetector.h>
#include <BeltMotorDriver.h>
#include <BeltSwingArm.h>

//DC MOTOR PINS
const int BELT_MOTOR_ENABLE = 2;      //enable/disable motor
const int BELT_MOTOR_FWD = 5;         //pwm forward direction
const int BELT_MOTOR_RVS = 6;         //pwm reverse direction

//COLOR DETECTOR ATTRIBUTES
const int COLOR_DETECTOR_RED = 9;     //pwm for red pin of RGB 300ohm
const int COLOR_DETECTOR_GREEN = 10;  //pwm for green pin of RGB 200ohm
const int COLOR_DETECTOR_BLUE = 11;   //pwm for blue pin of RGB 160ohm
const int COLOR_DETECTOR_PHOTOCELL = A0;  //analog input for photoresistor
const int COLOR_DETECTOR_DELAY = 250;

//SWING ARM ATTRIBUTES
const int SWING_ARM = 3;              //pwm pin that controls servo
const int SWING_ARM_MIN = 50;         //min rotation of swing arm
const int SWING_ARM_MAX = 130;        //max rotation of swing arm
const int SWING_ARM_DELAY = 3000;     //total time delay to move object fro color detection zone to loading zone

BeltSwingArm mBeltSwingArm(SWING_ARM, SWING_ARM_MIN, SWING_ARM_MAX);
BeltMotorDriver mBeltMotorDriver(BELT_MOTOR_ENABLE, BELT_MOTOR_FWD, BELT_MOTOR_RVS);
ColorDetector mColorDetector(COLOR_DETECTOR_RED, COLOR_DETECTOR_GREEN, COLOR_DETECTOR_BLUE, COLOR_DETECTOR_PHOTOCELL);

bool reTest = false;


void setup() {
  Serial.begin(9600);
  mBeltSwingArm.attach();     //must attach servo during setup()
  mBeltMotorDriver.driveForward();
}

void loop() {
  
  Serial.println("in loop()");
  
  //reset reTest to false
  reTest = false;

  //loop until object detected in light tunnel
  while (!mColorDetector.detectObject()) {
    Serial.println("no object detected, DELAY");
    delay(COLOR_DETECTOR_DELAY);
  }

  //object detected, disable motor
  Serial.println("object detected, disabling motor");
  mBeltMotorDriver.disableMotor();

  delay(3000);
  
  //test for color
  Serial.println("testing for color");
  int colorDetected = mColorDetector.detectColor();
  Serial.println("colorDetected");
  //move arm according to color detected
  switch (colorDetected) {
    case ColorDetector::RED_MATCH:          //red object
      Serial.println("Red match");
      Serial.println("swinging arm left");
      mBeltSwingArm.swingLeft();          //swing arm left
      Serial.println("moving block to loading zone");
      mBeltMotorDriver.driveForward();    //move fwd while delay
      delay(SWING_ARM_DELAY);
      Serial.println("disabling motor");
      mBeltMotorDriver.disableMotor();
      Serial.println("swing arm right, pushing block into right bin");
      mBeltSwingArm.swingRight();         //swing arm right, pushing object into right bin
      break;
    case ColorDetector::GREEN_MATCH:         //green object
      Serial.println("Green match");
      Serial.println("swinging arm right");
      mBeltSwingArm.swingRight();           //swing arm right
      Serial.println("moving block to loading zone");
      mBeltMotorDriver.driveForward();      //move fwd while delay
      delay(SWING_ARM_DELAY);
      Serial.println("disabling motor");
      mBeltMotorDriver.disableMotor();
      Serial.println("swing arm left, pushing block into bin");
      mBeltSwingArm.swingLeft();            //swing arm left, pushing object into left bin
      break;
    case ColorDetector::BLUE_MATCH:          //blue object
      Serial.println("Blue match");
      Serial.println("swinging arm left to move it out of the way");
      mBeltSwingArm.swingLeft();            //swing arm left
      Serial.println("moving block to loading zone and straight off belt");
      mBeltMotorDriver.driveForward();      //move fwd while delay * 2
      delay(SWING_ARM_DELAY * 2);           //delay twice as long so object will fall of end of belt
      Serial.println("motor pushed object straight off belt");
      mBeltMotorDriver.disableMotor();      //disable motor, object pushed straight off belt
      break;
    default:
      //setting reTest to true will prevent motor from turning back on, forcing ColorDetector to re-check same block
      //we can add counter to prevent checking excessively, give up after several attempts
      Serial.println("in default, no match, let's re-test");
      reTest = true; 
  }

  Serial.println("object pushed to final location, delaying for a second");
  delay(5000);

  //if we are not re-testing, continue driving belt forward
  if(!reTest){
    Serial.println("in (!reTest), turning belt motor back on");
    mBeltMotorDriver.driveForward();
  }
  
}
