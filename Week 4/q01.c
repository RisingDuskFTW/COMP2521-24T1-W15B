// Using a Stack ADT

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct queue {
	Stack s1;
	Stack s2;
};

typedef struct queue *Queue;

Queue QueueNew(void) {
	Queue q = malloc(sizeof(struct queue));
	q->s1 = StackNew();
	q->s2 = StackNew();
	return q;
}

void QueueEnqueue(Queue q, int item) {
	StackPush(q->s1, item);
}

int QueueDequeue(Queue q) {
	if (StackIsEmpty(q->s2)) {
        while (!StackIsEmpty(q->s1)) {
            StackPush(q->s2, StackPop(q->s1));
        }
    }
    return StackPop(q->s2);
}
