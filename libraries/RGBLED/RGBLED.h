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
  RGBLED(int, int, int, bool);
  void turnOnLED();
  void turnOnLED(int, int, int);
  void turnOnRedLED();
  void turnOnBlueLED();
  void turnOnGreenLED();
  void turnOnYellowLED();
  void turnOnOrangeLED();
  void turnOnMagentaLED();
  void turnOnCyanLED();
  void turnOffLED();
  int toggleLED();
  int getRedSignal();
  int getGreenSignal();
  int getBlueSignal();
  bool isOn();
  private:
  int _redLEDPin;
  int _greenLEDPin;
  int _blueLEDPin;
  int _redSignal;
  int _greenSignal;
  int _blueSignal;
  bool _pwmOn;
  int _state;

};


#endif