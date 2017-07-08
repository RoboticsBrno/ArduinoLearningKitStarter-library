#include "LearningKit.h"

void setupLeds() {
    pinMode( L_R, OUTPUT );
    pinMode( L_G, OUTPUT );
    pinMode( L_B, OUTPUT );
    pinMode( L_Y, OUTPUT );
}

void setupRgbLed() {
    pinMode( L_RGB_R, OUTPUT );
    pinMode( L_RGB_G, OUTPUT );
    pinMode( L_RGB_B, OUTPUT );
}

void setupButtons() {
    pinMode( SW1, INPUT_PULLUP );
    pinMode( SW2, INPUT_PULLUP );
    pinMode( SW3, INPUT_PULLUP );
}