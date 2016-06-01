/**
*ColorDetector.h Library for detecting white and black objects.
*Justin Johnson Summer 2016
*ED1 Team 5
*/
#ifndef ColorDetector_h
#define ColorDetector_h

#include "Arduino.h"
#include "RGBLED.h"

class ColorDetector{
  public:
  ColorDetector(int redLEDPin, int greenLEDPin, int blueLEDPin, int photoresistorPin);
  bool detectObject();
  int detectColor();
  int detectRed();
  int detectGreen();
  int detectBlue();
  int detectYellow();
  int detectPink();
  int detectOrange();
  int detectAqua();
  int detectWhite();
  static const int NO_MATCH = -1;
  static const int RED_MATCH = 1;
  static const int GREEN_MATCH = 2;
  static const int BLUE_MATCH = 3;
  static const int YELLOW_MATCH = 4;
  static const int ORANGE_MATCH = 5;
  static const int AQUA_MATCH = 6;
  static const int PINK_MATCH = 7;
  static const int WHITE_MATCH= 8;
  static const int OBJECT_THRESHOLD = 500;
  int _photoresistorPin;
  int _redLEDPin;
  int _greenLEDPin;
  int _blueLEDPin;
  RGBLED _RGBLED;
};


#endif

