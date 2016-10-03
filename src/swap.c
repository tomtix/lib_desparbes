#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "swap.h"

void swap(void *x, void *y, int dataSize)
{
    void *temp = malloc(dataSize);

    if(temp == NULL){
        fprintf(stderr, "Error: malloc failed trying to swap two elements.\n");
        return;
    }

    memcpy(temp, x, dataSize);
    memcpy(x, y, dataSize);
    memcpy(y, temp, dataSize);

    free(temp);
}

