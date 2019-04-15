/*
Série příkladů, které vás seznámí s funkcemi tohoto shieldu.
Vytvořeno @RoboticsBrno
*/

#include <ALKS.h>

//Přidáme potřebné soubory s tóny
#include "pitches.h" 
#include "themes.h"

//Pin bzučáku
int bzucak = 9;

void setup(){
    pinMode(bzucak, OUTPUT); //Nastavíme pin bzučáku jako výstupní
}

void loop(){
  //Samotný cyklus, která nám zahraje melodii.
  for (int thisNote = 0; thisNote < (sizeof(Pirates_note)/sizeof(int)); thisNote++) {

        int noteDuration = 1000 / Pirates_duration[thisNote];
        tone(bzucak, Pirates_note[thisNote], noteDuration);

        int pauseBetweenNotes = noteDuration * 1.05; //Tempo. Pokud chcete, můžete melodii zrychlit nebo zpomalit.
        delay(pauseBetweenNotes);
        noTone(bzucak); //Pauza
    }

}
