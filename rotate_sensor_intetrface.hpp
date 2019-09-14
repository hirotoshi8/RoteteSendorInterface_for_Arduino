#ifndef __ROTATE_SENSOR_INTERFACE_HPP__
#define __ROTATE_SENSOR_INTERFACE_HPP__

/* API for the Motor Driver */
class rotate_sensor_interface
{
public:
    
    /**********************************************************/
    /* Function: create                                       */
    /* overview: motor driver configulation as initialization */
    /* arg: void                                              */
    /* return: void                                           */
    /**********************************************************/
    virtual void create(void) = 0;

    /**********************************************************/
    /* Function: count_pulse_edge                             */
    /* overview: count the rising/down edge each pulse        */
    /* arg: void                                              */
    /* return: void                                           */
    /**********************************************************/
    virtual void count_pulse_edge(void) = 0;

    /**********************************************************/
    /* Function: measure_pulse_width                          */
    /* overview: measure the pulse width between up/down edge */
    /* arg: void                                              */
    /* return: void                                           */
    /**********************************************************/
    virtual unsigned int measure_pulse_width(void) = 0;

    /**********************************************************/
    /* Function: calculate_rpm                                */
    /* overview: calculate the pulse width for rotate sensor  */
    /* arg: void                                              */
    /* return: void                                           */
    /**********************************************************/
    virtual float calculate_rpm(void) = 0;

    /**********************************************************/
    /* Function: calculate_rps                                */
    /* overview: calculate the pulse width for rotate sensor  */
    /* arg: void                                              */
    /* return: void                                           */
    /**********************************************************/
    virtual float calculate_rps(void) = 0;

    /**********************************************************/
    /* Function: calculate_rotate_angle                       */
    /* overview: calculate the count width for rotate sensor  */
    /* arg: void                                              */
    /* return: void                                           */
    /**********************************************************/
    virtual float calculate_rotate_angle(void) = 0;

    
};
#endif