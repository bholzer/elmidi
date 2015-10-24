#ifndef Modes_h
#define Modes_h

#include "Arduino.h"
#include <MIDI.h>
#include <ELWire.h>


class Mode {
public:
	midi::MidiInterface<HardwareSerial> *interface;
	Wire *wires;
	virtual ~Mode();
	virtual void processMidiMessage();
	Mode& operator=(const Mode& otherMode);
};

class NoteMatch : public Mode {
public:
	midi::MidiInterface<HardwareSerial> *interface;
	Wire *wires;
	NoteMatch(midi::MidiInterface<HardwareSerial> *interface, Wire *wires, size_t arrSize);
	virtual void processMidiMessage() override;
	void toggleELForNote(int note, bool isActive);
	int filterWiresForNote(int note, Wire *wires, size_t arrSize);
};

#endif