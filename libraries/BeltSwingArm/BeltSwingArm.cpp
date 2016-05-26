/**
* BeltSwingArm offers servo motor controls for conveyor belt's swing arm
* ED1 Team 5 Summer 2016
*/

#include "Arduino.h"
#include "BeltSwingArm.h"
#include "Servo.h"

/**
*Constructor congigures motor signal pin, min angle, and max angle. 
*Motor position initialized to minAngle.
*@param servoPin Arduino pin that signals motor control
*@param minAngle Minimum swing arm angle, default is 0
*@param maxAngle Maximum swing arm angle, default is 180
*/
BeltSwingArm::BeltSwingArm(int servoPin, int minAngle, int maxAngle){
  _servoPin = servoPin;
  _minAngle = ((minAngle < 0 || minAngle > 180) ? 0 : minAngle);
  _maxAngle = ((maxAngle < 0 || maxAngle > 180) ? 180 : maxAngle);
  _currentAngle = _minAngle;
}

/**
*Constructor congigures motor signal pin, min angle, and max angle.
*Default min angle (0) and max angle (180) are applied.
*Motor position initialized to minAngle.
*@param servoPin Arduino pin that signals motor control
*/
BeltSwingArm::BeltSwingArm(int servoPin){
  _servoPin = servoPin;
  _minAngle = 0;
  _maxAngle = 180;
  _currentAngle = _minAngle;
  
}

/**
*Deconstructor detaches motor from arduino
*/
BeltSwingArm::~BeltSwingArm(){
  _servo.detach();
}

/**
*Attach swing arm to _servoPin and rotates servo to _currentAngle
*Must be called during setup() or loop()
*/
void BeltSwingArm::attach(){
  _servo.attach(_servoPin);
  _servo.write(_currentAngle);
}

/**
*Returns current position of swing arm motor
*@return _currentAngle
*/
int BeltSwingArm::read(){
  return _currentAngle;
}

/**
*Rotate swing arm to minimum angle
*/
void BeltSwingArm::swingLeft(){
  _servo.write(_minAngle);
}

/**
*Rotate swing arm to maximum angle
*/
void BeltSwingArm::swingRight(){
  _servo.write(_maxAngle);
}