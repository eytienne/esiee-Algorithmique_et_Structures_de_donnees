#ifndef CELL_H
#define CELL_H

#include <stdlib.h>

typedef struct Cell {
	void *value;
	size_t size;
} Cell;

Cell *cellcpy(Cell *dest, const Cell *src);

void freeCell(Cell *toFree);

#endif