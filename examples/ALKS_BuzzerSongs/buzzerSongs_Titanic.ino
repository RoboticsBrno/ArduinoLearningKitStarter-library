/*
Série příkladů, které vás seznámí s funkcemi tohoto shieldu.
Vytvořeno @RoboticsBrno
*/

#import <ALKS.h>

//Importujeme potřebné tóny pro bzučák.
#include "pitches.h" 
#include "themes.h" 

//Pin pro bzučák
int bzucak = 9;

void setup(){
    pinMode(bzucak, OUTPUT);
}

void loop(){
  //Samotný cyklus, která nám zahraje melodii.
  for (int thisNote = 0; thisNote < (sizeof(Titanic_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / Titanic_duration[thisNote];
    tone(bzucak, Titanic_note[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 2.70; //Tempo. Pokud chcete, můžete melodii zrychlit nebo zpomalit.
    delay(pauseBetweenNotes);
    noTone(bzucak); //Pauza
  }
}
