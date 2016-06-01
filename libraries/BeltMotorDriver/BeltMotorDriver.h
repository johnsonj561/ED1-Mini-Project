/**
* BeltMotorDriver.h Library for driving belt motor.
* ED1 Team 5 Summer 2016
*/

#ifndef BeltMotorDriver_h
#define BeltMotorDriver_h

#include "Arduino.h"

class BeltMotorDriver{
  public:
    BeltMotorDriver(int pwmForwardPin);
    void driveForward();
    void driveForward(int pwm);
    void stopMotor();
    int getState();
  private:
    int _pwmForwardPin;
    int _state;
};

#endif