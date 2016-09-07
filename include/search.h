#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdlib.h>

typedef int (*compare_t)(const void*, const void*);

int intcmp(const void *v1, const void *v2);
int search(void *array, size_t element_size, size_t array_size,
           void *element, compare_t compare);

#endif //SEARCH_H
