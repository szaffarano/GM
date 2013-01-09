#include "MenuManager.h"
#include <string.h>

static void padTitle(char* buffer, const char* str, unsigned int cols);

MenuManager::MenuManager(MenuEntry** menu, Display* display) {
	this->display = display;
	this->path = new Queue<State*>(10);

	this->path->push(new State(menu, 0, 0));
}

void MenuManager::draw() {
	display->clear();
	char title[display->getCols() + 1];

	int first = path->peek()->getFirsVisible();
	int current = path->peek()->getCurrent();
	MenuEntry** menu = path->peek()->getMenu();

	for (int i = 0; i < display->getRows(); i++) {
		if (menu[i + first] != NULL) {
			padTitle(title, menu[i + first]->getTitle(), display->getCols());

			display->setCursor(0, i);

			if (current == i + first) {
				title[0] = '>';
			}

			display->print(title);
		}
	}
}

void MenuManager::execute(MenuAction action) {
}

void MenuManager::up() {
	int first = path->peek()->getFirsVisible();
	int current = path->peek()->getCurrent();
	MenuEntry** menu = path->peek()->getMenu();

	if (current != 0) {
		current--;
	} else {
		current++;
		while (menu[current + 1] != NULL) {
			++current;
		}
		first = display->getRows();
	}
	if (current < first) {
		first = current;
	}
	path->peek()->setCurrent(current);
	path->peek()->setFirstVisible(first);
}

void MenuManager::down() {
	int first = path->peek()->getFirsVisible();
	int current = path->peek()->getCurrent();
	MenuEntry** menu = path->peek()->getMenu();

	if (menu[current + 1] != NULL) {
		current++;
	} else {
		current = first = 0;
	}
	if (current - first == display->getRows()) {
		first++;
	}
	path->peek()->setCurrent(current);
	path->peek()->setFirstVisible(first);
}

void MenuManager::select() {
	int current = path->peek()->getCurrent();
	MenuEntry** menu = path->peek()->getMenu();
	MenuEntry* currentMenu = menu[current];

	if (currentMenu->hasChilds()) {
		path->push(new State(currentMenu->getChilds(), 0, 0));
	}
	currentMenu->execute();
}

void MenuManager::back() {
	State* st = path->pop();
	if (path->isEmpty()) {
		path->push(st);
	}
}

MenuManager::~MenuManager() {
}

void padTitle(char buffer[], const char* str, unsigned int cols) {
	unsigned int i = 0;
	buffer[i++] = ' ';
	unsigned int size = strlen(str) > cols - 1 ? cols - 1 : strlen(str);
	for (; i <= size; i++) {
		buffer[i] = str[i - 1];
	}
	for (; i < cols; i++) {
		buffer[i] = ' ';
	}
	buffer[i] = '\0';
}
