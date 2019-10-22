#include "queue.h"


myQueue_t *initQueue() {
    myQueue_t *queue = (myQueue_t *)malloc(sizeof(myQueue_t));
    memeset(queue, 0, sizeof(myQueue_t));

    return queue;
}

void enqueue(node_t *node, myQueue_t *queue) {
    if (!queue) {
        return;
    }

    node->next = NULL;
    if (NULL == queue->tail) {
        queue->head = node;
        queue->tail = node;
        return;
    }

    queue->tail->next = node;
    queue->tail = node;
}

node_t *dequeue(myQueue_t *queue) {
    if (!queue) {
        return NULL;
    }

    node_t *node = queue->head;
    if (queue->head) {
        queue->head = queue->head->next;
    }
    node->next = NULL; // 不要让外面访问到内部数据

    return node;
}

