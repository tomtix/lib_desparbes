#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

void test_voidQueue()
{
    Queue *queue = initQueue(sizeof(int));
    assert(voidQueue(queue));
    destroyQueue(queue);
}

void test_resetQueue()
{
    Queue *queue = initQueue(sizeof(int));
    int a = 42;
    pushQueue(queue, &a);
    resetQueue(queue);
    assert(voidQueue(queue));
    destroyQueue(queue);
}

void test_peekQueue()
{
    Queue *queue = initQueue(sizeof(int));
    int a = 42;
    int b = 8;
    int c = 0;

    pushQueue(queue, &a);
    pushQueue(queue, &b);
    c = *((int *)(peekQueue(queue)));
    assert(c == 42 && !voidQueue(queue));
    destroyQueue(queue);
}

void test_popQueue()
{
    Queue *queue = initQueue(sizeof(char));
    int a = 42;
    int b = 8;
    int c = 0;

    pushQueue(queue, &a);
    pushQueue(queue, &b);
    assert(!voidQueue(queue));
    c = *((int *)(popQueue(queue)));
    assert(c == 42 && !voidQueue(queue));
    c = *((int *)(popQueue(queue)));
    assert(c == 8 && voidQueue(queue));
    destroyQueue(queue);
}

void test_lengthQueue()
{
    Queue *queue = initQueue(sizeof(char));
    int a = 42;
    int b = 8;

    assert(lengthQueue(queue) == 0);
    pushQueue(queue, &a);
    assert(lengthQueue(queue) == 1);
    pushQueue(queue, &b);
    assert(lengthQueue(queue) == 2);
    popQueue(queue);
    assert(lengthQueue(queue) == 1);
    popQueue(queue);
    assert(lengthQueue(queue) == 0);
    destroyQueue(queue);
}

void test_general()
{
    Queue *queue = initQueue(sizeof(int));
    int array[5] = {3, 14, 15, 9, 2};

    for (int i = 0; i < 5; i++)
        pushQueue(queue, &array[i]);

    assert(*((int*)popQueue(queue)) == 3);
    assert(*((int*)popQueue(queue)) == 14);
    assert(*((int*)popQueue(queue)) == 15);
    assert(*((int*)popQueue(queue)) == 9);
    assert(*((int*)popQueue(queue)) == 2);
    assert(voidQueue(queue));
    assert(popQueue(queue) == NULL);

    destroyQueue(queue);
}

int main(int argc, char *argv[])
{
    test_voidQueue();
    test_resetQueue();
    test_peekQueue();
    test_popQueue();
    test_lengthQueue();
    test_general();
    return EXIT_SUCCESS;
}
