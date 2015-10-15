#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

void test_voidStack()
{
    Stack *stack = initStack(sizeof(int));
    assert(voidStack(stack));
    destroyStack(stack);
    printf("test_voidStack successful\n");
}

void test_resetStack()
{
    Stack *stack = initStack(sizeof(int));
    int a = 42;
    addDataStack(stack, &a);
    resetStack(stack);
    assert(voidStack(stack));
    destroyStack(stack);
    printf("test_resetStack successful\n");
}

void test_readDataStack()
{
    Stack *stack = initStack(sizeof(int));
    int a = 42;
    int b = 0;

    addDataStack(stack, &a);
    b = *((int *)(readDataStack(stack)));
    assert(b == 42 && !voidStack(stack));
    destroyStack(stack);
    printf("test_readDataStack successful\n");
}

void test_removeDataStack()
{
    Stack *stack = initStack(sizeof(char));
    int a = 42;

    addDataStack(stack, &a);
    assert(!voidStack(stack));
    removeDataStack(stack);
    assert(voidStack(stack));
    destroyStack(stack);
    printf("test_removeDataStack successful\n");
}

void test_general()
{
    Stack *stack = initStack(sizeof(int));
    int a;

    for (int i = 0; i < 5; i++)
	addDataStack(stack, &i);
    
    for (int i = 4; i >= 0; i--) {
	a = *((int *) readDataStack(stack));
	assert(a == i);
	removeDataStack(stack);
    }
    destroyStack(stack);
    printf("test_general successful\n");
}

int main(int argc, char *argv[])
{
    test_voidStack();
    test_resetStack();
    test_readDataStack();
    test_removeDataStack();
    test_general();
    return EXIT_SUCCESS;
}
