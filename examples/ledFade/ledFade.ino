// Not actual example, for CI purposes only

#include <Arduino.h>
#include <ALKS.h>

int brightStep = 1;
int brightness = 0;

void setup() {
  setupAll();
}

void loop() {
  brightness += brightStep;
  if ( brightness == 0 || brightness == 255 ) {
    brightStep = -brightStep;
  }

  analogWrite(L_RGB_R, brightness);

  delay(10);
}