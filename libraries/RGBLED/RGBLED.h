/**
*RGBLED.h Library for connecting RGB LED to Arduino and generating variuos colors
*Justin Johnson Summer 2016
*ED1
*/
#ifndef RGBLED_h
#define RGBLED_h

#include "Arduino.h"

class RGBLED{
  public:
  RGBLED(int, int, int);
  void turnOnLED();
  void turnOnLED(int, int, int);
  void turnOnRedLED();
  void turnOnBlueLED();
  void turnOnGreenLED();
  void turnOnYellowLED();
  void turnOnOrangeLED();
  void turnOnPinkLED();
  void turnOnAquaLED();
  void turnOffLED();
  int toggleLED();
  int getRedPWM();
  int getGreenPWM();
  int getBluePWM();
  bool isOn();
  private:
  int _redLEDPin;
  int _greenLEDPin;
  int _blueLEDPin;
  int _redPWM;
  int _greenPWM;
  int _bluePWM;
  int _state;

};


#endif