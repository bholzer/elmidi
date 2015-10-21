#include <MIDI.h>
#include <Mode.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

MIDI_CREATE_DEFAULT_INSTANCE();

WireManager *manager;

void setup() {
//  MIDI.begin(MIDI_CHANNEL_OMNI);
  int blueNotes[NOTES_PER_WIRE] = {60, 72};
  Wire blue = *new Wire(6, blueNotes, LOW);
  Wire ora = *new Wire(7, blueNotes, LOW);
  Wire red = *new Wire(8, blueNotes, LOW);
  Wire ora2 = *new Wire(9, blueNotes, LOW);
  Wire wires[4] = {blue, ora, red, ora2};
  Serial.begin(9600);
  Serial.println(sizeof(wires));
  Serial.println("WTF");
  manager = new WireManager(new NoteMatch(MIDI, wires, sizeof(wires)));
  // Escudo status LED
  pinMode(10, OUTPUT);
}


void loop() {
//Serial.println(manager->mode->getPins());
//  if(MIDI.read()) {
//    manager->processMidi();
//  }
}
