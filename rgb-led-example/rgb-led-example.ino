#include <RGBLED.h>

//RGB LED pins
const int RGB_RED = 4;        //300ohm resistor
const int RGB_GREEN = 7;      //200ohm resistor
const int RGB_BLUE = 8;       //160ohm resistor
const bool RGB_PWM = false;   //disable pulse width modulation option, limits RGB to red/green/blue/yellow/magenta/cyan/white

//enabling pwm will allow RGB to display full range of colors

//initialize RGBLEB object
RGBLED mRGB(RGB_RED, RGB_GREEN, RGB_BLUE, RGB_PWM);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("loop()");
  delay(2000);
  Serial.println("red on");
  mRGB.turnOnRedLED();
  delay(2000);
  Serial.println("green on");
  mRGB.turnOnGreenLED();
  delay(2000);
  Serial.println("blue on");
  mRGB.turnOnBlueLED();
  delay(2000);
  Serial.println("yellow on");
  mRGB.turnOnYellowLED();
  delay(2000);
  Serial.println("magenta on");
  mRGB.turnOnMagentaLED();
  delay(2000);Serial.println("cyan on");
  mRGB.turnOnCyanLED();
  delay(2000);Serial.println("turn off");
  mRGB.turnOffLED();
  delay(5000);


}


