/********************************************************
/ created by karuuzo
/
/ Motion sensor HC-SR501 example
/ Important - Delay sensor measures motion in ~5-6 sec.
/ If sensor detection set below 5s, there can be false delays
/ (sensor show no motion while motion exists)
/ Motion sensor "warm up" time ~60 sec, try to not distrub device
/ in this time. In this time device can set false readings
/
/ to minimize false delays, use delay output (pinDelayLight)
/
/*********************************************************/


#include <PreciseDelay.h>
#include <ControlTimedOutput.h>
#include <ControlButton.h>

const int pinMotionDetector = 11;  // sensor input pin
const int pinLight = 13;           // light directly connected to sensor
const int pinDelayLight = 12;      // light with delay turn off

ControlTimedOutput lcdLight (pinLight, 10);
ControlTimedOutput lcdDelayLight (pinDelayLight, 10000);
ControlButton motionSensor (pinMotionDetector);

// main cycle timer
PreciseDelay preciseDelay(250);

void setup()
{
  lcdLight.init();
  lcdDelayLight.init();
  motionSensor.init();
  Serial.begin(9600);
  Serial.println ("Start...");
}

bool sensed = false;
long startTime = 0;
void loop()
{
  motionSensor.tick();
  if (motionSensor.down())
  {
    lcdLight.set();
    lcdDelayLight.set();

    if (!sensed)
    {
      sensed = true;
      long sensorTime = (millis() - startTime) / 1000;
      startTime = millis();
      Serial.print ("Sensor idle - ");
      Serial.print (sensorTime);
      Serial.println ("s");
    }
  }
  else
  {
    if (sensed)
    {
      sensed = false;
      long sensorTime = (millis() - startTime) / 1000;
      startTime = millis();
      Serial.print ("Sensor move - ");
      Serial.print (sensorTime);
      Serial.println ("s");
    }
  }
  lcdLight.tick();
  lcdDelayLight.tick();
  preciseDelay.delay();
}
