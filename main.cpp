#include "MenuEntry.h"
#include "ConsoleDisplay.h"
#include <stdio.h>

void pp(MenuEntry* menu[], int indent = 0);

int main(int argc, char* argv[]) {
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

	pp(menu);

	return 0;
}

void pp(MenuEntry* menu[], int indent) {
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
		ConsoleDisplay().print(s);
		if (entry->hasChilds()) {
			pp(entry->getChilds(), indent + 1);
		}
		i++;
	}
}
