#include "motor.hpp"
#include "encoder.hpp"

/* Motor constants */
#define M1_EN 33
#define M1_A  25
#define M1_B  26
#define M2_A  27
#define M2_B  14
#define M2_EN 12

Motor motor1(M1_A, M1_B, M1_EN);
Motor motor2(M2_A, M2_B, M2_EN);

void setup() {
    /* Motors */
    motor1.halt();
    motor2.halt();

    /* Encoders */
    initEnc();

    /* Serial */
    Serial.begin(115200);
    
}

void loop() {
    motor1.setDirection(true);
    motor2.setDirection(true);
    motor1.setVelocity(1023);
    motor2.setVelocity(1023);
    delay(1000);
    Serial.println(pulses);
    motor1.setVelocity(900);
    motor2.setVelocity(900);
    delay(1000);
    Serial.println(pulses);
    motor1.setVelocity(800);
    motor2.setVelocity(800);
    delay(1000);
    Serial.println(pulses);

}
