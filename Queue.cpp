#include "Queue.h"
#include "MenuEntry.h"
#include <stdio.h>

Queue::Queue() {
	for (int i = 0; i < size; i++) {
		queue[i] = NULL;
	}
	idx = -1;
	this->size = 10;
}

void Queue::print() {
	int i = 0;
	while(queue[i] != NULL) {
		printf("queue[%d] = %s\n", i, queue[i]->getTitle());
		i++;
	}
}

MenuEntry* Queue::push(MenuEntry* entry) {
	if(isFull()) {
		return NULL;
	}

	queue[++idx] = entry;

	return queue[idx-1];
}

MenuEntry* Queue::pop() {
	if(isEmpty()) {
		return NULL;
	}
	MenuEntry* entry = queue[idx];
	queue[idx--] = NULL;
	return entry;
}

MenuEntry* Queue::peek() {
	if(isEmpty()) {
		return NULL;
	}
	return queue[idx];
}

bool Queue::isEmpty() {
	return idx == -1;
}

bool Queue::isFull() {
	return idx == size-1;
}

Queue::~Queue() {
//	delete[] queue;
}

