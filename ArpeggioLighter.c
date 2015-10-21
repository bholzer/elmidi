#include <MIDI.h>
#include <Mode.h>

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
  Wire *wireRef;
  wireRef = wires;
  Mode noteMatcherMode = *new NoteMatch(&MIDI, wireRef, sizeof(wires));
  manager = new WireManager(&noteMatcherMode);
  Serial.begin(9600);
}


void loop() {
  manager->processMidi();
}
