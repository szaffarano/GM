/*
 * State.cpp
 *
 *  Created on: 09/01/2013
 *      Author: sebas
 */

#include "State.h"

State::State(MenuEntry** menu, int current, int firstVisible) {
	this->menu = menu;
	this->current = current;
	this->firstVisible = firstVisible;
}

MenuEntry** State::getMenu() {
	return this->menu;
}

int State::getCurrent() {
	return this->current;
}

int State::getFirsVisible() {
	return this->firstVisible;
}

void State::setCurrent(int current) {
	this->current = current;
}

void State::setFirstVisible(int first) {
	this->firstVisible = first;
}

State::~State() {
}

