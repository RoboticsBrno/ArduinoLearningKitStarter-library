#import <ALKS.h>
 
//We define all pins
 
int potPin = A0;   
int ledPin = 8;     
 
int potProm = 0;    
int ledProm = 0;   
 
void setup(){
 ledcSetup(1, 12000, 8);
}
 
void loop(){
  
  potProm = analogRead(POT1);
 
  ledProm = map(potProm, 0, 1023, 0, 255);
 
  ledcWrite(LED_BLUE, ledProm);
 
  delay(2);
}
 

 
