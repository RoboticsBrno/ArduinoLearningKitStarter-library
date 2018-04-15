#include <ALKS.h>
#include <Servo.h> 
 
Servo servo1; 
 
void setup() { 
    servo1.attach(S1); 
} 
void loop() { 
    int servoPosition = map(analogRead(POT1), 0, 4096, 0, 180); 
    servo1.write(servoPosition); 
    delay(20); 
}
