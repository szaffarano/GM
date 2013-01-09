#include <stdio.h>

#ifndef _MENU_ENTRY_H_
#define _MENU_ENTRY_H_

typedef void (*Callback)(void* data);

class MenuEntry {
public:
	MenuEntry(const char* title, MenuEntry** childs);
	MenuEntry(const char* title, Callback callback, void* data);
	bool hasChilds();
	const char* getTitle();
	void execute();
	void setCallbackData(void* data);
	MenuEntry** getChilds();
	~MenuEntry();
private:
	char* title;
	void* data;
	Callback callback;
	MenuEntry** childs;
};

#endif
