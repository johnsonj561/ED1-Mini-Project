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
  : _RGBLED(redLEDPin, greenLEDPin, blueLEDPin, false){     //note pwm is disabled
    _photoresistorPin = photoresistorPin;
    pinMode(_photoresistorPin, INPUT);
  }

/**
*Flashes RGB LED various colors and returns the detected color as integer value corresponding to color
*Colors Tested Include: Red, Green, Blue, Yellow, Orange, magenta, cyan, and White
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
  //checking to make sure we have the right color
  //due to problems with green/blue values too close
  int confidence = blue - green;
  Serial.print("B-G Confidence = "); Serial.println(confidence);
  if(largest == blue && confidence < 50){
    Serial.println("Confidence < 50, returning NO_MATCH");
    colorMatch = NO_MATCH;
  }
  
  _RGBLED.turnOffLED();
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
  Serial.print("R = ");
  Serial.println(red);
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
  Serial.print("G = ");
  Serial.println(green);
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
  Serial.print("B = ");
  Serial.println(blue);
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
*Detects strength of magenta in object and returns voltage read on photoresistor
*/
int ColorDetector::detectMagenta(){
  int magenta = 0;
  _RGBLED.turnOnMagentaLED();
  delay(200);
  for(int i = 0; i < 10; ++i){
    magenta += analogRead(_photoresistorPin);
  }
  magenta = magenta/10;
  return magenta;
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
*Detects strength of cyan in object and returns voltage read on photoresistor
*/
int ColorDetector::detectCyan(){
  int cyan = 0;
  _RGBLED.turnOnCyanLED();
  delay(200);
  for(int i = 0; i < 10; ++i){
    cyan += analogRead(_photoresistorPin);
  }
  cyan = cyan/10;
  return cyan;
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

/**
*Detects an object placed in front of ColorDetector LED/Photocell
*@return true if object is present
*/
bool ColorDetector::detectObject(){
  _RGBLED.turnOnLED();
  delay(25);
  int photoCellVoltage = analogRead(_photoresistorPin);
  _RGBLED.turnOffLED();
  if(photoCellVoltage > OBJECT_THRESHOLD){
    return true;
  }
  return false;
}