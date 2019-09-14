#ifndef __ENCODER_HPP__
#define __ENCODER_HPP__

#include "rotate_sensor_intetrface.hpp"

/* Pin settings */
const int pin_INT = 2;
const int pin_Dir = 3;

const int pulse_per_roll = 100;


class encoder_measure : public rotate_sensor_interface
{
public:
    encoder_measure(){};
    ~encoder_measure(){};

    /**********************************************************/
    /* Function: create                                       */
    /* overview: motor driver configulation as initialization */
    /* arg: void                                              */
    /* return: void                                           */
    /**********************************************************/
    virtual void create(void);

    /**********************************************************/
    /* Function: count_pulse_edge                             */
    /* overview: count the rising/down edge each pulse        */
    /* arg: void                                              */
    /* return: void                                           */
    /**********************************************************/
    virtual void count_pulse_edge(void);

    /**********************************************************/
    /* Function: measure_pulse_width                          */
    /* overview: measure the pulse width between up/down edge */
    /* arg: void                                              */
    /* return: void                                           */
    /**********************************************************/
    virtual unsigned int measure_pulse_width(void);

    /**********************************************************/
    /* Function: calculate_rpm                                */
    /* overview: calculate the pulse width for rotate sensor  */
    /* arg: void                                              */
    /* return: void                                           */
    /**********************************************************/
    virtual float calculate_rpm(void);

    /**********************************************************/
    /* Function: calculate_rps                                */
    /* overview: calculate the pulse width for rotate sensor  */
    /* arg: void                                              */
    /* return: void                                           */
    /**********************************************************/
    virtual float calculate_rps(void);

    /**********************************************************/
    /* Function: calculate_rotate_angle                       */
    /* overview: calculate the count width for rotate sensor  */
    /* arg: void                                              */
    /* return: void                                           */
    /**********************************************************/
    virtual float calculate_rotate_angle(void);

private:

};

#endif