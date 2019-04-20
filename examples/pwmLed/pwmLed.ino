#include <ALKS.h>

int potPin = A0;
int ledPin = 8;

int potVal = 0;
int ledVal = 0;

#if defined(ESP32)
const int freq = 2000;
const int channel = 0;
const int resolution = 8;
#endif

void setup(){
#if defined(ESP32)
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(LED_GREEN, channel);
#endif
}

void loop(){

  potVal = analogRead(POT1);

#if defined(ESP32)
  ledVal = map(potVal, 0, 4095, 0, 255);
  ledcWrite(channel, ledVal);
#else
  ledVal = map(potVal, 0, 1023, 0, 255);
  analogWrite(LED_BLUE, ledVal);
#endif

  delay(2);
}
