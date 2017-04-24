#include <ControlButton.h>
#include <ControlTimedOutput.h>
#include <PreciseDelay.h>


#define PIN_BUTTON D2
#define PIN_LIGHT  D0

ControlButton button(PIN_BUTTON);
ControlTimedOutput light (PIN_LIGHT, 5000);
PreciseDelay loopDelay;



void setup() {
  // put your setup code here, to run once:
  button.init();
  light.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  button.tick();
  light.tick();

  if (button.pressed())
  {
    light.set();
  }

  loopDelay.delay();
}
