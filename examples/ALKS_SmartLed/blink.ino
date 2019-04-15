/*
Série příkladů, které vás seznámí s funkcemi tohoto shieldu.
Vytvořeno @RoboticsBrno
*/

//Toto je jen příklad pro pobavení. Jeho kód vás moc neposune...
#include <Bounce.h>
#include <FiniteStateMachine.h>

#define DEBUG

#include "debug.h"
#include "fsm.h"
#include "hal.h"
#include "core.h"

void setup()
{
	Serial.begin(9600);
	TRACE("Setup");

	hal_setup();
}

void loop()
{
	btn_loop();
	fsm.update();
}

