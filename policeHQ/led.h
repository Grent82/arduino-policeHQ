#ifndef LED_H
#define LED_H

#include "Arduino.h"

class Led
{
  public:
    Led();
    void Init(int pin, long on = 50, long off = 50);
    void Flicker();
    void Flicker2();
    void On();
    void Off();

  private:
    int m_LedPin;            /* pin where the LED is connected to */
    long m_lOnTime;       /* milliseconds of on-time */
    long m_lOffTime;      /* milliseconds of off-time */

    int m_iLedState;                    /* state of the LED (LOW/HIGH) */
    unsigned long m_lPreviousMillis;      /* last update time */
};

#endif

