/*Button 1 → count up
Button 2 → count down
2 LEDs show count in binary from 0 to 3. 
binary of 
0---0
1---01
2---10
3---11
*/

#include <Arduino.h>

const int buttonUp =11; //yellow
const int buttonDown = 14; //orange

const int led1 = 15;
const int led2 = 16;

int count = 0;

void counting(){
    if(count == 0){
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
    }
    else if(count == 1){
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
    }
    else if(count == 2){
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
    }
    else if(count == 3){
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
    }
}

void setup(){

    //connect the button one side to vcc to use PULLDOWN
    pinMode(buttonUp, INPUT_PULLUP);
    pinMode(buttonDown, INPUT_PULLUP);

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);

    Serial.begin(115200);

    counting();
}

void loop(){

//UP
    if(digitalRead(buttonUp) == LOW){
        count++;
        if(count > 3){
            count = 0;
        }
        counting();
        Serial.println(count);

        //checking if the button is still pressed after every interval
        while(digitalRead(buttonUp) == LOW){
           delay(10);
        }
}

    //DOWN
if(digitalRead(buttonDown) == LOW){
    count--;
    if(count < 0){
        count = 3;
    }

    counting();
    Serial.println(count);
    while(digitalRead(buttonDown) == LOW){
        delay(10);
    }
}
}