#include "Arduino.h"

#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>
#include <Mode.h>

Mode::Mode(midi::MidiInterface<HardwareSerial>& interface): interface(interface) {

}

void Mode::processMidi() {

}