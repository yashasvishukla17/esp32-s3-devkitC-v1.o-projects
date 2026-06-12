/*when the push button is pressed, an external interrupt should occur, 
this interrupt should enable a timer. This timer ISR should toggle the LED state*/
#include <Arduino.h>
const int LED_PIN=36;
const int button_pressed=6;

hw_timer_t *timer = NULL;
volatile bool ledState = false;
volatile bool timerRunning = false;
volatile int lastDebounceTime = 0;
const int debounceDelay = 200; // 200ms debounce

void IRAM_ATTR onTimer()
{
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
}
void IRAM_ATTR onButtonPress()
{
    unsigned long currentTime = millis();
    if (currentTime - lastDebounceTime < debounceDelay) {
        return;
    }
    lastDebounceTime = currentTime;
    timerRunning = !timerRunning; 
    if (timerRunning) {
        timerAlarmEnable(timer);
    } else {
        timerAlarmDisable(timer);
    }
}
void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(button_pressed, INPUT_PULLUP);
    timer = timerBegin(1, 80, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, 1000000, true);
    attachInterrupt(digitalPinToInterrupt(button_pressed), onButtonPress, FALLING);
}
void loop()
{
    Serial.println("running");
    delay(1000);
}