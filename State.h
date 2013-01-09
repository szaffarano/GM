/*
 * State.h
 *
 *  Created on: 09/01/2013
 *      Author: sebas
 */

#include "MenuEntry.h"

#ifndef STATE_H_
#define STATE_H_

class State {
	MenuEntry** menu;
	int current;
	int firstVisible;
public:
	State(MenuEntry** menu, int current, int firstVisible);
	MenuEntry** getMenu();
	int getCurrent();
	int getFirsVisible();
	void setCurrent(int current);
	void setFirstVisible(int first);
	virtual ~State();
};

#endif /* STATE_H_ */
