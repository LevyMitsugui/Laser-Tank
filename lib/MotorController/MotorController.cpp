#include "MotorController.h"
#include <Arduino.h>

MotorController::MotorController(int IN1, int IN2, int IN3, int IN4) {
    IN_1 = IN1;
    IN_2 = IN2;
    IN_3 = IN3;
    IN_4 = IN4;
}

void MotorController::begin() {
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT);
}

void MotorController::setMotorSpeed(float speed, int motor) {
    if ((motor != 1 && motor != 2) || abs(speed) > 100.0F) {
        return;
    }

    if (speed > 0) {
        if (motor == 1) {
            digitalWrite(IN_1, LOW);
            analogWrite(IN_2, (uint32_t) speed*2.55f);
            motor1Speed = speed;
        }

        else {
            digitalWrite(IN_3, LOW);
            analogWrite(IN_4, (uint32_t)(speed * 2.55F));
            motor2Speed = speed;
        }
    }

    else if (speed < 0) {
        if (motor == 1) {
            analogWrite(IN_1, (uint32_t) speed*2.55f);
            digitalWrite(IN_2, LOW);
            motor1Speed = speed;
        } else {
            analogWrite(IN_3, (uint32_t)(speed * 2.55F));
            digitalWrite(IN_4, LOW);
            motor2Speed = speed;
        }
    }

    else {
        coastMotors();
    }

    return;
}

void MotorController::setMotors(float speed){
    MotorController::setMotorSpeed(speed, 1);
    MotorController::setMotorSpeed(speed, 2);
}

void MotorController::stopMotors() {
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, HIGH);

    motor1Speed = 0;
    motor2Speed = 0;
}

void MotorController::coastMotors() {
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);

    motor1Speed = 0;
    motor2Speed = 0;
}

int MotorController::getSpeed(int Motor) {
    if (Motor != 1 && Motor != 2) {
        return 0;
    }

    if (Motor == 1) {
        return motor1Speed;
    } else {
        return motor2Speed;
    }
}

void MotorController::testMotors(){
    MotorController::setMotorSpeed(1, 100);
    delay(2000);
    MotorController::setMotorSpeed(1, 0);
    delay(500);
    MotorController::setMotorSpeed(1, -100);
    delay(2000);
    MotorController::setMotorSpeed(1, 0);
    delay(500);
    MotorController::setMotorSpeed(2, 100);
    delay(2000);
    MotorController::setMotorSpeed(2, 0);
    delay(500);
    MotorController::setMotorSpeed(2, -100);
    delay(2000);
    MotorController::setMotorSpeed(2, 0);
    
}