#ifdef TEST

#include "MenuEntry.h"
#include "CursesDisplay.h"
#include "MenuManager.h"
#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include "Queue.h"

#define UP 65
#define DOWN 66
#define SELECT 10
#define BACK 127

static void back(void* data);

int main(int argc, char* argv[]) {
	Display* display = new CursesDisplay(16, 2);
	MenuEntry* backEntry = new MenuEntry("Volver", back, NULL);

	MenuEntry* setTempChilds[] = {
			new MenuEntry("Maxima", NULL),
			new MenuEntry("Minima", NULL),
			backEntry,
			NULL };

	MenuEntry* tempChilds[] = {
			new MenuEntry("Setear Temp.", setTempChilds),
			new MenuEntry("Setear delta", NULL),
			backEntry,
			NULL };

	MenuEntry* soundChilds[] = {
			new MenuEntry("Activar", NULL),
			new MenuEntry("Volumen", NULL),
			backEntry,
			NULL };

	MenuEntry* timerChilds[] = {
			new MenuEntry("Setear hora", NULL),
			new MenuEntry("Iniciar", NULL),
			new MenuEntry("Sonido", soundChilds),
			backEntry,
			NULL };

	MenuEntry* menu[] = {
			new MenuEntry("Reloj", NULL),
			new MenuEntry("Temperatura", tempChilds),
			new MenuEntry("Temporizador", timerChilds),
			backEntry,
			NULL };
	MenuManager* mm = new MenuManager(menu, display);
	backEntry->setCallbackData(mm);

	mm->draw();

	char pressed = 0;
	while (pressed != 'q') {
		pressed = getch();
		switch (pressed) {
		case UP:
			mm->up();
			break;
		case DOWN:
			mm->down();
			break;
		case SELECT:
			mm->select();
			break;
		case BACK:
			mm->back();
			break;
		}
		mm->draw();
	}

	delete mm;
	delete display;

	return 0;
}

void back(void* data) {
	((MenuManager*) data)->back();
	((MenuManager*) data)->draw();
}

#endif // TEST
