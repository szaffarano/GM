#include "MenuEntry.h"
#include <stdio.h>
#include <string.h>

MenuEntry::MenuEntry(const char* title, MenuEntry** childs) {
	this->title = title;
	this->childs = childs;
}

MenuEntry::MenuEntry(const char* title, Callback callback, void* data) {
	this->title = title;
	this->callback = callback;
	this->data = data;
}

bool MenuEntry::hasChilds() {
	return this->childs != NULL;
}

const char* MenuEntry::getTitle() {
	return title;
}

void MenuEntry::execute() {
	if (callback != NULL) {
		callback(data);
	}
}

void MenuEntry::setCallbackData(void* data) {
	this->data = data;
}

MenuEntry** MenuEntry::getChilds() {
	return this->childs;
}

MenuEntry::~MenuEntry() {
}
