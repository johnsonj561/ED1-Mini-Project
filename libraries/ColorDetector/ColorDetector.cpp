/**
*ColorDetector.cpp - Library for detecting white and black objects.
*Justin Johnson Summer 2016
*Summer 2016
*/

#include "Arduino.h"
#include "ColorDetector.h"
#include "LED.h"

/**
*Constructor declares LED with aruino output pin of ledPin and 
*configures analog input pin to read photoresistor values
*/
ColorDetector::ColorDetector(int ledPin, int photoresistorPin): _led(ledPin){
  _photoresistorPin = photoresistorPin;
  _ledPin = ledPin;
  pinMode(_photoresistorPin, INPUT);
}

/**
*Flashes LED and calculates value of light reflected back onto photoresistor
*@return value of potoresistor detected by arduino
*/
int ColorDetector::detectColor(){
  _led.turnOnLED();
  delay(100);
  int colorValue = analogRead(_photoresistorPin);
  delay(100);
  _led.turnOffLED();
  return colorValue;
}