//potentiometer controlled LED using map
#include <Arduino.h>
const int LED=15;
const int pot=20; //ADC is GPIO 1-20 on esp32-s3

void setup(){
  pinMode(LED,OUTPUT);
  pinMode(pot,INPUT);
}

void loop(){
  //0-4095 for potentiometer- analogRead(pot) 12bit (2^12)
  int bright = map(analogRead(pot), 0, 4095, 0, 255);  // PWM range (0-255) 8 bit is LED (2^8)
  analogWrite(LED, bright);         
}