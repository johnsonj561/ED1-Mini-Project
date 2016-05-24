/*
  ColorDetector.h Library for detecting white and black objects.
  Justin Johnson Summer 2016
  ED1
*/
#ifndef ColorDetector_h
#define ColorDetector_h

#include "Arduino.h"

class ColorDetector{
  public:
    ColorDetector(int ledPin, int photoresistorPin);
    int detectColor();
  private:
    int _ledPin;
    int _photoresistorPin;
};


#endif