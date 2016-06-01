/**
* BeltMotorDriver.cpp - Library for driving DC motor on L293D half-h bridge
* ED1 Team 5 Summer 2016
*/

#include "Arduino.h"
#include "BeltMotorDriver.h"

/**
* Constructor attaches motor to arduino pwm pin and sets motor to OFF state
* @param pwmForwardPin pin to control forward motion
*/
BeltMotorDriver::BeltMotorDriver(int pwmForwardPin){
  _pwmForwardPin = pwmForwardPin;
  pinMode(_pwmForwardPin, OUTPUT);
  digitalWrite(_pwmForwardPin, LOW);
  _state = 0;
}

/**
* Turn motor off by setting _pwmForwardPin LOW
*/
void BeltMotorDriver::stopMotor(){
  if(_state){
    digitalWrite(_pwmForwardPin, LOW);
    _state = 0;
  }
}

/**
* Drive motor in forward direction. Will enable motor if not already enabled.
*/
void BeltMotorDriver::driveForward(){
  digitalWrite(_pwmForwardPin, HIGH);
  _state = 1;
}

/**
* Drive motor in forward direction, speed is function of pwm
* @param pwm controls motor speed (0 <= pwm <= 255, default = 255)
*/
void BeltMotorDriver::driveForward(int pwm){
  if(0 <= pwm && pwm <= 255){
    analogWrite(_pwmForwardPin, pwm);
  }
  else{
    digitalWrite(_pwmForwardPin, HIGH);
  }
  _state = 1;
}

/**
*Checks if motor is on and return true of on
*@return _state
*/
int BeltMotorDriver::getState(){
  return _state;
}