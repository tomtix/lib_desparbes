#include <stdlib.h>
#include <stdio.h>

int intcmp(const void *v1, const void *v2)
{
    return *((int*)v1) - *((int*)v2);
}

int search(void *array, size_t element_size, size_t array_size, void *element, 
	   int (*compare)(const void *v1, const void *v2))
{
    int l = 0;
    int r = array_size - 1;
    int m;
    while (l <= r) {
	m = (r + l) / 2;
	int c = compare(array + m * element_size, element);
	if (c < 0)
	    l = m + 1;
	else if (c > 0)
	    r = m - 1;
	else
	    return m;
    } 
    return -1;	    
}
 
