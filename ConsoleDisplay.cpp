#include "ConsoleDisplay.h"
#include <stdio.h>

ConsoleDisplay::ConsoleDisplay() {
}

void ConsoleDisplay::clear() {
}

void ConsoleDisplay::setCursor(uint8_t, uint8_t) {
}

size_t ConsoleDisplay::print(const char str[]) {
	return printf("%s", str);
}

size_t ConsoleDisplay::print(const char ch) {
	return printf("%c", ch);
}
