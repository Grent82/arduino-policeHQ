#ifndef MOTOR_H
#define MOTOR_H

#include "config.h"
#include "Arduino.h"


class Motor
{
  public:
    Motor();
    void Init(unsigned int motor1Pin1, unsigned int motor1Pin2, unsigned int enable1Pin);
    void SpeedUp();
    void SpeedDown();
    void MoveWithMaxSpeedInLastDirection();
    void Stop();

  private:
    unsigned int uiMotor1Pin1;
    unsigned int uiMotor1Pin2;
    unsigned int uiEnable1Pin;

    unsigned int uiMaxSpeed;
    unsigned int uiSpeedUp;

    unsigned int uiPwmMax;
    unsigned int uiPwmMin;

    unsigned long m_lPreviousMoveMillis;

    void Move(unsigned int value);

};

#endif
