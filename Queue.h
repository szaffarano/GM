/*
 * Queue
 *
 *  Created on: 09/01/2013
 *      Author: sebas
 */
#include "MenuEntry.h"

#ifndef QUEUE_
#define QUEUE_

/**
 * @TODO: que funcione con templates y que se redimencione automáticamente al llenarse.
 */
class Queue {
	MenuEntry* queue[20];
	int idx;
	int size;
public:
	Queue();
	void print();
	MenuEntry* push(MenuEntry* entry);
	MenuEntry* pop();
	MenuEntry* peek();
	bool isEmpty();
	bool isFull();
	~Queue();
};

#endif /* QUEUE_ */
