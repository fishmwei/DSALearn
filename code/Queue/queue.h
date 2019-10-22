
#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    struct node_s *next;
    int val;
} node_t;

typedef struct queue_s {
    node_t *head;
    node_t *tail;
    int count;
} myQueue_t;

myQueue_t *initQueue();
void enqueue(node_t *node, myQueue_t *queue);
node_t *dequeue(myQueue_t *queue);

