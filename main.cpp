#include "MenuEntry.h"
#include "CursesDisplay.h"
#include <stdio.h>
#include <curses.h>
#include <unistd.h>

static void pp(Display* display, MenuEntry* menu[], int indent = 0);

int main(int argc, char* argv[]) {
	Display* display = new CursesDisplay(16, 2);
	
	MenuEntry* tempChilds[] = {
			new MenuEntry("Setear Temp.", NULL, NULL),
			new MenuEntry("Setear delta", NULL, NULL),
			new MenuEntry("Volver", NULL, NULL),
			NULL };

	MenuEntry* soundChilds[] = {
			new MenuEntry("Activar", NULL, NULL),
			new MenuEntry("Volumen", NULL, NULL),
			new MenuEntry("Volver", NULL, NULL),
			NULL };

	MenuEntry* timerChilds[] = {
			new MenuEntry("Setear hora", NULL, NULL),
			new MenuEntry("Iniciar", NULL, NULL),
			new MenuEntry("Sonido", NULL, soundChilds),
			new MenuEntry("Volver", NULL, NULL),
			NULL };

	MenuEntry* menu[] = {
			new MenuEntry("Reloj", NULL, NULL),
			new MenuEntry("Temperatura", NULL, tempChilds),
			new MenuEntry("Temporizador", NULL, timerChilds),
			new MenuEntry("Volver", NULL, NULL),
			NULL };

	//pp(display, menu);
	display->setCursor(0,0);
	display->print("hola");
	display->setCursor(0,1);
	display->print("mundo");
	
	getch();
	
	display->clear();
	
	char c = getch();
	
	delete display;

	printf("saliste con %d\n", c);
	
	return 0;
}

void pp(Display* display, MenuEntry* menu[], int indent) {
	int i = 0;

	char prefix[indent + 1];
	for (i = 0; i < indent; i++) {
		prefix[i] = '\t';
	}
	prefix[i] = '\0';

	i = 0;
	while (menu != NULL && menu[i] != NULL) {
		MenuEntry* entry = menu[i];
		char s[128];
		sprintf(s, "%s%s\n", prefix, entry->getTitle());
		display->print(s);
		if (entry->hasChilds()) {
			pp(display, entry->getChilds(), indent + 1);
		}
		i++;
	}
}


