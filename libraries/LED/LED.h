/**
*ColorDetector.h Library for detecting white and black objects.
*Justin Johnson Summer 2016
*ED1
*/
#ifndef LED_h
#define LED_h

#include "Arduino.h"

class LED{
  public:
  LED(int ledPin);
  void turnOnLED();
  void turnOffLED();
  int toggleLED();
  bool isOn();
  private:
  int _ledPin;
  int _state;
};


#endif