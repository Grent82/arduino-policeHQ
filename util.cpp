#include "util.h"

int randomNumber = 0;
bool booleanValue = false;

Util::Util()
{

}

int Util::GetRandomIntWithDelay(int max, int delayInMs /*= 1000*/)
{
  unsigned long currentMillis = millis();

  if (currentMillis - m_lPreviousMillisForRandomValue > delayInMs)
  {
    m_lPreviousMillisForRandomValue = currentMillis;
    randomNumber = random(max);
  }
  return randomNumber;
}

bool Util::SwitchBooleanWithDelay(int delayInMs /*= 1000*/)
{
  unsigned long currentMillis = millis();

  if (currentMillis - m_lPreviousMillisForBooleanValue > delayInMs) {
    m_lPreviousMillisForBooleanValue = currentMillis;
    if (booleanValue == false) {
      booleanValue = true;
    } else {
      booleanValue = false;
    }
  }
  return booleanValue;
}
