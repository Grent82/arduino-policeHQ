#include "config.h"
#include "led.h"
#include "util.h"


Led ledArray[3] = {Led(), Led(), Led()};
Util util;

int startingPin = 13;
int ledCount = sizeof(ledArray) / sizeof(ledArray[0]);

int previousLed = -1;

void setup() {
  randomSeed(analogRead(0));

  for (int i = 0; i < ledCount; i++) {
    ledArray[i].Init(startingPin - i, 150, 1000);
  }
}

void loop() {

  //multiRandomFlicker();
  singleRandomFlicker();
}

void multiRandomFlicker() {
  bool canFlicker = util.SwitchBooleanWithDelay(3000);
  int randF = util.GetRandomIntWithDelay(ledCount);

  for (int i = 0; i < ledCount; i++) {
    if (canFlicker && randF == i) {
      ledArray[randF].Flicker();
    } else {
      ledArray[i].On();
    }
  }
}

void singleRandomFlicker() {
  bool canFlicker = util.SwitchBooleanWithDelay(3000);
  int randF = util.GetRandomIntWithDelay(ledCount);
  if (canFlicker && randF != previousLed) {
    randF = previousLed;
  } else if (!canFlicker) {
    previousLed = randF;
  }

  for (int i = 0; i < ledCount; i++) {
    if (canFlicker && randF == i) {
      ledArray[randF].Flicker();
    } else {
      ledArray[i].On();
    }
  }
}
