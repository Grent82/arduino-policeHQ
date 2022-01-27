#include "biStepper.h"


Stepper myStepper(200, 2, 3, 4, 5); // 1000 steps zu viel

BiStepper::BiStepper()
{
}

void BiStepper::Init(int motorPin1, int motorPin2, int motorPin3, int motorPin4)
{
	  m_lPreviousMoveMillis = 0;
    m_iMotorSpeed = 100;
	
	  myStepper = Stepper(200, motorPin1, motorPin2, motorPin3, motorPin4);

    myStepper.setSpeed(m_iMotorSpeed);
}

void BiStepper::Move(int step, unsigned int delay)
{
	  unsigned long currentMillis = millis();

	  if (currentMillis - m_lPreviousMoveMillis >= delay) {
		  m_lPreviousMoveMillis = currentMillis;
		
		  myStepper.step(step);
	  }
}
