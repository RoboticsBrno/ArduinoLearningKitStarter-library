// hal.cpp.h

#ifndef _HAL_
#define _HAL_

#include "arduino.h"
#include <Bounce.h>
#include "config.h"

Bounce btnA = Bounce(BTN_A, 5);
Bounce btnB = Bounce(BTN_B, 5);

void hal_setup()
{
	// LED
	pinMode(LED_R, OUTPUT);
	pinMode(LED_G, OUTPUT);
	pinMode(LED_B, OUTPUT);

	// Buttons
	pinMode(BTN_A, INPUT_PULLUP);
	pinMode(BTN_B, INPUT_PULLUP);
}

void color(byte r, byte g, byte b)
{
	analogWrite(LED_R, r);
	analogWrite(LED_G, g);
	analogWrite(LED_B, b);
}

void btn_loop()
{
	btnA.update();
	btnB.update();
}


#endif