
#include "config.h"
#include "biStepper.h"
#include "motor.h"

BiStepper stepper;
Motor rotor;

bool m_bStart = true;
int m_iState = 0;

void setup() {
  stepper.Init(2, 3, 4, 5);
  rotor.Init(6, 7, 9); // possible pwm (enable/speed) pins : 3, 5, 6, 9, 10, 11
}

void loop() {

  if (m_bStart)
  {
    stepper.Move(3000, 500);
    m_bStart = false;
  } else if(digitalRead(10) == HIGH) {

    if (m_iState == 0)
    {
      rotor.SpeedUp();
      m_iState = 1;
    }

    if (m_iState == 1)
    {
      stepper.Move(-3000, 500);
      m_iState = 2;
    }

    if (m_iState == 2)
    {
      rotor.MoveWithMaxSpeedInLastDirection();
      delay(5000);
      m_iState = 3;
    }

    if (m_iState == 3)
    {
      stepper.Move(3000, 500);
      m_iState = 4;
    }

    if (m_iState == 4)
    {
      rotor.SpeedDown();
      m_iState = 0;
    }
  }
}
