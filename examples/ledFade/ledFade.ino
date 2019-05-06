/*
  ALKS faded LED example

  Example with fading LED.

  Source: https://github.com/ERROPiX/ESP32_AnalogWrite/blob/master/examples/ledFade/ledFade.ino
  Modified by Kryštof Černý (@CornyjK) @RoboticsBrno
*/

#include <ALKS.h>

int brightStep = 1;
int brightness = 0;

void setup()
{
    setupAll();
}

void loop()
{
    brightness += brightStep;
    if (brightness == 0 || brightness == 255)
    {
        brightStep = -brightStep;
    }

    analogWrite(L_RGB_R, brightness);

    delay(10);
}