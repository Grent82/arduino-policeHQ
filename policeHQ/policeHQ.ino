#include "config.h"
#include "light.h"


StreetLigth streetLigth;


void setup() {
  randomSeed(analogRead(0));

  streetLigth.Init(13);
}

void loop() {
  //streetLigth.MultiRandomFlicker();
  streetLigth.SingleRandomFlicker();
}
