#include "Arduino.h"

#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>
#include <Mode.h>

NoteMatch::NoteMatch(midi::MidiInterface<HardwareSerial>& interface)
:Mode(interface)
{

}

// void NoteMatch::toggleELForNote(int note, bool on) {
//   // // Get a copy of the wires that we can filter as needed
//   // Wire wiresMatchingNote[WIRE_COUNT] = {};
//   // memcpy(wiresMatchingNote, WIRE_MANAGER.wires, sizeof(WIRE_MANAGER.wires));

//   // int matchCount = filterWiresForNote(note, wiresMatchingNote, sizeof(WIRE_MANAGER.wires)); // No way of finding size of arr from pointer, send it
//   // for(int i = 0; i < matchCount; i++) {
//   //   on ? WIRE_MANAGER.wireOn(wiresMatchingNote[i]) : WIRE_MANAGER.wireOff(wiresMatchingNote[i]);
//   // }
//   // delete[] wiresMatchingNote;
// }

// void NoteMatch::processMidi() {
// 	// switch (this->interface.getType()) {
// 	//   case midi::NoteOff:
// 	//     {
// 	//       uint8_t note = this->interface.getData1();
// 	//       toggleELForNote(note, false);
// 	//     }
// 	//     break;
// 	//   case midi::NoteOn:
// 	//     {
// 	//       uint8_t vel  = this->interface.getData2();
// 	//       uint8_t note = this->interface.getData1();
// 	//       bool isOn = (vel != 0);
// 	//       this->toggleELForNote(note, isOn);
// 	//     }
// 	//     break;
// 	//   case midi::PitchBend :
// 	//     {
// 	//       uint16_t val;
// 	//       val = this->interface.getData2() << 7 | this->interface.getData1();
// 	//       //flickerActiveWires(val);
// 	//     }
// 	//     break;
// 	// }
// }