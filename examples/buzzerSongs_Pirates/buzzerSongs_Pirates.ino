#include <ALKS.h>

//Add requed files
#include "pitches.h"
#include "themes.h"

#if defined(ESP32)
const int freq = 2000;
const int channel = 0;
const int resolution = 8;
#endif

void setup(){
  // We need to set the second PIEZO pin to the GND or fixed voltage, NOT gigh impedance
  pinMode(PIEZO1, OUTPUT);
  digitalWrite(PIEZO1, LOW);
#if defined(ESP32)
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(PIEZO2, channel);
#endif
}

void loop(){
  //For cycle which plays melod itself
  for (int thisNote = 0; thisNote < (sizeof(Pirates_note)/sizeof(int)); thisNote++) {
    int noteDuration = 1000 / Pirates_duration[thisNote];
#if defined(ESP32)
    ledcWriteTone(channel, Pirates_note[thisNote]);
    delay(noteDuration);
#else
    tone(PIEZO1, Pirates_note[thisNote], noteDuration);
#endif

    int pauseBetweenNotes = noteDuration * 1.05; //Tempo. ou can set your own.
    delay(pauseBetweenNotes);
#if defined(ESP32)
    ledcWriteTone(channel, 0);
#else
    noTone(PIEZO1); //Pause
#endif
  }
}
