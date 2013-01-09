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
 * El por qué no se puede separar .h de .cpp :(
 *
 * @see http://www.parashift.com/c++-faq-lite/separate-template-fn-defn-from-decl.html
 */
template<class T>
class Queue {
	T* queue;
	int idx;
	int size;
public:
	Queue(int size) {
		queue = new T[size];
		for (int i = 0; i < size; i++) {
			queue[i] = NULL;
		}
		idx = -1;
		this->size = size;
	}
	T push(T entry) {
		if (isFull()) {
			return NULL;
		}

		queue[++idx] = entry;

		return queue[idx - 1];
	}
	T pop() {
		if (isEmpty()) {
			return NULL;
		}
		T entry = queue[idx];
		queue[idx--] = NULL;
		return entry;
	}
	T peek() {
		if (isEmpty()) {
			return NULL;
		}
		return queue[idx];
	}
	bool isEmpty() {
		return idx == -1;
	}
	bool isFull() {
		return idx == size - 1;
	}
	~Queue() {
		delete[] queue;
	}
};

#endif /* QUEUE_ */
