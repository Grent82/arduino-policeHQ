# Streetlights for RE Police HQ

Arduino Project that lights up the street of the Police HQ.
Currently it comes in two flavours:
* One random street ligth flickers, **pause** and then an other random street light flickers
* One random street light flickers, then an other one and then the **pause**


## Config.h

DEBUG; not in use; default 0
BAUD_DEFAULT; Serial baud rate; default 9600
DELAY_FOR_NEW_BOOLEAN; delay before the boolean value is switched
DELAY_FOR_NEW_RANDOM; delay before a new random value is generated (random value is used to switch led)
