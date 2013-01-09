#include "MenuManager.h"
#include <string.h>

MenuManager::MenuManager(MenuEntry** menu, Display* display) {
	this->menu = menu;
	this->display = display;
	
	this->selected = 0;
}

void MenuManager::draw() {
	for (int i = 0; i < display->getRows(); i++) {
		display->setCursor(0, i);
		char title[display->getCols()+1];
		int j = 0, idx = 0;
		
		for (int k = 0; k < display->getCols()+1; k++) {
			title[k] = ' ';
		}
		title[display->getCols()] = '\0';
		
		if (selected == i) {
			title[j++] = '[';
			title[display->getCols()-1] = ']';
		}
		
		
		for (; idx < strlen(menu[i]->getTitle()); idx++) {
			title[j++] = menu[i]->getTitle()[idx]; 
		}
		
		display->print(title);
	}
}

void MenuManager::execute(MenuAction action) {
}

void MenuManager::up() {
	selected--;
}

void MenuManager::down() {
	selected++;
}

void MenuManager::select() {
}

void MenuManager::back() {
}

MenuManager::~MenuManager() {
}
