#include "Arduino.h"
#include <ELWire.h>

Wire::Wire(uint8_t pin, int *notes, byte state)
:pin(pin), notes(notes), state(state)
{
	pinMode(this->pin, OUTPUT);
}

void Wire::update()
{
	
	digitalWrite(this->pin, HIGH);
}

void Wire::activate()
{
	this->state = HIGH;
	this->update();
}

void Wire::deactivate()
{
	this->state = LOW;
	this->update();
}