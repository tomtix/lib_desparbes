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
    pushStack(stack, &a);
    resetStack(stack);
    assert(voidStack(stack));
    destroyStack(stack);
}

void test_peekStack()
{
    Stack *stack = initStack(sizeof(int));
    int a = 42;
    int b = 0;

    pushStack(stack, &a);
    b = *((int *)(peekStack(stack)));
    assert(b == 42 && !voidStack(stack));
    destroyStack(stack);
}

void test_popStack()
{
    Stack *stack = initStack(sizeof(char));
    int a = 42;

    pushStack(stack, &a);
    assert(!voidStack(stack));
    popStack(stack);
    assert(voidStack(stack));
    destroyStack(stack);
}

void test_lengthStack()
{
    Stack *stack = initStack(sizeof(char));
    int a = 42;
    int b = 8;
    
    assert(lengthStack(stack) == 0);
    pushStack(stack, &a);
    assert(lengthStack(stack) == 1);
    pushStack(stack, &b);
    assert(lengthStack(stack) == 2);
    popStack(stack);
    assert(lengthStack(stack) == 1);
    popStack(stack);
    assert(lengthStack(stack) == 0);
    destroyStack(stack);
}

void test_general()
{
    Stack *stack = initStack(sizeof(int));
    int array[5] = {3, 14, 15, 9, 2};

    for (int i = 0; i < 5; i++)
	pushStack(stack, &array[i]);
    
    assert(*((int*)popStack(stack)) == 2);
    assert(*((int*)popStack(stack)) == 9);
    assert(*((int*)popStack(stack)) == 15);
    assert(*((int*)popStack(stack)) == 14);
    assert(*((int*)popStack(stack)) == 3);
    assert(voidStack(stack));
    assert(popStack(stack) == NULL);
    
    destroyStack(stack);
}

int main(int argc, char *argv[])
{
    test_voidStack();
    test_resetStack();
    test_peekStack();
    test_popStack();
    test_lengthStack();
    test_general();
    return EXIT_SUCCESS;
}
