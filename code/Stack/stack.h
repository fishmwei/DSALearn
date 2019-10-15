#include <stdio.h>
#include <stdlib.h>

#ifndef _STACK_H_
#define _STACK_H_

typedef struct node {
    struct node *top;
    char val;
} node_t;

typedef struct stack_s
{
    node_t *top;
} myStack_t;

typedef enum {
    false, 
    true
} bool ;

myStack_t *initStack();
node_t *pop(myStack_t *stack);
void push(node_t *node, myStack_t *stack);
bool isEmpty(myStack_t *stack);
void freeStack(myStack_t *stack);

#endif