#include <stdio.h>

#ifndef _MENU_ENTRY_H_
#define _MENU_ENTRY_H_

typedef void (*Callback)(char * title, void* pUserData);

class MenuEntry {
public:
	MenuEntry(const char* title, Callback callback, MenuEntry** childs);
	MenuEntry(const char* title, MenuEntry** childs);
	MenuEntry(const char* title, Callback callback);
	bool hasChilds();
	const char* getTitle();
	Callback getCallback();
	MenuEntry** getChilds();
	~MenuEntry();
private:
	const char* title;
	Callback callback;
	MenuEntry** childs;
};

#endif
