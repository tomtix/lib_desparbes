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

void test_popStack()
{
    Stack *stack = initStack(sizeof(int));
    int a = 42;
    int b = 0;

    pushStack(stack, &a);
    b = *((int *)(popStack(stack)));
    assert(b == 42 && !voidStack(stack));
    destroyStack(stack);
}

void test_peekStack()
{
    Stack *stack = initStack(sizeof(int));
    int a = 42;
    int b = 0;

    pushStack(stack, &a);
    b = *((int *)(popStack(stack)));
    assert(b == 42 && voidStack(stack));
    destroyStack(stack);
}

int main(int argc, char *argv[])
{
    test_voidStack();
    test_popStack();
    test_peekStack();
    return EXIT_SUCCESS;
}
