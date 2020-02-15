#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct LLCell {
	void *value;
	struct LLCell *previous, *next;
} LLCell;

typedef struct LinkedList {
    LLCell* first;
    LLCell *last;
    size_t sizeofEach;
} LinkedList;

LinkedList *newLinkedList(size_t sizeofEach);

void freeLinkedList(LinkedList *l, void (*freeValue)(void *value));

void addToLinkedList(LinkedList *l, void *e);

int isEmpty(const LinkedList *l);

#endif