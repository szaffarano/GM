#ifdef TEST
// para ejecutar tests de la lógica del menu uso main.cpp, al compilar
// para arquitectura no avr, necesito incluir librerías que no existen
// en el ambiente de AVR/Arduino
#include <stdio.h>
typedef int uint8_t;
#else
#include <Arduino.h>
#endif

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

class Display {
public:
	virtual void clear() = 0;
	virtual void setCursor(uint8_t, uint8_t) = 0;
	virtual size_t print(const char[]) = 0;
	virtual size_t print(char) = 0;
	virtual ~Display() {
	}
};

#endif
