#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

Stack *initStack();
void resetStack(Stack *stack);
int voidStack(Stack *stack);
void pushStack(Stack *stack, void *data);
void *peekStack(Stack *stack);
void *popStack(Stack *stack);
int lengthStack(Stack *stack);
void destroyStack(Stack *stack);

#endif // STACK_H
