#ifndef BI_STEPPER_H
#define BI_STEPPER_H

#include <Stepper.h>
#include "config.h"
#include "Arduino.h"


class BiStepper 
{
    public:
    BiStepper();
    void Init(int motorPin1, int motorPin2, int motorPin3, int motorPin4);
    void Move(int step, unsigned int delay);

    private:
    int m_iMotorSpeed;
	  unsigned long m_lPreviousMoveMillis;
};

#endif
