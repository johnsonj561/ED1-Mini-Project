/*
  ColorDetector.cpp - Library for detecting white and black objects.
  Justin Johnson Summer 2016
  Summer 2016
*/

#include "Arduino.h"
#include "ColorDetector.h"

ColorDetector::ColorDetector(int ledPin, int photoresistorPin){
  pinMode(ledPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);
  _ledPin = ledPin;
  _photoresistorPin = photoresistorPin;
}

int ColorDetector::detectColor(){
  digitalWrite(_ledPin, HIGH);
  delay(500);
  return analogRead(_photoresistorPin);
}