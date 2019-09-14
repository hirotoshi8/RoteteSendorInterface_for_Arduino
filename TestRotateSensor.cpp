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

static encoder_measure right_encoder;

void ISR_count(){
    right_encoder.count_pulse_edge();
}

void setup(){
    Serial.begin(115200);

    right_encoder.create();
    
    attachInterrupt(0, ISR_count, CHANGE);
    //attachInterrupt(1, interruput_pinA, CHANGE);

}


void loop(){
    //Serial.print("Encoder couter: ");
    //Serial.println(count);

    unsigned int pulse_width = right_encoder.measure_pulse_width();
    float rps = right_encoder.calculate_rps();
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

