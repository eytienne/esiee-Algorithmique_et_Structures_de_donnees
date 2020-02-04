#include "../lib/vector.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define GREEN_BG "\x1b[42m"
#define CUSTOM_FG "\x1b[97m"
#define COLOR_RESET "\x1b[0m"

int test();
int demo();

void printVector(Vector *v);
void printVectorWithChars(Vector *v);

int main(int argc, char const *argv[]) { return test(); }

int test() {
	Vector *v = (Vector *)malloc(sizeof(Vector));

	create(v);
	printVector(v);
	assert(v->values != NULL);
	assert(capacity(v) == 10);
	assert(size(v) == 0);
	assert(v->increment == 3);

	destroy(v);
	printVector(v);
	assert(v->values == NULL);
	assert(capacity(v) == 0);
	assert(size(v) == 0);

	create_expert(v, 5, 4);
	printVector(v);
	assert(v->values != NULL);
	assert(capacity(v) == 5);
	assert(size(v) == 0);
	assert(v->increment == 4);

	for (int i = 1; i <= 5; i++)
		add(v, &i, sizeof(i));
	printVector(v);
	assert(*(int *)get(v, size(v) - 1) == 5);
	assert(size(v) == 5);
	assert(capacity(v) == 5);

	delete (v, 0, 3);
	printVector(v);
	assert(size(v) == 2);
	assert(capacity(v) == 5);

	int removed = *(int *)removeFromVectorAtIndex(v, size(v) - 1);
	printVector(v);
	assert(*(int *)get(v, size(v) - 1) == 4);
	assert(removed == 5);
	assert(size(v) == 1);
	assert(capacity(v) == 1);

	int a = 11;
	int b = 11;
	int c = 11;
	add(v, &a, sizeof(a));
	add(v, &b, sizeof(b));
	add(v, &c, sizeof(c));
	printVector(v);
	assert(size(v) == 4);
	assert(capacity(v) == 5);

	adjust(v);
	printVector(v);
	assert(size(v) == 4);
	assert(capacity(v) == 4);

	a = 10;
	set(v, 0, &a, sizeof(a));
	printVector(v);
	assert(*(int *)get(v, 0) == 10);

	int *getRef = (int *)get(v, 0);
	assert(*getRef == 10);
	*getRef = 7;
	printVector(v);
	getRef = (int *)get(v, 0);
	assert(*getRef == 10);

	free(v);
	v = NULL;

	printf("\n" GREEN_BG CUSTOM_FG "All the tests passed !" COLOR_RESET "\n");
	return 0;
}

int demo() {
	Vector *v = (Vector *)malloc(sizeof(Vector));
	create(v);

	int i = 35;
	add(v, &i, sizeof(int));

	char *cc = "c";
	add(v, cc, sizeof(char));
	printVectorWithChars(v);

	char *cc2 = "wesh";
	set(v, 1, cc2, sizeof(char));
	printVectorWithChars(v);

	free(v);
	v = NULL;

	return 0;
}

void printVector(Vector *v) {
	printf("Vector (size : %d, capacity : %d): \n", v->size, v->capacity);
	for (int i = 0; i < size(v); i++)
		printf("%d\n", *(int *)get(v, i));
}

void printVectorWithChars(Vector *v) {
	printf("Vector (size : %d, capacity : %d): \n", v->size, v->capacity);
	for (int i = 0; i < size(v); i++) {
		Cell *c = getCell(v, i);
		switch (c->size) {
		case 1:
			printf("%s\n", (char *)c->value);
			break;
		case 2:
			printf("%hd\n", *(short *)c->value);
			break;
		case 4:
			printf("%d\n", *(int *)c->value);
			break;
		case 8:
			printf("%ld\n", *(long *)c->value);
			break;
		default:
			fprintf(stderr, "Value cannot be printed!");
			break;
		}
	}
}