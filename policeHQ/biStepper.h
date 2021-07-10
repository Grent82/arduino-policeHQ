#ifndef BI_STEPPER_H
#define BI_STEPPER_H

#include <Stepper.h>
#include "config.h"


class BiStepper 
{
    public:
    BiStepper();
    void Init(int motorPin1, int motorPin2, int motorPin3, int motorPin4);
    void Move(int sstep);

    private:
    int motorSpeed;
};

#endif
