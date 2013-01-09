#include "Display.h"

Display::Display(int cols, int rows) {
	this->cols = cols;
	this->rows = rows;
}

int Display::getRows() {
	return this->rows;
}

int Display::getCols() {
	return this->cols;
}
