/**
*RGBLED.h Library for connecting RGB LED to Arduino and generating variuos colors
*Justin Johnson Summer 2016
*Summer 2016
*/

#include "Arduino.h"
#include "RGBLED.h"

/**
*Constructor assigns arduino pins to LED and initializes LED to OFF state
*@param redLedPin signals red pin of RGB
*@param greenLedPin signals green pin of RGB
*@param blueLedPin signals blue pin of RGB
*/
RGBLED::RGBLED(int redLedPin, int greenLedPin, int blueLedPin){
  //assign pins
  _redLEDPin = redLedPin;
  _greenLEDPin = greenLedPin;
  _blueLEDPin = blueLedPin;
  //set pins to output
  pinMode(_redLEDPin, OUTPUT);
  pinMode(_greenLEDPin, OUTPUT);
  pinMode(_blueLEDPin, OUTPUT);
  //set pins HIGH, LED OFF
  _state = 1; //setting state to on to allow for turnOffLED() call
  turnOffLED();
}

/**
*Turn on LED (white light) and set _state to 1
*/
void RGBLED::turnOnLED(){
  digitalWrite(_redLEDPin, LOW);
  _redPWM = 0;
  digitalWrite(_greenLEDPin, LOW);
  _greenPWM = 0;
  digitalWrite(_blueLEDPin, LOW);
  _bluePWM = 0;
    _state = 1;
}

/**
*Turn on LED with assigned PWM values for Red, Green, and Blue
*@param redPWM pulse width mod for red pin
*@param greenPWW pulse width mod for green pin
*@param bluePWM pulse width mod for blue pin
*/
void RGBLED::turnOnLED(int redPWM, int greenPWM, int bluePWM){
  turnOffLED();
  _redPWM = redPWM;
  analogWrite(_redLEDPin, redPWM);
  _greenPWM = greenPWM;
  analogWrite(_greenLEDPin, greenPWM);
  _bluePWM = bluePWM;
  analogWrite(_blueLEDPin, bluePWM);
  _state = 1;
}

/**
*Turns off all RGB pins and then sets _redLEDPin low, turning on Red LED
*/
void RGBLED::turnOnRedLED(){
  turnOnLED(0, 255, 255);
}

/**
*Turns off all RGB pins and then sets _greenLEDPin low, turning on Green LED
*/
void RGBLED::turnOnGreenLED(){
  turnOnLED(255, 0, 255);
}

/**
*Turns off all RGB pins and then sets _blueLEDPin low, turning on Blue LED
*/
void RGBLED::turnOnBlueLED(){
  turnOnLED(255, 255, 0);
}

/**
*Assigns RGB LED pins pwm values to generate yellow light
*/
void RGBLED::turnOnYellowLED(){
  turnOnLED(0, 0, 255);
}

/**
*Assigns RGB LED pins pwm values to generate orange light
*/
void RGBLED::turnOnOrangeLED(){
  turnOnLED(0, 130, 255);
}

/**
*Assigns RGB LED pins pwm values to generate pink light
*/
void RGBLED::turnOnPinkLED(){
  turnOnLED(0, 255, 0);
}

/**
*Assigns RGB LED pins pwm values to generate orange light
*/
void RGBLED::turnOnAquaLED(){
  turnOnLED(255, 0, 0);
}



/**
*Turn Off LED and set _state to False
*/
void RGBLED::turnOffLED(){
  if(_state){
    digitalWrite(_redLEDPin, HIGH);
    _redPWM = 255;
    digitalWrite(_greenLEDPin, HIGH);
    _greenPWM = 255;
    digitalWrite(_blueLEDPin, HIGH);
    _bluePWM = 255;
    _state = 0;
  }
}

/**
*Toggle LED state with white light
*@return 0 if LED was turned off
*@return 1 if LED was turned on
*/
int RGBLED::toggleLED(){
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
bool RGBLED::isOn(){
  if(_state){
    return true;
  }
  return false;
}

/**
*Get the current PWM of RGB's red pin
*@return _redPWM
*/
int RGBLED::getRedPWM(){
  return _redPWM;
}

/**
*Get the current PWM of RGB's green pin
*@return _redPWM
*/
int RGBLED::getGreenPWM(){
  return _greenPWM;
}

/**
*Get the current PWM of RGB's blue pin
*@return _bluePWM
*/
int RGBLED::getBluePWM(){
  return _bluePWM;
}
