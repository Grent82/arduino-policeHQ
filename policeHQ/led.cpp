#include "led.h"


Led::Led()
{
}

void Led::Init(int pin, long on /* = 50 */, long off /* = 50 */)
{
  m_LedPin = pin;
  pinMode(m_LedPin, OUTPUT);

  m_lOnTime = on;
  m_lOffTime = off;

  m_iLedState = LOW;
  m_lPreviousMillis = 0;
}

void Led::Flicker()
{
  int flickerPhase = millis() % (m_lOnTime + m_lOffTime);
  if (flickerPhase < m_lOffTime) {
    analogWrite(m_LedPin, random(m_lOffTime));
  } else {
    analogWrite(m_LedPin, random(120) + 135);
  }
}

void Led::On()
{
  digitalWrite(m_LedPin, HIGH);
}

void Led::Off()
{
  digitalWrite(m_LedPin, LOW);
}

void Led::Flicker2() {
  int blinkPhase = millis() % (m_lOnTime + m_lOffTime);
  if (blinkPhase < m_lOffTime) Off(); else On();
}


