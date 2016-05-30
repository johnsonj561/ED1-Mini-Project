#include <RGBLED.h>

const int redPin = 5;
const int greenPin = 3;
const int bluePin = 6;

RGBLED mRGBLED(redPin, greenPin, bluePin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("loop()");
  Serial.println("turn on red");
  mRGBLED.turnOnRedLED();
  delay(3000);
  Serial.println("turn on green");
  mRGBLED.turnOnGreenLED();
  delay(3000);
  Serial.println("turn on blue");
  mRGBLED.turnOnBlueLED();
  delay(3000);
  Serial.println("turn on yellow");
  mRGBLED.turnOnYellowLED();
  delay(3000);
  Serial.println("turn on pink");
  mRGBLED.turnOnPinkLED();
  delay(3000);
  Serial.println("turn on orange");
  mRGBLED.turnOnOrangeLED();
  delay(3000);
  Serial.println("turn on aqua");
  mRGBLED.turnOnAquaLED();
  delay(3000);
  Serial.println("turn on white");
  mRGBLED.turnOnLED();
  delay(3000);
  
}
