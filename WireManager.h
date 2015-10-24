#ifndef WireManager_h
#define WireManager_h

#include "Arduino.h"
#include <Modes.h>
#include <ELWire.h>



class WireManager {
public:
	Mode mode;
	Wire *wires;
	WireManager();
	WireManager(Mode *activeMode);
	void allWiresOff();
	void allWiresOn();
	void wireOn(Wire otherWire);
	void wireOff(Wire otherWire);
	void setMode(Mode otherMode);
	void processMidi();
};

#endif
