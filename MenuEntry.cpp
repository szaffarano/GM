#include "MenuEntry.h"
#include <stdio.h>
#include <string.h>

MenuEntry::MenuEntry(const char* title, MenuEntry** childs) {
	this->title = new char[strlen(title)];
	for(unsigned int i = 0; i < strlen(title); i++) {
		this->title[i] = title[i];
	}
	this->childs = childs;
}

MenuEntry::MenuEntry(const char* title, Callback callback, void* data) {
	this->title = new char[strlen(title)];
	for(unsigned int i = 0; i < strlen(title); i++) {
		this->title[i] = title[i];
	}
	this->callback = callback;
	this->data = data;
}

bool MenuEntry::hasChilds() {
	return this->childs != NULL;
}

const char* MenuEntry::getTitle() {
	return this->title;
}

void MenuEntry::execute() {
	if(callback != NULL) {
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
