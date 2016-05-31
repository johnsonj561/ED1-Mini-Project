/**
* BeltMotorDriver.h Library for driving belt motor.
* ED1 Team 5 Summer 2016
*/

#ifndef BeltMotorDriver_h
#define BeltMotorDriver_h

#include "Arduino.h"

class BeltMotorDriver
{
  public:
    BeltMotorDriver(int enablePin, int pwmForwardPin, int pwmReversePin);
    void enableMotor();
    void disableMotor();
    void driveForward();
    void driveForward(int pwm);
    void driveReverse();
    void driveReverse(int pwm);
    int getState();
  private:
    int _enablePin;
    int _pwmForwardPin;
    int _pwmReversePin;
    int _state;
};

#endif