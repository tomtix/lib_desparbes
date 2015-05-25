#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

typedef struct ElementStack{
    void *data;
    struct ElementStack *next;
}ElementStack;

typedef struct Stack{
    ElementStack *first;
    int length;
    int dataSize;
}Stack;

Stack *initStack(int dataSize)
{
    if(dataSize <= 0){
	fprintf(stderr, "Error: incorrect size of data in stack.\n");
	return NULL;
    }

    Stack *stack = malloc(sizeof(Stack));

    if(stack == NULL)
	fprintf(stderr, "Error: malloc failed during stack initilization.\n");

    stack->first = NULL;
    stack->length = 0;
    stack->dataSize = dataSize;
    return stack;
}

int voidStack(Stack *stack)
{
    return (stack->length <= 0);
}

void pushStack(Stack *stack, void* data)
{
    ElementStack *newElementStack = malloc(sizeof(ElementStack));
    newElementStack->data = malloc(stack->dataSize);

    if(newElementStack == NULL || newElementStack->data == NULL){
	fprintf(stderr, "Error: malloc failed intempting pushing stack.\n");
	return;
    }

    memcpy(newElementStack->data, data, stack->dataSize);
    newElementStack->next = stack->first;
    stack->first = newElementStack;
    stack->length++;
}

void *popStack(Stack *stack)
{
    if(voidStack(stack)){
	fprintf(stderr, "Error: popping of a void stack.\n");
	return NULL;
    }
    ElementStack *destroy = stack->first;
    void* data = destroy->data;
    stack->first = destroy->next;
    stack->length--;
    free(destroy);
    return data;
}    

void *peekStack(Stack *stack)
{
    if(voidStack(stack)){
	fprintf(stderr, "Error: peeking of a void stack.\n");
	return NULL;
    }
    return stack->first->data;
}

void destroyStack(Stack *stack)
{
    ElementStack *cursor = stack->first;
    ElementStack *destroy = stack->first;
    
    while(cursor != NULL){
	cursor = cursor->next;
	free(destroy->data);
	free(destroy);
	destroy = cursor;
    }
    free(stack);
}
