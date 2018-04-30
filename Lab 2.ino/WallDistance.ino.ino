#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_MCP23017.h>
#include <Servo.h>
#include "MySharpSensor.h"

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();


const int SFSensor = A0;
const int SLSensor = A1;
const int SRSensor = A2;
const int LFSensor = A3;



uint8_t buttons;

float n[10];
float Kp = 0.9;


void setup() {
  LWheel.attach(2);
  RWheel.attach(3);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  
  delay(5000);

}
int j = 0;
void loop() {
  wall(1);
}
float y;
void wall (int sensor) {
  takeNewMaeasurement(sensor);
  delay(20);
  takeNewMaeasurement(sensor);
  delay(20);

  takeNewMaeasurement(sensor);
  delay(20);

  takeNewMaeasurement(sensor);
  delay(20);

  takeNewMaeasurement(sensor);
  delay(20);

  y = getCombinedDistance(sensor);
  lcd.print(y);
  b = 0;
  Serial.println("The combined distance to the wall is:");
  Serial.println(y);
  float x = FindUr(1);
  Serial.println("The Ur Value is :");
  Serial.println(x);


  if (x < 1 && x  > -1) {
    setSpeedsIPS(0, 0);

  } else if (x > 1) {

    setSpeedsIPS(x, x);
    if (x < 2.3) {

      setSpeedsIPS(x, x);


    }

  }
  else if (x < -1) {

    setSpeedsIPS(x, x);
    if (x < -4) {
      setSpeedsIPS(x, x);

    }

  }


}

float r = 5;
float Ur = 0;


float FindUr(int sensor) {
  float e = r - y;
  Ur = Kp * e;
  Serial.print("the value of UR is :");
  Serial.println(Ur);
  return Ur;
}
void setSpeedsIPS ( float rps, float lps) {
  LWheel.writeMicroseconds(1500 - rps * 10);
  RWheel.writeMicroseconds(1500 + rps * 10);
}



