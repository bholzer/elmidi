#ifndef Mode_h
#define Mode_h

#include "Arduino.h"
#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

// Modes
#define NOTE_MATCH 0x80

class Mode {
public:
	midi::MidiInterface<HardwareSerial> interface;
	Mode(midi::MidiInterface<HardwareSerial>& interface);
	void processMidi();
};

class NoteMatch : public Mode {
public:
	NoteMatch(midi::MidiInterface<HardwareSerial>& interface);
	void processMidi();
// private:
// 	void toggleELForNote();
};

class Wire {
public:
	byte pin;
	int *notes;
	byte state;
	Wire(byte pin, int *notes, byte state);
	void update();
	void activate();
	void deactivate();
};

class WireManager {
public:
	Wire *wires;
	midi::MidiInterface<HardwareSerial>& interface;
	WireManager(Wire *wires, midi::MidiInterface<HardwareSerial>& interface);
	void allWiresOff();
	void allWiresOn();
	void wireOn(Wire otherWire);
	void wireOff(Wire otherWire);
	void processMidi();
};

#endif