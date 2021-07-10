#include "config.h"
#include "light.h"
#include "biStepper.h"


StreetLigth streetLigth; // 17 Leds, start bei pin Anzahl - 1

BiStepper stepper;


void setup() {
  randomSeed(analogRead(0));

  //streetLigth.Init();

  stepper.Init(8, 9, 10, 11);
}

void loop() {
  //streetLigth.MultiRandomFlicker();
  //streetLigth.SingleRandomFlicker();

  stepper.Move(-3000);
  delay(500);
  stepper.Move(3000);
  delay(500);
}
