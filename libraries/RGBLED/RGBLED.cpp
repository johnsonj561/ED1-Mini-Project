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
*@param pwmOn enables use of pulse width modulation using analogWrite(pwm) if set true
*/
RGBLED::RGBLED(int redLEDPin, int greenLEDPin, int blueLEDPin, bool pwmOn){
  //assign pins
  _redLEDPin = redLEDPin;
  _greenLEDPin = greenLEDPin;
  _blueLEDPin = blueLEDPin;
  //set pins to output
  pinMode(_redLEDPin, OUTPUT);
  pinMode(_greenLEDPin, OUTPUT);
  pinMode(_blueLEDPin, OUTPUT);
  //pwmOn allows use of pulse width modulation with analogWrite(pwm)
  _pwmOn = pwmOn;
  //set pins HIGH, LED OFF
  _state = 1; //setting state to on to allow for turnOffLED() call
  turnOffLED();
}

/**
*Signals RGB(0, 0, 0) to create white light
*/
void RGBLED::turnOnLED(){
  digitalWrite(_redLEDPin, LOW);
  _redSignal = 0;
  digitalWrite(_greenLEDPin, LOW);
  _greenSignal = 0;
  digitalWrite(_blueLEDPin, LOW);
  _blueSignal = 0;
  _state = 1;
}

/**
*Turn on LED with assigned PWM values for Red, Green, and Blue
*@param redSignal pulse width mod for red pin
*@param greenPWW pulse width mod for green pin
*@param blueSignal pulse width mod for blue pin
*/
void RGBLED::turnOnLED(int redSignal, int greenSignal, int blueSignal){
  turnOffLED();
  if(_pwmOn){
    _redSignal = redSignal;
    analogWrite(_redLEDPin, redSignal);
    _greenSignal = greenSignal;
    analogWrite(_greenLEDPin, greenSignal);
    _blueSignal = blueSignal;
    analogWrite(_blueLEDPin, blueSignal);
  }
  else{
    _redSignal = redSignal;
    digitalWrite(_redLEDPin, redSignal);
    _greenSignal = greenSignal;
    digitalWrite(_greenLEDPin, greenSignal);
    _blueSignal = blueSignal;
    digitalWrite(_blueLEDPin, blueSignal);
  }
  _state = 1;
}

/**
*Turn Off LED and set _state to False
*/
void RGBLED::turnOffLED(){
  if(_state){
    digitalWrite(_redLEDPin, HIGH);
    _redSignal = 255;
    digitalWrite(_greenLEDPin, HIGH);
    _greenSignal = 255;
    digitalWrite(_blueLEDPin, HIGH);
    _blueSignal = 255;
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
*@return _redSignal
*/
int RGBLED::getRedSignal(){
  return _redSignal;
}

/**
*Get the current PWM of RGB's green pin
*@return _redSignal
*/
int RGBLED::getGreenSignal(){
  return _greenSignal;
}

/**
*Get the current PWM of RGB's blue pin
*@return _blueSignal
*/
int RGBLED::getBlueSignal(){
  return _blueSignal;
}

/**
*Signals RGB(0, 255, 255) to create red light
*/
void RGBLED::turnOnRedLED(){
  turnOnLED(0, 255, 255);
}

/**
*Signals RGB(255, 0, 255) to create green light
*/
void RGBLED::turnOnGreenLED(){
  turnOnLED(255, 0, 255);
}

/**
*Signals (255, 255, 0) to create blue light
*/
void RGBLED::turnOnBlueLED(){
  turnOnLED(255, 255, 0);
}

/**
*Signals RGB(0, 0, 255) to create yellow light
*/
void RGBLED::turnOnYellowLED(){
  turnOnLED(0, 0, 255);
}

/**
*Signals RGB(0, 130, 255) to create orange light
*pwmOn must be enabled during RGBLED initialization
*/
void RGBLED::turnOnOrangeLED(){
  if(_pwmOn){
    turnOnLED(0, 130, 255);
  }
}

/**
*Signals RGB(0, 255, 0) to create pink light
*/
void RGBLED::turnOnMagentaLED(){
  turnOnLED(0, 255, 0);
}

/**
*Signals RGB(255, 0, 0) to create aqua light
*/
void RGBLED::turnOnCyanLED(){
  turnOnLED(255, 0, 0);
}




