/*
make a function (map smth like) such that when a lowest and a highest value given from 
the potentiometer (within this range 0-1023) it will affect the LED glow (within this
rang 0-255), so that the led will now have the new range (lowest, highest) which was the input
from the potentiometer
*/

#include <Arduino.h>

const int led = 15;
const int pot = 1;

//inMin= minimum input value- potentiometer min value
//inMax= maximum input value- potentiometer max value
//outMin=minimum output value- led glow min
//outMax=Maximum output value- led glow max
//potValue= current potentiometer reading 
//positionInInputRange= How far have you travelled from the start (or the input Minimum reading)

int myMap(int potValue, int inMin, int inMax, int outMin, int outMax){
  int inputRange = inMax - inMin;
  int outputRange = outMax - outMin;
  int positionInInputRange = potValue - inMin;

  return (positionInInputRange * outputRange)/ inputRange + outMin;
   
}

void setup(){
    pinMode(led, OUTPUT);
    pinMode(pot, INPUT);
}

void loop(){
    int potValue = analogRead(pot); 

    // LED will glow from 0 to 255-8bit
    int brightness = myMap(potValue, 0, 4095, 0, 255);

    analogWrite(led, brightness);
    delay(10);
}