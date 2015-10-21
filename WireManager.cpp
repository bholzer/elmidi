#include "Arduino.h"

#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>
#include <Mode.h>


WireManager::WireManager(Wire *wires, midi::MidiInterface<HardwareSerial>& interface)
: wires(wires), interface(interface)
{

}

void WireManager::allWiresOff()
{
	for(int i = 0; i < 4; i++) {
		wires[i].deactivate();
	}
}

void WireManager::allWiresOn()
{
	for(int i = 0; i < 4; i++) {
		wires[i].activate();
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

void WireManager::processMidi()
{
		
}