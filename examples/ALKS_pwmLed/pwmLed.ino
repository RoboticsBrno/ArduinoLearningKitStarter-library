#import <ALKS.h>

//Definujeme všechny piny

int potPin = A0;    // číslo pinu připojeného potenciometru
int ledPin = 8;     // číslo pinu připojené modré LED diody

int potProm = 0;    // proměnná pro analogovou hodnotu potenciometru
int ledProm = 0;    // proměnná pro analogovou hodnotu PWM

void setup(){
//nastavení pinu I/O
 pinMode(potPin, INPUT);
 pinMode(ledPin, OUTPUT);
}

void loop(){
  // načtení analogové hodnoty senzoru a uložení do proměnné
  potProm = analogRead(potPin);
  // přepočet hodnot z potenciometru na PWM LED diody
  ledProm = map(potProm, 0, 1023, 0, 255);
  // nastavení napětí na LED diodě odpovídající hodnotě PWM
  analogWrite(ledPin, ledProm);
   // pauza programu na 2 ms pro ustálení 
  // analogově-digitálního převodníku
  // po předchozím čtení hodnot
  delay(2);
}
 
