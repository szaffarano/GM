#include "Display.h"
#include <curses.h>
#include <unistd.h>

#ifndef _CONSOLE_DISPLAY_H_
#define _CONSOLE_DISPLAY_H_

class CursesDisplay: public Display {
public:
	CursesDisplay(int, int);
	void clear();
	void setCursor(uint8_t col, uint8_t row);
	void createChar(uint8_t, uint8_t[]);
	size_t print(const char[]);
	size_t print(const char);
	~CursesDisplay();
private:
	int rows;
	int cols;
};

#endif
