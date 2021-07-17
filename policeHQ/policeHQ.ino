#include "config.h"
#include "light.h"
#include "biStepper.h"


StreetLigth streetLigth; // 17 Leds, start bei pin Anzahl - 1
Led landingPadLed;

BiStepper stepper;


void setup() {
  randomSeed(analogRead(0));

  streetLigth.Init();
  landingPadLed.Init(17, 1000, 1000);

  stepper.Init(20, 21, 22, 23);
}

void loop() {
  //streetLigth.MultiRandomFlicker();
  streetLigth.SingleRandomFlicker();
  landingPadLed.Flicker2();

  //stepper.Move(-3000, 500);
  //stepper.Move(3000, 500);
}
