#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue Queue;

Queue *initQueue();
void resetQueue(Queue *queue);
int voidQueue(Queue *queue);
void pushQueue(Queue *queue, void *data);
void *peekQueue(Queue *queue);
void *popQueue(Queue *queue);
int lengthQueue(Queue *queue);
void destroyQueue(Queue *queue);

#endif // QUEUE_H
