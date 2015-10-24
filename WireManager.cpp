#include "Arduino.h"

#include <WireManager.h>


WireManager::WireManager()
{
	// memcpy(this->wires, newWires, wireArrLen);
}

WireManager::WireManager(Mode *currentMode)
{
	memcpy(&this->mode, &currentMode, sizeof(currentMode));
}

void WireManager::allWiresOff()
{
	for(int i = 0; i < 4; i++) {
		mode.wires[i].deactivate();
	}
}

void WireManager::allWiresOn()
{
	for(int i = 0; i < 4; i++) {
		mode.wires[i].activate();
	}
}

void WireManager::wireOff(Wire otherWire)
{
	otherWire.deactivate();	
}

void WireManager::wireOn(Wire otherWire)
{
	otherWire.activate();
}

void WireManager::setMode(Mode otherMode)
{
	// *mode = otherMode;
	// mode->wires = wires;
}

void WireManager::processMidi()
{
	Serial.println("DO THING Parent");
	mode.processMidiMessage();
}