#include "encoder.hpp"
//   ArduinoをC/C++で実装するに当たって必須のヘッダファイル
//
#ifndef STD_ARDUINO_HPP
#define STD_ARDUINO_HPP
#include "Arduino.h"    // ここでArduino.hをインクルードする
#endif

volatile int count = 0;
static unsigned int pulse_width = 0;

/**********************************************************/
/* Function: create                                       */
/* overview: motor driver configulation as initialization */
/* arg: void                                              */
/* return: void                                           */
/**********************************************************/
void encoder_measure::create(void){
    
    pinMode(pin_INT, INPUT_PULLUP);
    pinMode(pin_Dir, INPUT_PULLUP);


};
/**********************************************************/
/* Function: count_pulse_edge                             */
/* overview: count the rising/down edge each pulse        */
/* arg: void                                              */
/* return: void                                           */
/**********************************************************/
void encoder_measure::count_pulse_edge(void){

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
    
};
/**********************************************************/
/* Function: measure_pulse_width                          */
/* overview: measure the pulse width between up/down edge */
/* arg: void                                              */
/* return: void                                           */
/**********************************************************/
unsigned int encoder_measure::measure_pulse_width(void){
    /* measeure pulse width */
    unsigned int duration_High = pulseIn(pin_INT, HIGH);
    unsigned int pulse_duration_minco_sec = duration_High * 2.0f;

    return pulse_duration_minco_sec;

};
/**********************************************************/
/* Function: calculate_rpm                                */
/* overview: calculate the pulse width for rotate sensor  */
/* arg: void                                              */
/* return: void                                           */
/**********************************************************/
float encoder_measure::calculate_rpm(void){
};
/**********************************************************/
/* Function: calculate_rps                                */
/* overview: calculate the pulse width for rotate sensor  */
/* arg: void                                              */
/* return: void                                           */
/**********************************************************/
float encoder_measure::calculate_rps(void){

    float time_per_pulse = (float)(pulse_width) / 1000000.0f;
    float roll_per_time = 1 / (time_per_pulse * pulse_per_roll);

    return roll_per_time;

};
/**********************************************************/
/* Function: calculate_rotate_angle                       */
/* overview: calculate the count width for rotate sensor  */
/* arg: void                                              */
/* return: void                                           */
/**********************************************************/
float encoder_measure::calculate_rotate_angle(void){
    
};
