// Magic01
// This code is designed for the Dagu Magician Chassis
// Simple test of the chassis: Forwards, Reverse, SpinLeft and SpinRight
//
// The motors are controlled using the Adafruit Motor shield library
// which must be downloaded and installed first
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <Arduino.h>
#include <AFMotor.h>

AF_DCMotor mLeft(2);
AF_DCMotor mRight(1);

void forward (int spd)
{
  Serial.println("Forward");
  mLeft.run(FORWARD);
  mRight.run(FORWARD);
  mLeft.setSpeed(spd);  
  mRight.setSpeed(spd);  
}
 
void reverse(int spd)
{
  Serial.println("Reverse");
  mLeft.run(BACKWARD);
  mRight.run(BACKWARD);
  mLeft.setSpeed(spd);  
  mRight.setSpeed(spd);  
 }
 
void spinLeft(int spd)
{
  Serial.println("Spin Left");
  mLeft.run(FORWARD);
  mRight.run(BACKWARD);
  mLeft.setSpeed(spd);  
  mRight.setSpeed(spd);  
 }
 
void spinRight(int spd)
{
  Serial.println("Spin Right");
  mLeft.run(BACKWARD);
  mRight.run(FORWARD);
  mLeft.setSpeed(spd);  
  mRight.setSpeed(spd);  
}
 
void halt()
{
  Serial.println("Stop");
  mLeft.run(RELEASE);
  mRight.run(RELEASE);
  delay(10);
}



void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  forward(240);  // go forward at speed 200 (max is 255)
  delay(1000);   // keep moving for 1sec (= 1000 milliseconds)
  halt();        // stop
  delay(500);

  spinRight(200);  // spin right
  delay(1000);
  halt();        // stop
  delay(500);

  reverse(240);  // now reverse
  delay(1000);
  halt();        // stop
  delay(500);

  spinLeft(200);  // spin left
  delay(1000);
  halt();        // stop
  delay(500);

  digitalWrite(LED_BUILTIN, LOW);
  halt();        // stop
  delay(1000);

  digitalWrite(LED_BUILTIN, HIGH);
  forward(240);  // go forward at speed 200 (max is 255)
  delay(1000);   // keep moving for 1sec (= 1000 milliseconds)
  halt();        // stop
  delay(500);

  spinLeft(200);  // spin left
  delay(1000);
  halt();        // stop
  delay(500);

  reverse(240);  // now reverse
  delay(1000);
  halt();        // stop
  delay(500);

  spinRight(200);  // spin right
  delay(1000);
  halt();        // stop
  delay(500);
}
