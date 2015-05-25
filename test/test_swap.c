#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "swap.h"

void test_swap()
{
    int a = 4;
    int b = 2;
    swap(&a, &b, sizeof(int));
    assert(a == 2 && b == 4);
}

int main(int argc, char *argv[])
{
    test_swap();
    return EXIT_SUCCESS;
}
