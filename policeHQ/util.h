#ifndef RANDOM_UTIL_H
#define RANDOM_UTIL_H

#include "Arduino.h"

class Util
{
  public:
    Util();
    int GetRandomIntWithDelay(int max, int delayInMs = 1000);
    bool SwitchBooleanWithDelay(int delayInMs = 1000);

  private:
    unsigned long m_lPreviousMillisForRandomValue;      /* last update time */
    unsigned long m_lPreviousMillisForBooleanValue;      /* last update time */
};

#endif
