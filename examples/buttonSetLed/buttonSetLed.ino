#include "LearningKit.h"

void setup() {
    Serial.begin(115200);
    setupRgbLed();
    setupLeds();
    setupButtons();
}

void loop() {
    if(digitalRead(SW1) == true) {
        digitalWrite(L_R, LOW);
        Serial.println("SW1 not press => no light");
    } else {
        digitalWrite(L_R, HIGH);
        Serial.println("SW1 is press => RED light");
    }
    delay(200);
}