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
    ledArray[i].Init(startingPin - i, 30, 50);
  }
}

void loop() {

  //multiRandomFlicker();
  singleRandomFlicker();
}

void multiRandomFlicker() {
  bool canFlicker = util.SwitchBooleanWithDelay(3000);
  int randF = util.GetRandomIntWithDelay(ledCount);

  update(randF, canFlicker);
}

void singleRandomFlicker() {
  bool canFlicker = util.SwitchBooleanWithDelay(3000);
  int randF = util.GetRandomIntWithDelay(ledCount);
  if (canFlicker && randF != previousLed) {
    randF = previousLed;
  } else if (!canFlicker) {
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

