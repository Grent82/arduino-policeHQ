#include "config.h"
#include "led.h"
#include "util.h"


Led ledArray[17] = {Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led()};
Led landingPadLed;
Util util;

int ledCount = sizeof(ledArray) / sizeof(ledArray[0]);

int startingPin = ledCount - 1;
int previousLed = -1;
int pauseBetweenFlickeringInMs = DELAY_FOR_NEW_BOOLEAN;
int delayBetweenNewRandomValueInMs = DELAY_FOR_NEW_RANDOM;

void setup() {
  randomSeed(analogRead(0));

  for (int i = 0; i < ledCount; i++) {
    ledArray[i].Init(startingPin - i, 200, 800);
  }

  landingPadLed.Init(ledCount, 1000, 1000);
}

void loop() {

  //multiRandomFlicker();
  singleRandomFlicker();

  landingPadLed.Flicker2();
}

void multiRandomFlicker() {
  bool canFlicker = util.SwitchBooleanWithDelay(random(pauseBetweenFlickeringInMs, 5000));
  int randF = util.GetRandomIntWithDelay(ledCount, delayBetweenNewRandomValueInMs);

  update(randF, canFlicker);
}

void singleRandomFlicker() {
  bool canFlicker = util.SwitchBooleanWithDelay(random(pauseBetweenFlickeringInMs, 5000));
  
  int randF = util.GetRandomIntWithDelay(ledCount, delayBetweenNewRandomValueInMs);
  
  if (canFlicker && randF != previousLed) 
  {
    randF = previousLed;
  }
  else if (!canFlicker)
  {
    previousLed = randF;
  }

  update(randF, canFlicker);
}

void update(int ledIndex, bool canFlicker) {
  for (int i = 0; i < ledCount; i++) {
    if (canFlicker && ledIndex == i) {
      ledArray[ledIndex].Flicker();
    } else {
      ledArray[i].On();
    }
  }
}
