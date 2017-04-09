#include <LowPower.h>
#include <SoftwareSerial.h>
 
//SIM800 TX is connected to Arduino D8
#define SIM800_TX_PIN 8
 
//SIM800 RX is connected to Arduino D7
#define SIM800_RX_PIN 7
 
//Create software serial object to communicate with SIM800
SoftwareSerial serialSIM800(SIM800_TX_PIN,SIM800_RX_PIN);

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
   
  //Being serial communication with Arduino and SIM800
  serialSIM800.begin(9600);
  delay(1000);
  
  pinMode(pin2, INPUT);  
  pinMode(ledPin, OUTPUT);
  Serial.println("Setup Complete!");
}

int iterations = 0;
void loop()
{   
  delay(1000);
  iterations ++;
  Serial.println("Awake in the loop!");
  Serial.println(iterations);
    if(digitalRead(pin2) == LOW && iterations == 5)
    {
      iterations = 0;
      Serial.println("No child detected, so going to sleep!");
      delay(200);
      enterSleep();
    }
    else if(digitalRead(pin2) == HIGH && iterations == 10)
    {
      iterations = 0;
    }
}

