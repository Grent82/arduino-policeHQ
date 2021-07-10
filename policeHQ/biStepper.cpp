#include "biStepper.h"


Stepper myStepper(200, 8, 9, 10, 11); // 1000 steps zu viel

BiStepper::BiStepper()
{
}

void BiStepper::Init(int motorPin1, int motorPin2, int motorPin3, int motorPin4)
{
    motorSpeed = 100;

    myStepper.setSpeed(motorSpeed);
}

void BiStepper::Move(int step)
{
    myStepper.step(step);
}
