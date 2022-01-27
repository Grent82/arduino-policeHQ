#include "motor.h"

Motor::Motor()
{
}

void Motor::Init(unsigned int motor1Pin1, unsigned int motor1Pin2, unsigned int enable1Pin)
{
  uiMaxSpeed = 2024;
  uiSpeedUp = 4;

  uiPwmMax = 255;
  uiPwmMin = 0;

  uiMotor1Pin1 = motor1Pin1;
  uiMotor1Pin2 = motor1Pin2;
  uiEnable1Pin = enable1Pin;

  Serial.begin(BAUD_DEFAULT);

  //Set pins as outputs
  pinMode(uiMotor1Pin1, OUTPUT);
  pinMode(uiMotor1Pin2, OUTPUT);
  pinMode(uiEnable1Pin, OUTPUT);

  digitalWrite(uiMotor1Pin1, HIGH);
  digitalWrite(uiMotor1Pin2, LOW);  // A = HIGH and B = LOW means the motor will turn right
}


void Motor::SpeedUp()
{
  for (int i = 0; i < uiMaxSpeed; i += uiSpeedUp)
  {
    Move(i);
  }
}

void Motor::SpeedDown()
{
  for (int i = uiMaxSpeed; i >= 0; i -= uiSpeedUp)
  {
    Move(i);
  }
}

void Motor::MoveWithMaxSpeedInLastDirection()
{
  analogWrite(uiEnable1Pin, uiPwmMax);
}

void Motor::Stop()
{
  analogWrite(uiEnable1Pin, uiPwmMin);
}

void Motor::Move(int value)
{
  int pwmOutput = map(value, 0, uiMaxSpeed - 1, 0, 255);
  analogWrite(uiEnable1Pin, pwmOutput);
  delay(20);
}
