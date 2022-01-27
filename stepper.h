#ifndef STEPPER_H
#define STEPPER_H


#include "Arduino.h"


class Stepper
{
  public:
    Stepper();
    //~Stepper();
    void init(int motorPin1, int motorPin2, int motorPin3, int motorPin4);
    void update();
  private:
    void linksrum(unsigned int steps);
    void rechtsrum(unsigned int steps);
    void stop();

  private:
    int m_iMotorPin1;  // Blue   - In 1
    int m_iMotorPin2;  // Pink   - In 2
    int m_iMotorPin3; // Yellow - In 3
    int m_iMotorPin4; // Orange - In 4
	
    unsigned int m_iSteps;
    long m_lOpenTime;
    long m_lCloseTime;
    long m_lDelay;
    long m_lCurrentDelay;
    int m_iState;
    int m_iTargetPosMax;
    int m_iTargetPosMin;
    int m_iCurrentPos;
    unsigned long m_lPreviousMillis;
    unsigned long m_lPreviousMoveMillis;
    unsigned long m_lPreviousMoveMillis2;
	
	move(int state1, int state2, int state3, int state4);
};

#endif
