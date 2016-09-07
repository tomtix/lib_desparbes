#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

typedef struct Stack{
    void **buffer;
    int length;
    int bufferSize;
}Stack;

Stack *initStack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->length = 0;
    stack->bufferSize = 4;
    stack->buffer = malloc(stack->bufferSize * sizeof(void*));
    return stack;
}

void resetStack(Stack *stack)
{
    stack->length = 0;
}   

int voidStack(Stack *stack)
{
    return (stack->length <= 0);
}

void addDataStack(Stack *stack, void* data)
{
    if(stack->length >= stack->bufferSize){
	stack->bufferSize *= 2;
	stack->buffer = realloc(stack->buffer, 
				stack->bufferSize * sizeof(void*));
    }
    stack->buffer[stack->length++] = data;
}

void *readDataStack(Stack *stack)
{
    if(stack->length <= 0){
	fprintf(stderr, "Error: peeking of a void stack.\n");
	return NULL;
    }
    return stack->buffer[stack->length - 1];
}

void *removeDataStack(Stack *stack)
{
    if(stack->length <= 0){
	fprintf(stderr, "Error: removing data from a void stack.\n");
	return NULL;
    }
    return stack->buffer[--stack->length];
}

int lengthStack(Stack *stack)
{
    return stack->length;
}

void destroyStack(Stack *stack)
{
    free(stack->buffer);
    free(stack);
}
