/**
*ColorDetector.cpp - Library for detecting white and black objects.
*Justin Johnson Summer 2016
*Summer 2016
*/

#include "Arduino.h"
#include "ColorDetector.h"
#include "RGBLED.h"

/**
*Constructor declares LED with aruino output pin of ledPin and 
*configures analog input pin to read photoresistor values
*/
ColorDetector::ColorDetector(int redLEDPin, int greenLEDPin, int blueLEDPin, int photoresistorPin)
  : _RGBLED(redLEDPin, greenLEDPin, blueLEDPin){
    _photoresistorPin = photoresistorPin;
    pinMode(_photoresistorPin, INPUT);
  }

/**
*Flashes RGB LED various colors and returns the detected color as integer value corresponding to color
*Colors Tested Include: Red, Green, Blue, Yellow, Orange, Pink, Aqua, and White
*@return value corresponding to color that was detected by photoresister
*/
int ColorDetector::detectColor(){
  int largest = 0;
  int colorMatch = NO_MATCH;
  int red = detectRed();
  if(red > largest){
    Serial.println("red > largest");
    Serial.println(red);
    largest = red;
    colorMatch = RED_MATCH;
  }
  int green = detectGreen();
  if(green > largest){
    Serial.println("green > largest");
    Serial.println(green);
    largest = green;
    colorMatch = GREEN_MATCH;
  }
  int blue = detectBlue();
  if(blue > largest){
    Serial.println("blue > largest");
    Serial.println(blue);
    largest = blue;
    colorMatch = BLUE_MATCH;
  }
  int yellow = detectYellow();
  if(yellow > largest){
    Serial.println("yellow > largest");
    Serial.println(yellow);
    largest = yellow;
    colorMatch = YELLOW_MATCH;
  }
  int orange = detectOrange();
  if(orange > largest){
    Serial.println("orange > largest");
    Serial.println(orange);
    largest = orange;
    colorMatch = ORANGE_MATCH;
  }
  int pink = detectPink();
  if(pink > largest){
    Serial.println("pink > largest");
    Serial.println(pink);
    largest = pink;
    colorMatch = PINK_MATCH;
  }
  int aqua = detectAqua();
  if(aqua > largest){
    Serial.println("aqua > largest");
    Serial.println(aqua);
    largest = aqua;
    colorMatch = AQUA_MATCH;
  }
  int white = detectWhite();
  if(white > largest){
    Serial.println("white > largest");
    Serial.println(white);
    largest = white;
    colorMatch = WHITE_MATCH;
  }
  return colorMatch;
}

/**
*Detects strength of red in object and returns voltage read on photoresistor
*/
int ColorDetector::detectRed(){
  int red = 0;
  _RGBLED.turnOnRedLED();
  delay(200);
  for(int i = 0; i < 10; ++i){
    red += analogRead(_photoresistorPin);
  }
  red = red/10;
  return red;
}

/**
*Detects strength of green in object and returns voltage read on photoresistor
*/
int ColorDetector::detectGreen(){
  int green = 0;
  _RGBLED.turnOnGreenLED();
  delay(200);
  for(int i = 0; i < 10; ++i){
    green += analogRead(_photoresistorPin);
  }
  green = green/10;
  return green;
}

/**
*Detects strength of blue in object and returns voltage read on photoresistor
*/
int ColorDetector::detectBlue(){
  int blue = 0;
  _RGBLED.turnOnBlueLED();
  delay(200);
  for(int i = 0; i < 10; ++i){
    blue += analogRead(_photoresistorPin);
  }
  blue = blue/10;
  return blue;
}

/**
*Detects strength of yellow in object and returns voltage read on photoresistor
*/
int ColorDetector::detectYellow(){
  int yellow = 0;
  _RGBLED.turnOnYellowLED();
  delay(200);
  for(int i = 0; i < 10; ++i){
    yellow += analogRead(_photoresistorPin);
  }
  yellow = yellow/10;
  return yellow;
}

/**
*Detects strength of pink in object and returns voltage read on photoresistor
*/
int ColorDetector::detectPink(){
  int pink = 0;
  _RGBLED.turnOnPinkLED();
  delay(200);
  for(int i = 0; i < 10; ++i){
    pink += analogRead(_photoresistorPin);
  }
  pink = pink/10;
  return pink;
}

/**
*Detects strength of orange in object and returns voltage read on photoresistor
*/
int ColorDetector::detectOrange(){
  int orange = 0;
  _RGBLED.turnOnOrangeLED();
  delay(200);
  for(int i = 0; i < 10; ++i){
    orange += analogRead(_photoresistorPin);
  }
  orange = orange/10;
  return orange;
}

/**
*Detects strength of aqua in object and returns voltage read on photoresistor
*/
int ColorDetector::detectAqua(){
  int aqua = 0;
  _RGBLED.turnOnAquaLED();
  delay(200);
  for(int i = 0; i < 10; ++i){
    aqua += analogRead(_photoresistorPin);
  }
  aqua = aqua/10;
  return aqua;
}

/**
*Detects strength of white in object and returns voltage read on photoresistor
*/
int ColorDetector::detectWhite(){
  int white = 0;
  _RGBLED.turnOnLED();
  delay(200);
  for(int i = 0; i < 10; ++i){
    white += analogRead(_photoresistorPin);
  }
  white = white/10;
  return white;
}