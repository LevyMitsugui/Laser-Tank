#include <Arduino.h>
#include <MotorController.h>

//TODO Correct following pinout
#define MOT1_A 19
#define MOT1_B 20
#define MOT2_A 21
#define MOT2_B 22

//Global
//MotorController Motors(MOT1_A, MOT1_B, MOT2_A, MOT2_A);


void setup() {
  //Motors.begin();
  pinMode(MOT1_A, OUTPUT);
  pinMode(MOT1_B, OUTPUT);

  pinMode(MOT2_A, OUTPUT);
  pinMode(MOT2_B, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  //Motors.testMotors();
  digitalWrite(MOT1_A, HIGH);
  digitalWrite(MOT1_B, HIGH);

  digitalWrite(MOT2_A, LOW);
  analogWrite(MOT2_B, 255);
  Serial.println("vamo");
  delay(200);
}