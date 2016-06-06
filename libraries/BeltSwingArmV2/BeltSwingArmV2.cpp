/**
* 
offers servo motor controls for conveyor belt's swing arm
* ED1 Team 5 Summer 2016
*/

#include "Arduino.h"
#include "BeltSwingArmV2.h"
#include "Servo.h"

/**
*Constructor congigures motor signal pin, min angle, and max angle. 
*Motor position initialized to minAngle.
*@param servoPin Arduino pin that signals motor control
*@param minAngle Minimum swing arm angle, default is 0
*@param maxAngle Maximum swing arm angle, default is 180
*/
BeltSwingArmV2::BeltSwingArmV2(int rotationServoPin, int handServoPin){
  _rotationServoPin = rotationServoPin;
  _handServoPin = handServoPin;
  _currentRotationPosition = 0;
  _currentHandPosition = 0;
}

/**
*Deconstructor detaches motor from arduino
*/
BeltSwingArmV2::~BeltSwingArmV2(){
  _rotationServo.detach();
  _handServo.detach();
}

/**
*Attach swing arm to _servoPin and rotates servo to _currentAngle
*Must be called during setup() or loop()
*/
void BeltSwingArmV2::attach(){
  _rotationServo.attach(_rotationServoPin);
  _handServo.attach(_handServoPin);
  _rotationServo.write(_currentAngle);
  _handServo.write(
}

/**
*Returns current position of swing arm motor
*@return _currentAngle
*/
int BeltSwingArmV2::read(){
  return _currentAngle;
}

/**
*Rotate swing arm to minimum angle
*/
void BeltSwingArmV2::swingLeft(){
  _servo.write(_minAngle);
}

/**
*Rotate swing arm to maximum angle
*/
void BeltSwingArmV2::swingRight(){
  _servo.write(_maxAngle);
}