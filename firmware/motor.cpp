#include "motor.hpp"

Motor::Motor(int inA, int inB, int enable){
    this->inA = inA;
    this->inB = inB;
    this->enable = enable;

    pinMode(inA, OUTPUT);
    pinMode(inB, OUTPUT);
    pinMode(enable, OUTPUT);

    ledcSetup(CHAN, FREQ, RSLT);
    ledcAttachPin(enable, CHAN);
    
}

void Motor::setDirection(bool dir){
    if (dir){
        digitalWrite(inA, HIGH);
	      digitalWrite(inB, LOW);
    }
    else{
        digitalWrite(inA, LOW);
	      digitalWrite(inB, HIGH);
    }
    
    return;
}

void Motor::setVelocity(unsigned int vel){
    vel = constrain(vel, 0, 1023);
    ledcWrite(CHAN, vel); 
    return;
}

void Motor::halt(){
    digitalWrite(inA, LOW);
    digitalWrite(inB, LOW);

    return;
}
