#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

void test_voidStack()
{
    Stack *stack = initStack(sizeof(int));
    assert(voidStack(stack));
    destroyStack(stack);
}

void test_resetStack()
{
    Stack *stack = initStack(sizeof(int));
    int a = 42;
    addDataStack(stack, &a);
    resetStack(stack);
    assert(voidStack(stack));
    destroyStack(stack);
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
}

void test_lengthStack()
{
    Stack *stack = initStack(sizeof(char));
    int a = 42;
    int b = 8;
    
    assert(lengthStack(stack) == 0);
    addDataStack(stack, &a);
    assert(lengthStack(stack) == 1);
    addDataStack(stack, &b);
    assert(lengthStack(stack) == 2);
    removeDataStack(stack);
    assert(lengthStack(stack) == 1);
    removeDataStack(stack);
    assert(lengthStack(stack) == 0);
    destroyStack(stack);
}

void test_general()
{
    Stack *stack = initStack(sizeof(int));
    int array[5] = {3, 14, 15, 9, 2};

    for (int i = 0; i < 5; i++)
	addDataStack(stack, &array[i]);
    
    assert(*((int*)removeDataStack(stack)) == 2);
    assert(*((int*)removeDataStack(stack)) == 9);
    assert(*((int*)removeDataStack(stack)) == 15);
    assert(*((int*)removeDataStack(stack)) == 14);
    assert(*((int*)removeDataStack(stack)) == 3);
    assert(voidStack(stack));
    assert(removeDataStack(stack) == NULL);
    
    destroyStack(stack);
}

int main(int argc, char *argv[])
{
    test_voidStack();
    test_resetStack();
    test_readDataStack();
    test_removeDataStack();
    test_lengthStack();
    test_general();
    return EXIT_SUCCESS;
}
