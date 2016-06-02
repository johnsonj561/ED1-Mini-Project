#include <ColorDetector.h>
#include <BeltMotorDriver.h>
#include <BeltSwingArm.h>

//Belt's DC Motor
const int BELT_MOTOR_FWD = 5;             //digital pwm pin 5 for belt's DC motor control

//Color Detector 
const int COLOR_DETECTOR_RED = 4;         //pwm for red pin of RGB 300ohm
const int COLOR_DETECTOR_GREEN = 7;       //pwm for green pin of RGB 200ohm
const int COLOR_DETECTOR_BLUE = 8;        //pwm for blue pin of RGB 160ohm
const int COLOR_DETECTOR_PHOTOCELL = A0;  //analog input for photoresistor
const int COLOR_DETECTOR_DELAY = 250;     //time delay between each color

//SWING ARM ATTRIBUTES
const int SWING_ARM = 3;              //pwm pin that controls servo
const int SWING_ARM_MIN = 50;         //min rotation of swing arm
const int SWING_ARM_MAX = 130;        //max rotation of swing arm
const int SWING_ARM_DELAY = 3000;     //total time delay to move object from color detection zone to loading zone

BeltSwingArm mBeltSwingArm(SWING_ARM, SWING_ARM_MIN, SWING_ARM_MAX);
BeltMotorDriver mBeltMotorDriver(BELT_MOTOR_FWD);
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
  mBeltMotorDriver.stopMotor();

  delay(3000);
  
  //test for color
  Serial.println("testing for color");
  int colorDetected = mColorDetector.detectColor();
  Serial.print("Color Detected: ");
  Serial.println(colorDetected);
  
  //move arm according to color detected
  switch (colorDetected) {
    case ColorDetector::RED_MATCH:          //RED OBJECT DETECTED
      Serial.println("Red match");          //push object off belt to the right
      Serial.println("swinging arm left");
      mBeltSwingArm.swingLeft();
      delay(1000);           
      Serial.println("moving block to loading zone");
      mBeltMotorDriver.driveForward();      
      delay(SWING_ARM_DELAY);
      Serial.println("disabling motor");
      mBeltMotorDriver.stopMotor();
      delay(1000);
      Serial.println("swing arm right, pushing block into right bin");
      mBeltSwingArm.swingRight();
      delay(1000);           
      break;
    case ColorDetector::GREEN_MATCH:        //GREEN OBJECT DETECTED
      Serial.println("Green match");        //push object off belt to the left
      Serial.println("swinging arm right");
      mBeltSwingArm.swingRight();   
      delay(1000);        
      Serial.println("moving block to loading zone");
      mBeltMotorDriver.driveForward();      
      delay(SWING_ARM_DELAY);
      Serial.println("disabling motor");
      mBeltMotorDriver.stopMotor();
      delay(1000);
      Serial.println("swing arm left, pushing block into bin");
      mBeltSwingArm.swingLeft();
      delay(1000);            
      break;
    case ColorDetector::BLUE_MATCH:          //BLUE OBJECT DETECTED
      Serial.println("Blue match");          //drive object straight off belt, do not push to left or right
      Serial.println("swinging arm left to move it out of the way");
      mBeltSwingArm.swingLeft();
      delay(1000);            
      Serial.println("moving block to loading zone and straight off belt");
      mBeltMotorDriver.driveForward();      
      delay(SWING_ARM_DELAY * 2);           
      Serial.println("motor pushed object straight off belt");
      mBeltMotorDriver.stopMotor();
      delay(1000);      
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
    Serial.println("match was found, no need to retest, turning belt motor back on");
    mBeltMotorDriver.driveForward();
  }
  
}
