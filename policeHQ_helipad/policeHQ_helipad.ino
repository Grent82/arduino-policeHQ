
#include "config.h"
#include "biStepper.h"
#include "motor.h"

BiStepper stepper;
Motor rotor;

void setup() {
  stepper.Init(4, 5, 6, 7);
  rotor.Init(8, 9, 10);
}

void loop() {

  rotor.SpeedUp();

  stepper.Move(3000, 500);
  rotor.MoveWithMaxSpeedInLastDirection();
  delay(5000);

  stepper.Move(-3000, 500);
  rotor.SpeedDown();
  delay(1000);
}
