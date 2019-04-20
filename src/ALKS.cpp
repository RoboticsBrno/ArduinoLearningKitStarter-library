#include "ALKS.h"

void setupLeds()
{
    pinMode(L_R, OUTPUT);
    pinMode(L_G, OUTPUT);
    pinMode(L_B, OUTPUT);
    pinMode(L_Y, OUTPUT);
}

void setupRgbLed()
{
    pinMode(L_RGB_R, OUTPUT);
    pinMode(L_RGB_G, OUTPUT);
    pinMode(L_RGB_B, OUTPUT);
}

void setupButtons()
{
    pinMode(SW1, INPUT_PULLUP);
    pinMode(SW2, INPUT_PULLUP);
    pinMode(SW3, INPUT_PULLUP);
}

void setupPiezo()
{
    pinMode(PIEZO1, OUTPUT);
    pinMode(PIEZO2, OUTPUT);
}

void setupAnalog(uint8_t resolution)
{
#ifdef ESP32
    analogWriteResolution(resolution);
#endif
}

void setupAll()
{
    setupLeds();
    setupRgbLed();
    setupButtons();
    setupPiezo();
    setupAnalog(8); // AVR uses 8-bit, so set the same for esp32
}