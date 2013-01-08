#include "Display.h"

#ifndef _CONSOLE_DISPLAY_H_
#define _CONSOLE_DISPLAY_H_

class ConsoleDisplay: public Display {
public:
	ConsoleDisplay();
	void clear();
	void setCursor(uint8_t, uint8_t);
	void createChar(uint8_t, uint8_t[]);
	size_t print(const char[]);
	size_t print(const char);
	~ConsoleDisplay() {
	}
	;
};

#endif
