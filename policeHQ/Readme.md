# Streetlights for RE Police HQ

Arduino Project that lights up the street of the Police HQ.
Currently it comes in two flavours:
<dl>
<dt>SinlgeRandomFlicker</dt>
<dd>One random street ligth flickers, pause and then an other random street light flickers</dd>

<dt>MultiRandomFlicker</dt>
<dd>One random street light flickers, then an other one and then the pause</dd>

</dl>

## Config.h
<dl>
<dt>DEBUG</dt>
<dd>not in use; default 0</dd>

<dt>BAUD_DEFAULT</dt>
<dd>Serial baud rate; default 9600</dd>

<dt>DELAY_FOR_NEW_BOOLEAN</dt>
<dd>Delay before the boolean value is switched</dd>

<dt>DELAY_FOR_NEW_RANDOM</dt>
<dd>Delay before a new random value is generated (random value is used to switch led)</dd>
</dl>
