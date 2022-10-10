#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <Arduino.h>

#define CHAN 0      // PWM channel <0-15>
#define FREQ 5000   // PWM frequency <hertz>
#define RSLT 10     // PWM resolution <bits>

class Motor{
    private:
        int inA;
        int inB;
        int enable;
        
    public:
        Motor(int, int, int);  
	      void setDirection(bool);
	      void setVelocity(unsigned int);
	      void halt();  
};

#endif
