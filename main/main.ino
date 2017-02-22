#include <LowPower.h>

int ledPin   = 13;

void setup()
{   pinMode(ledPin, OUTPUT);
}

void loop()
{   for (int i=0; i<3; i++)     // LED will blink 3 times
    {  delay(2000);
       digitalWrite(ledPin, HIGH);
       delay(2000);
       digitalWrite(ledPin, LOW);
    } 

    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}

