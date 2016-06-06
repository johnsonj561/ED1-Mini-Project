/**
* BeltSwingArmV2 offers servo motor controls for conveyor belt's swing arm
* ED1 Team 5 Summer 2016
*/

#ifndef BeltSwingArmV2_h
#define BeltSwingArmV2_h

#include "Arduino.h"
#include "Servo.h"

class BeltSwingArmV2{
  public:
    BeltSwingArmV2(int, int);
    ~BeltSwingArmV2();
    int  read();
    void attach();
    void moveToLoading();
    void openHand();
    void closeHand();
    void moveToBin(int);
    static const int RED_BIN_POSITION = 1;
    static const int GREEN_BIN_POSITION = 2;
    static const int BLUE_BIN_POSITION = 3;
    static const int YELLOW_BIN_POSITION = 4;
    static const int MAGENTA_BIN_POSITION = 5;
    static const int CYAN_BIN_POSITION = 6;
  private:
    Servo _rotationServo;
    Servo _handServo;
    int _rotationServoPin;
    int _handServoPin;
    int _currentRotationPosition;
    int _currentHandPosition; 
};

#endif