#include <ALKS.h>

//Add requed files
#include "pitches.h" 
#include "themes.h"


void setup(){
}

void loop(){
  //For cycle which plays melod itself
  for (int thisNote = 0; thisNote < (sizeof(Pirates_note)/sizeof(int)); thisNote++) {

        int noteDuration = 1000 / Pirates_duration[thisNote];
        tone(PIEZO1, Pirates_note[thisNote], noteDuration);

        int pauseBetweenNotes = noteDuration * 1.05; //Tempo. ou can set your own.
        delay(pauseBetweenNotes);
        noTone(PIEZO1); //Pause
    }

}
