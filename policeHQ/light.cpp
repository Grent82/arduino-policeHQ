#include "light.h"

Util util;

StreetLigth::StreetLigth()
{
}


void StreetLigth::Init(int startPin)
{
    startingPin = 13;

    pauseBetweenFlickeringInMs = DELAY_FOR_NEW_BOOLEAN;
    delayBetweenNewRandomValueInMs = DELAY_FOR_NEW_RANDOM;

    ledCount = sizeof(ledArray) / sizeof(ledArray[0]);

    for (int i = 0; i < 13; i++) {
        ledArray[i].Init(startingPin - i, 30, 50);
    }
}

void StreetLigth::MultiRandomFlicker() {
  bool canFlicker = util.SwitchBooleanWithDelay(pauseBetweenFlickeringInMs);
  int randF = util.GetRandomIntWithDelay(ledCount, delayBetweenNewRandomValueInMs);

  Update(randF, canFlicker);
}

void StreetLigth::SingleRandomFlicker() {
  bool canFlicker = util.SwitchBooleanWithDelay(pauseBetweenFlickeringInMs);
  int randF = util.GetRandomIntWithDelay(ledCount, delayBetweenNewRandomValueInMs);
  if (canFlicker && randF != previousLed) {
    randF = previousLed;
  } else if (!canFlicker) {
    previousLed = randF;
  }

  Update(randF, canFlicker);
}

void StreetLigth::Update(int ledIndex, bool canFlicker) {
  for (int i = 0; i < ledCount; i++) {
    if (canFlicker && ledIndex == i) {
      ledArray[ledIndex].Flicker();
    } else {
      ledArray[i].On();
    }
  }
}
