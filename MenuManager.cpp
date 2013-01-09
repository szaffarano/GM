#include "MenuManager.h"
#include <string.h>

static void padTitle(char* buffer, const char* str, unsigned int cols);

MenuManager::MenuManager(MenuEntry** menu, Display* display) {
	this->menu = menu;
	this->display = display;

	this->firstVisibleEntry = 0;
	this->currentEntry = 0;
}

void MenuManager::draw() {
	display->clear();
	char title[display->getCols() + 1];
	for (int i = 0; i < display->getRows(); i++) {
		display->setCursor(0, i);

		padTitle(title, currentMenu()[i+firstVisibleEntry]->getTitle(), display->getCols());

		if (currentEntry == i+firstVisibleEntry) {
			title[0] = '>';
		}

		display->print(title);
	}
}

void MenuManager::execute(MenuAction action) {
}

void MenuManager::up() {
	if (currentEntry != 0) {
		currentEntry--;
	} else {
		currentEntry++;
		while(currentMenu()[currentEntry+1] != NULL) {
			++currentEntry;
		}
		firstVisibleEntry = display->getRows();
	}
	if (currentEntry < firstVisibleEntry) {
		firstVisibleEntry = currentEntry;
	}
}

void MenuManager::down() {
	if (currentMenu()[currentEntry+1] != NULL) {
		currentEntry++;
	} else {
		currentEntry = firstVisibleEntry = 0;
	}
	if(currentEntry - firstVisibleEntry  == display->getRows()) {
		firstVisibleEntry++;
	}
}

void MenuManager::select() {
	MenuEntry* current = currentMenu()[currentEntry];
	if (current->hasChilds()) {
		path.push(current);
		currentEntry = firstVisibleEntry = 0;
	}
	current->execute();
}

void MenuManager::back() {
}

MenuEntry** MenuManager::currentMenu() {
	if(path.isEmpty()) {
		return menu;
	}
	return path.peek()->getChilds();
}

MenuManager::~MenuManager() {
}

void padTitle(char buffer[], const char* str, unsigned int cols) {
	unsigned int i = 0;
	buffer[i++] = ' ';
	unsigned int size = strlen(str) > cols-1 ? cols-1 : strlen(str);
	for (; i <= size; i++) {
		buffer[i] = str[i-1];
	}
	for(; i < cols; i++) {
		buffer[i] = ' ';
	}
	buffer[i] = '\0';
}
