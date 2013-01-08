#include "MenuEntry.h"

MenuEntry::MenuEntry(const char* title, Callback callback, MenuEntry** childs) {
	this->title = title;
	this->callback = callback;
	this->childs = childs;
}

MenuEntry::MenuEntry(const char* title, MenuEntry** childs) {
	MenuEntry(title, NULL, childs);
}

MenuEntry::MenuEntry(const char* title, Callback callback) {
	MenuEntry(title, callback, new MenuEntry[0]);
}

bool MenuEntry::hasChilds() {
	return this->childs != NULL;
}

const char* MenuEntry::getTitle() {
	return this->title;
}

Callback MenuEntry::getCallback() {
	return this->callback;
}

MenuEntry** MenuEntry::getChilds() {
	return this->childs;
}

MenuEntry::~MenuEntry() {
}
