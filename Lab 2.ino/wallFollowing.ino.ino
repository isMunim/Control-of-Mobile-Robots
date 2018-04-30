// include the library code:
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_MCP23017.h>
#include <Servo.h>
#include "MySharpSensor.h"
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

Servo LServo, RServo;

const int SFSensor = A0;  
const int SLSensor = A1;  
const int SRSensor = A2;  
const int LFSensor = A3; 

void setup() {
  LServo.attach(2);
  RServo.attach(3);

  LServo.writeMicroseconds(1500); 
  RServo.writeMicroseconds(1500); 

  Serial.begin(9600);
  lcd.begin(16, 2);

  lcd.print("Wall follow");
  lcd.setCursor(1, 6);
  
  lcd.setBacklight(BLUE);
  delay(5000);
}
 float frontD ;
   float rightD ;
void loop() {
   frontD = measure(1);
   rightD = measure(2);
   
   if ( rightD> 4 && rightD < 6 && frontD >5){
  if((frontD > 8)){
      LServo.writeMicroseconds(1900);
      RServo.writeMicroseconds(1300);
  }else if (frontD <8 && frontD > 4){
     LServo.writeMicroseconds(1520);
     RServo.writeMicroseconds(1480);
     lcd.setBacklight(RED);
     }
   }
   else if( rightD < 4 || frontD< 5){
     LServo.writeMicroseconds(1430);
      delay(20);
      RServo.writeMicroseconds(1100);
      delay(20);
    }
   else if ( rightD > 6){
      LServo.writeMicroseconds(1700);
      delay(20);
      RServo.writeMicroseconds(1480);
      delay(20);
      }  
   else {
    LServo.writeMicroseconds(1500);
     RServo.writeMicroseconds(1500);
    }
  
/*
     else if(frontD > 6){
       RServo.writeMicroseconds(1530);
      delay(20);
      LServo.writeMicroseconds(1400);
      delay(20);
    } */
  delay(10);
}
float y;
float measure(int sensor) {
  takeNewMaeasurement(sensor); 
  takeNewMaeasurement(sensor);
  takeNewMaeasurement(sensor);
  takeNewMaeasurement(sensor);
  takeNewMaeasurement(sensor);

   y = getCombinedDistance(sensor);
    Serial.println("combined value");
   Serial.println(y);
  b=0; 
  c=0;
  return y;
  }
