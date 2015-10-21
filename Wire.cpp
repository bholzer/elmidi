#include "Arduino.h"

#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>
#include <Mode.h>

Wire::Wire(byte pin, int *notes, byte state)
{
	this->pin = pin;
	this->notes = notes;
	this->state = state;
	pinMode(pin, OUTPUT);
}

void Wire::update()
{
	digitalWrite(pin, state);
}

void Wire::activate()
{
	state = HIGH;
	update();
}

void Wire::deactivate()
{
	state = LOW;
	update();
}