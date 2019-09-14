//   ArduinoをC/C++で実装するに当たって必須のヘッダファイル
//
#ifndef STD_ARDUINO_HPP
#define STD_ARDUINO_HPP

#include "Arduino.h"    // ここでArduino.hをインクルードする

// Arduinoで必須な関数をここで宣言しておく。
void setup();
void loop();
#endif
#include "encoder.hpp"

/* Pin settings */
const int pin_INT = 2;
const int pin_Dir = 3;

volatile int count = 0;


void ISR_pulse_count(void){
    int stateA = digitalRead(pin_INT);
    int stateB = digitalRead(pin_Dir);
    
    if(HIGH == stateA) {
        if(LOW == stateB){
            count++;
        }else if(HIGH == stateB){
            count--;
        }else{
            /* Error */
            count = 0;
        }
    }else if(LOW == stateA){
        if(HIGH == stateB){
            count++;
        }else if(LOW == stateB){
            count--;
        }else{
            /* Error */
            count = 0;
        }
    }else{
        /* Error */
        count = 0;
    }
}

unsigned int measeure_pulse_width(void){
    /* measeure pulse width */
    unsigned int duration_High = pulseIn(pin_INT, HIGH);
    unsigned int pulse_duration_minco_sec = duration_High * 2.0f;

    return pulse_duration_minco_sec;
}

float calculate_rps(unsigned int pulse_width){
    const int pulse_per_roll = 100;
    float time_per_pulse = (float)(pulse_width) / 1000000.0f;
    float roll_per_time = 1 / (time_per_pulse * pulse_per_roll);

    return roll_per_time;
}

void setup(){
    Serial.begin(115200);

    pinMode(pin_INT, INPUT_PULLUP);
    pinMode(pin_Dir, INPUT_PULLUP);

    attachInterrupt(0, ISR_pulse_count, CHANGE);
    //attachInterrupt(1, interruput_pinA, CHANGE);
}


void loop(){
    //Serial.print("Encoder couter: ");
    //Serial.println(count);

    unsigned int pulse_width = measeure_pulse_width();
    float rps = calculate_rps(pulse_width);
    // Debug
    //Serial.print("Pulse width: ");
    //Serial.println(duration_High);
    //Serial.print("roll per sec: ");
    //Serial.println(roll_per_time);
    Serial.print(pulse_width);
    Serial.print(",");
    Serial.print(rps);
    Serial.println(",");
}

