#include <LowPower.h>

int pin2 = 2;
int ledPin   = 13;

void pin2interrupt(void)
{
  // Function called when awoken from sleep
  // Detach interrupt to stop it from continuosly firing when in normal mode
}

void enterSleep(void)
{
  attachInterrupt(0, pin2interrupt, HIGH);
  Serial.println("Sleeping");
  delay(100);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  Serial.println("Awake!");
}


void setup()
{ 
  Serial.begin(9600);
  pinMode(pin2, INPUT);  
  pinMode(ledPin, OUTPUT);
}

int seconds = 0;
void loop()
{   
  delay(1000);
  seconds++;
  Serial.println("Awake in the loop!");
  Serial.println(seconds);
    if(digitalRead(pin2) == LOW && seconds == 3)
    {
      seconds = 0;
      Serial.println("No child detected, so going to sleep!");
      delay(200);
      enterSleep();
    }
    else if(digitalRead(pin2) == HIGH && seconds == 3)
    {
      seconds = 0;
    }
}

