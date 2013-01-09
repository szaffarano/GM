/*
 * MenuManager.h
 *
 *  Created on: 08/01/2013
 *      Author: sebas
 */

#ifndef MENUMANAGER_H_
#define MENUMANAGER_H_

#include "MenuEntry.h"
#include "Display.h"
#include "Queue.h"

enum MenuAction {
	UP, DOWN, SELECT, BACK
};

class MenuManager {
public:
	MenuManager(MenuEntry** menu, Display* display);
	void draw();
	void execute(MenuAction action);
	void up();
	void down();
	void select();
	void back();
	~MenuManager();
private:
	MenuEntry** menu;
	Display* display;
	int firstVisibleEntry;
	int currentEntry;
	Queue path;
	MenuEntry** currentMenu();
};

#endif /* MENUMANAGER_H_ */
