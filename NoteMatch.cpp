#include "Arduino.h"

#include <MIDI.h>
#include <Constants.h>
#include <Modes.h>

NoteMatch::NoteMatch(midi::MidiInterface<HardwareSerial> *interface, Wire *wires, size_t arrLen)
{
	memcpy(&this->wires, &wires, arrLen);
}

int NoteMatch::filterWiresForNote(int note, Wire *allWires, size_t wireArrSize) {
	Wire *wiresMatchingNote[WIRE_COUNT] = {};
	int matchingWireCount = 0;
	for(int i = 0; i < WIRE_COUNT; i++) {
		for(int j = 0; j < NOTES_PER_WIRE; j++) {
			if(allWires[i].notes[j] == note) {
				wiresMatchingNote[matchingWireCount] = &allWires[i];
        		matchingWireCount++;
     		}
   		}
 	}
 	// Update the provided array with the wire objects that match the note
	memcpy(allWires, wiresMatchingNote, wireArrSize);
	return matchingWireCount;
}

void NoteMatch::toggleELForNote(int note, bool on) {
 	// Get a copy of the wires that we can filter as needed
	Wire *wiresMatchingNote[WIRE_COUNT] = {};
	memcpy(wiresMatchingNote, wires, sizeof(wires));

	int matchCount = filterWiresForNote(note, *wiresMatchingNote, sizeof(wires)); // No way of finding size of arr from pointer, send it
	for(int i = 0; i < matchCount; i++) {
		on ? wiresMatchingNote[i]->activate() : wiresMatchingNote[i]->deactivate();
	}
	delete[] wiresMatchingNote;
}

// TODO: Figure out how to call this instead of parent class
void NoteMatch::processMidiMessage() {
	Serial.println("DO THING CHILD");
	switch (interface->getType()) {
	  case midi::NoteOff:
	    {
	      uint8_t note = interface->getData1();
	      toggleELForNote(note, false);
	    }
	    break;
	  case midi::NoteOn:
	    {
	      uint8_t vel  = interface->getData2();
	      uint8_t note = interface->getData1();
	      bool isOn = (vel != 0);
	      toggleELForNote(note, isOn);
	    }
	    break;
	  case midi::PitchBend:
	    {
	      uint16_t val;
	      val = interface->getData2() << 7 | interface->getData1();
	      //flickerActiveWires(val);
	    }
	    break;
	}
}