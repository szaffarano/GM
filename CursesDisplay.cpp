#ifdef TEST

#include "CursesDisplay.h"
#include <stdio.h>

static void fill(char* arr, int size, char value);
static void nextFrame();

CursesDisplay::CursesDisplay(int cols, int rows): Display(cols, rows) {
	initscr();

	noecho();

	curs_set(0);

	char line[cols];
	fill(line, cols, '-');
	move(0,1);
	printw(line);
	move(rows+1, 1);
	printw(line);

	int i = 0;
	while (i < rows) {
		mvaddch(++i, 0, '|');
		mvaddch(i, cols+1, '|');
	}

	move (1,1);
	nextFrame();
}

void CursesDisplay::clear() {
	char line[cols];
	fill(line, cols, ' ');
	for (int i = 0; i < rows; i++) {
		move(i+1,1);
		printw(line);
	}
}

void CursesDisplay::setCursor(uint8_t col, uint8_t row) {
	move(row+1, col+1);
}

size_t CursesDisplay::print(const char str[]) {
	return printw("%s", str);
}

size_t CursesDisplay::print(const char ch) {
	return printw("%c", ch);
}

CursesDisplay::~CursesDisplay() {
	endwin();
}

void nextFrame() {
	refresh();
	usleep(1024*16);
}

void fill(char* arr, int size, char value) {
	int i = 0;
	for (; i < size; i++) {
		arr[i] = value;
	}
	arr[i] = '\0';
}

#endif // TEST
