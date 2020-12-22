#ifndef QUEUE_h
#define QUEUE_h
#include "LinkedList.h"
#include <stdbool.h>

typedef struct Queue* Queue;

Queue       QueueCreate(Element (*cpy)(Element), void (*fre)(Element));
void        QueueDestroy(Queue);
void        QueueEnqueue(Queue, Element);
Element     QueueDequeue(Queue);
bool        QueueIsEmpty(Queue);

#endif
