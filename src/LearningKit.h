#pragma once

#include "Arduino.h"

static const int DEFAULT_SERIAL_SPEED = 115200;

static const int L_R = 22;
static const int L_G = 17;
static const int L_Y = 23;
static const int L_B = 5;
static const int L_RGB_R = 4;
static const int L_RGB_G = 21;
static const int L_RGB_B = 16;

static const int SW1 = 15;
static const int SW2 = 2;
static const int SW3 = 0;

static const int POT1 = 32;
static const int POT2 = 33;

static const int PIEZO1 = 19;
static const int PIEZO2 = 18;

static const int PHOTO = 25;

static const int DHT_PIN = 26;

static const int S1 = 4;
static const int S2 = 16;
static const int S3 = 18;
static const int S4 = 19;
static const int S5 = 21;

void setupLeds();
void setupRgbLed();
void setupButtons();
