/**
* BeltMotorDriver.cpp - Library for driving DC motor on L293D half-h bridge
* ED1 Team 5 Summer 2016
*/

#include "Arduino.h"
#include "BeltMotorDriver.h"

/**
* Constructor attaches motor to arduino pins and sets motor to OFF state
* @param enablePin pin to enable h-bridge channel
* @param pwmForwardPin pin to control forward motion
* @param pwnReversePin pin to control reverse motion
*/
BeltMotorDriver::BeltMotorDriver(int enablePin, int pwmForwardPin, int pwmReversePin){
  _enablePin = enablePin;
  _pwmForwardPin = pwmForwardPin;
  _pwmReversePin = pwmReversePin;
  pinMode(_enablePin, OUTPUT);
  pinMode(_pwmForwardPin, OUTPUT);
  pinMode(_pwmReversePin, OUTPUT);
  disableMotor();
  digitalWrite(_pwmForwardPin, LOW);
  digitalWrite(_pwmReversePin, LOW);
}

/**
* Turn motor on by setting _enablePin HIGH
*/
void BeltMotorDriver::enableMotor(){
  if(!digitalRead(_enablePin)){
    digitalWrite(_enablePin, HIGH); 
  }
}

/**
* Turn motor off by setting _enablePin LOW
*/
void BeltMotorDriver::disableMotor(){
  if(digitalRead(_enablePin)){
    digitalWrite(_enablePin, LOW);
  }
}

/**
* Drive motor in forward direction. Will enable motor if not already enabled.
*/
void BeltMotorDriver::driveForward(){
  enableMotor();
  digitalWrite(_pwmReversePin, LOW); 
  digitalWrite(_pwmForwardPin, HIGH);
}

/**
* Drive motor in forward direction. Will enable motor if not already enabled.
* @param pwm controls motor speed (0 <= pwm <= 255, default = 255)
*/
void BeltMotorDriver::driveForward(int pwm){
  enableMotor();
  digitalWrite(_pwmReversePin, LOW); 
  if(0 <= pwm && pwm <= 255){
      analogWrite(_pwmForwardPin, pwm);
  }
  else{
    digitalWrite(_pwmForwardPin, HIGH);
  }
}

/**
* Drive motor in reverse direction. Will enable motor if not already enabled.
*/
void BeltMotorDriver::driveReverse(){
  enableMotor();
  digitalWrite(_pwmForwardPin, LOW); 
  digitalWrite(_pwmReversePin, HIGH);
}

/**
* Drive motor in reverse direction. Will enable motor if not already enabled.
* @param pwm controls motor speed (0 <= pwm <= 255, default = 255)
*/
void BeltMotorDriver::driveReverse(int pwm){
  enableMotor();
  digitalWrite(_pwmForwardPin, LOW); 
  if(0 <= pwm && pwm <= 255){
      digitalWrite(_pwmReversePin, pwm);
  }
  else{
    digitalWrite(_pwmReversePin, HIGH);
  }
}