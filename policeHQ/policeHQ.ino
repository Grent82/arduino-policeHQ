#include "config.h"
#include "light.h"
#include "biStepper.h"


StreetLigth streetLigth; // 17 Leds, start bei pin Anzahl - 1
Led landingPadLed;

BiStepper stepper;


void setup() {
  randomSeed(analogRead(0));

  //streetLigth.Init();
  //landingPadLed.Init(17, 1000, 1000);

  stepper.Init(8, 9, 10, 11);
}

void loop() {
  //streetLigth.MultiRandomFlicker();
  //streetLigth.SingleRandomFlicker();
  //landingPadLed.Flicker2();

  stepper.Move(-3000);
  delay(500);
  stepper.Move(3000);
  delay(500);
}
