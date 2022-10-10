/*
 * 
 * Pin 34 to 39 do not have pull-up resistors
 */
 
#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <Arduino.h>

#define E1_A  15//19
#define E1_B 4//21

volatile long int pulses;

void IRAM_ATTR count(){
    /*if (digitalRead(E1_A) && !digitalRead(E1_B))
        pulses++;
    else if (!digitalRead(E1_A) && digitalRead(E1_B))
        pulses--;*/
    pulses++;
}

void initEnc(){
     pinMode(E1_A, INPUT_PULLUP);
     pinMode(E1_B, INPUT_PULLUP);
     attachInterrupt(E1_A, count, CHANGE);
     attachInterrupt(E1_B, count, CHANGE);
     
     pulses = 0;
}

/*
class Encoder{
    private:
        int chA;
        int chB;
        unsigned long int pulses;

    public:
        Encoder(int, int);
};
*/


#endif
