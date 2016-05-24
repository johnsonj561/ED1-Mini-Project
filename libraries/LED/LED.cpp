/**
*ColorDetector.cpp - Library for detecting white and black objects.
*Justin Johnson Summer 2016
*Summer 2016
*/

#include "Arduino.h"
#include "LED.h"

/**
*Constructor assigns arduino pin to LED and initializes LED to OFF state
*@param ledPin arduino pin that will signal LED
*/
LED::LED(int ledPin){
  _ledPin = ledPin;
  pinMode(_ledPin, OUTPUT);
  digitalWrite(_ledPin, LOW);
  _state = false;
}

/**
*Turn On LED and set _state to True
*/
void LED::turnOnLED(){
  if(!_state){
    digitalWrite(_ledPin, HIGH);
    _state = true;
  }
}

/**
*Turn Off LED and set _state to False
*/
void LED::turnOffLED(){
  if(_state){
    digitalWrite(_ledPin, LOW);
    _state = false;
  }
}

/**
*Toggle LED state
*@return 0 if LED was turned off
*@return 1 if LED was turned on
*/
int LED::toggleLED(){
  if(_state){     //if LED is on, turn off
    turnOffLED();
    return 0;
  }         //else, turn on
  turnOnLED();
  return 1;
}

/**
*@return True if LED is on and _state = True
*@return False if LED is off and _state = False
*/
bool LED::isOn(){
  if(_state){
    return true;
  }
  return false;
}