#pragma once

#include "Arduino.h"

static const uint32_t DEFAULT_SERIAL_SPEED = 115200;

#ifdef LegALKS
static const uint8_t L_R = 12;
static const uint8_t L_G = 7;
static const uint8_t L_Y = 13;
static const uint8_t L_B = 8;
static const uint8_t L_RGB_R = 5;
static const uint8_t L_RGB_G = 11;
static const uint8_t L_RGB_B = 6;

static const uint8_t SW1 = 2;
static const uint8_t SW2 = 4;
static const uint8_t SW3 = 3;

static const uint8_t POT1 = A0;
static const uint8_t POT2 = A1;

static const uint8_t PIEZO1 = 9;
static const uint8_t PIEZO2 = 10;

static const uint8_t PHOTO = A2;

static const uint8_t DHT_PIN = A3;

#elif defined(AVR)
static const uint8_t L_R = 12;
static const uint8_t L_G = 7;
static const uint8_t L_Y = 13;
static const uint8_t L_B = 8;
static const uint8_t L_RGB_R = 5;
static const uint8_t L_RGB_G = 11;
static const uint8_t L_RGB_B = 6;

static const uint8_t SW1 = 2;
static const uint8_t SW2 = 3;
static const uint8_t SW3 = 4;

static const uint8_t POT1 = A0;
static const uint8_t POT2 = A1;

static const uint8_t PIEZO1 = 9;
static const uint8_t PIEZO2 = 10;

static const uint8_t PHOTO = A2;

static const uint8_t DHT_PIN = A3;

static const uint8_t S1 = 5;
static const uint8_t S2 = 6;
static const uint8_t S3 = 9;
static const uint8_t S4 = 10;
static const uint8_t S5 = 11;

#elif defined(ESP32)
static const uint8_t L_R = 22;
static const uint8_t L_G = 17;
static const uint8_t L_Y = 23;
static const uint8_t L_B = 5;
static const uint8_t L_RGB_R = 4;
static const uint8_t L_RGB_G = 21;
static const uint8_t L_RGB_B = 16;

static const uint8_t SW1 = 15;
static const uint8_t SW2 = 2;
static const uint8_t SW3 = 0;

static const uint8_t POT1 = 32;
static const uint8_t POT2 = 33;

static const uint8_t PIEZO1 = 19;
static const uint8_t PIEZO2 = 18;

static const uint8_t PHOTO = 25;

static const uint8_t DHT_PIN = 26;

static const uint8_t S1 = 4;
static const uint8_t S2 = 16;
static const uint8_t S3 = 18;
static const uint8_t S4 = 19;
static const uint8_t S5 = 21;

#else
  #error "Selected unsupported platform/processor!"
#endif

//alias for some pins/peripheries
static const uint8_t LED_RED = L_R;
static const uint8_t LED_GREEN = L_G;
static const uint8_t LED_YELLOW = L_Y;
static const uint8_t LED_BLUE = L_B;
static const uint8_t LED_RGB_RED = L_RGB_R;
static const uint8_t LED_RGB_GREEN = L_RGB_G;
static const uint8_t LED_RGB_BLUE = L_RGB_B;

static const uint8_t SERVO1 = S1;
static const uint8_t SERVO2 = S2;
static const uint8_t SERVO3 = S3;
static const uint8_t SERVO4 = S4;
static const uint8_t SERVO5 = S5;

void setupLeds();
void setupRgbLed();
void setupButtons();
void setupPiezo();
void setupAll();
