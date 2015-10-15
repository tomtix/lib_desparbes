#include <stdio.h>
#include <stdlib.h>

int intcmp(const void *v1, const void *v2);
int search(void *array, size_t element_size, size_t array_size, void *element, 
	   int (*compare)(const void *v1, const void *v2));
