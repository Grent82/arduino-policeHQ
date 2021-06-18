#ifndef LIGHT_H
#define LIGHT_H

#include "config.h"
#include "led.h"
#include "util.h"

class StreetLigth
{
    public:
    StreetLigth();
    void Init(int startPin);
    void MultiRandomFlicker();
    void SingleRandomFlicker();

    private:
    Led ledArray[13] = {Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led(), Led()};
    int ledCount;
    int startingPin;
    int previousLed;
    int pauseBetweenFlickeringInMs;
    int delayBetweenNewRandomValueInMs;

    void Update(int ledIndex, bool canFlicker);
};


#endif
