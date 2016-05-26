/**
*ColorDetector.h Library for detecting white and black objects.
*Justin Johnson Summer 2016
*ED1 Team 5
*/
#ifndef ColorDetector_h
#define ColorDetector_h

#include "Arduino.h"
#include "LED.h"

class ColorDetector{
  public:
    ColorDetector(int ledPin, int photoresistorPin);
    int detectColor();
  private:
    int _photoresistorPin;
    int _ledPin;
    LED _led;
};


#endif