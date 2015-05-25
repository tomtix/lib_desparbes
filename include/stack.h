#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

Stack * initStack(int dataSize);
int voidStack(Stack *stack);
void pushStack(Stack *stack, void *data);
void *popStack(Stack *stack);
void *peekStack(Stack *stack);
void destroyStack(Stack *stack);

#endif // STACK_H
