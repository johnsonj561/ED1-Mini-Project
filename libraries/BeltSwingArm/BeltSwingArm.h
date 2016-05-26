/**
* BeltSwingArm offers servo motor controls for conveyor belt's swing arm
* ED1 Team 5 Summer 2016
*/

#ifndef BeltSwingArm_h
#define BeltSwingArm_h

#include "Arduino.h"
#include "Servo.h"

class BeltSwingArm{
  public:
    BeltSwingArm(int servoPin, int minAngle, int maxAngle);
    BeltSwingArm(int servoPin);
    ~BeltSwingArm();
    int  read();
    void attach();
    void swingLeft();
    void swingRight();
  private:
    Servo _servo;
    int _servoPin;
    int _minAngle;
    int _maxAngle;
    int _currentAngle;
};

#endif