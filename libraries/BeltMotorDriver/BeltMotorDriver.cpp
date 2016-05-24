/**
* BeltMotorDriver.cpp - Library for driving DC motor on L293D half-h bridge
* ED1 Team 5 Summer 2016
*/

#include "Arduino.h"
#include "BeltMotorDriver.h"

/**
* Constructor
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
  //initialize motor OFF
  disableMotor();
  digitalWrite(_pwmForwardPin, LOW);
  digitalWrite(_pwmReversePin, HIGH);
}

/**
* Turn motor on
*/
void BeltMotorDriver::enableMotor(){
    digitalWrite(_enablePin, HIGH);
}

/**
* Turn motor off
*/
void BeltMotorDriver::disableMotor(){
    digitalWrite(_enablePin, LOW);
}

/**
* Drive motor in forward direction
*/
void BeltMotorDriver::driveForward(){
  if(!digitalRead(_enablePin)){
    enableMotor();
  } 
  digitalWrite(_pwmReversePin, LOW); 
  digitalWrite(_pwmForwardPin, HIGH);
}

/**
* Drive motor in forward direction
* @param pwm controls motor speed (0 <= pwm <= 255, default = 255)
*/
void BeltMotorDriver::driveForward(int pwm){
  if(!digitalRead(_enablePin)){
    enableMotor();
  } 
  digitalWrite(_pwmReversePin, LOW); 
  if(0 <= pwm && pwm <= 255){
      digitalWrite(_pwmForwardPin, pwm);
  }
  else{
    digitalWrite(_pwmForwardPin, HIGH);
  }
}

/**
* Drive motor in reverse direction
*/
void BeltMotorDriver::driveReverse(){
  if(!digitalRead(_enablePin)){
    enableMotor();
  } 
  digitalWrite(_pwmForwardPin, LOW); 
  digitalWrite(_pwmReversePin, HIGH);
}

/**
* Drive motor in reverse direction
* @param pwm controls motor speed (0 <= pwm <= 255, default = 255)
*/
void BeltMotorDriver::driveReverse(int pwm){
  if(!digitalRead(_enablePin)){
    enableMotor();
  } 
  digitalWrite(_pwmForwardPin, LOW); 
  if(0 <= pwm && pwm <= 255){
      digitalWrite(_pwmReversePin, pwm);
  }
  else{
    digitalWrite(_pwmReversePin, HIGH);
  }
}