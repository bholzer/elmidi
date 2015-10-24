#ifndef Wire_h
#define Wire_h

#include "Arduino.h"

class Wire {
public:
	uint8_t pin;
	int *notes;
	byte state;
	Wire(uint8_t pin, int *notes, byte state);
	void update();
	void activate();
	void deactivate();
};

#endif