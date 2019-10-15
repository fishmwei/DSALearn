#include "stack.h"

myStack_t *initStack() {
    myStack_t *s = (myStack_t *)malloc(sizeof(myStack_t));
    s->top = NULL;
    return s;
}

node_t *pop(myStack_t *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }

    node_t *temp = stack->top;
    stack->top = temp->top;
    temp->top = NULL;

    return temp;
}

void push(node_t *node, myStack_t *stack) {
    node->top = stack->top;
    stack->top = node;
}

bool isEmpty(myStack_t *stack) {
    return NULL == stack || NULL == stack->top;
}

void freeStack(myStack_t *stack) {
    while (!isEmpty(stack)) {
        node_t *temp = pop(stack);
        free(temp);
    }

    free(stack);
}