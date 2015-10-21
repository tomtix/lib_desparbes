#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

typedef struct Queue{
    void **buffer;
    int head;
    int tail;
    int bufferSize;
}Queue;

Queue *initQueue()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->head = 0;
    queue->tail = 0;
    queue->bufferSize = 4;
    queue->buffer = malloc(queue->bufferSize * sizeof(void*));
    return queue;
}

void resetQueue(Queue *queue)
{
    queue->head = 0;
    queue->tail = 0;
}   

int voidQueue(Queue *queue)
{
    return (queue->head == queue->tail);
}

void pushQueue(Queue *queue, void* data)
{
    if((queue->head + 1) % queue->bufferSize == queue->tail){
	queue->bufferSize *= 2;
	queue->buffer = realloc(queue->buffer, 
				queue->bufferSize * sizeof(void*));
    }
    queue->buffer[queue->head] = data;
    queue->head = (queue->head + 1) % queue->bufferSize;
}

void *peekQueue(Queue *queue)
{
    if(queue->head == queue->tail){
	fprintf(stderr, "Error: peeking of a void queue.\n");
	return NULL;
    }
    return queue->buffer[queue->tail];
}

void *popQueue(Queue *queue)
{
    if(queue->head == queue->tail){
	fprintf(stderr, "Error: removing data from a void queue.\n");
	return NULL;
    }
    return queue->buffer[queue->tail++];
}

int lengthQueue(Queue *queue)
{
    return (queue->head - queue->tail) % queue->bufferSize;
}

void destroyQueue(Queue *queue)
{
    free(queue->buffer);
    free(queue);
}
