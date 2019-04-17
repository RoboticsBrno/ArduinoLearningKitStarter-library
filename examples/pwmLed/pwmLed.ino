#import <ALKS.h>

//We define all pins

int potPin = A0;   

int potProm = 0;    
int ledProm = 0;   

const int freq = 5000; 
const int ledChannel = 0; 
const int resolution = 8;

const int ledPin = 16;  // 16 corresponds to GPIO16

void setup(){
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);
}

void loop(){
  
  #if defined(ESP32)
    ledcSetup(ledChannel, freq, resolution);
    
    // attach the channel to the GPIO to be controlled
    ledcAttachPin(ledPin, ledChannel);
  
    potProm = analogRead(POT1);

    ledProm = map(potProm, 0, 1023, 0, 255);

    analogWrite(LED_BLUE, ledProm);

    delay(2);
  #endif

    potProm = analogRead(POT1);

    ledProm = map(potProm, 0, 1023, 0, 255);

    analogWrite(LED_BLUE, ledProm);

    delay(2);
  #endif
}
 
