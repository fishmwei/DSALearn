typedef struct node {
    struct node *top;
    char val;
} node_t;

typedef struct stack_s
{
    node_t *top;
} myStack_t;

myStack_t *initStack() {
    myStack_t *s = (myStack_t *)malloc(sizeof(myStack_t));
    s->top = NULL;
    return s;
}

bool isEmpty(myStack_t *stack) {
    return NULL == stack || NULL == stack->top;
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



void freeStack(myStack_t *stack) {
    while (!isEmpty(stack)) {
        node_t *temp = pop(stack);
        free(temp);
    }

    free(stack);
}


bool isRightChar(char c) {
    return c == ']' || c == ')' || c == '}';
}

bool matchBrackets(char right, char test) {
    if (!isRightChar(right)) {
        return false;
    }

    return (right == ']' && test == '[') || (right == ')' && test == '(') || (right == '}' && test == '{');
}
 

bool isValid(char * s){
int length = strlen(s);
    int result = true;
    myStack_t *stack = initStack();

    int i = 0;
    for (; i < length; i++) {
        if (!isRightChar(s[i])) {
            node_t *temp = (node_t *)malloc(sizeof(node_t));
            temp->val = s[i];
            temp->top = NULL;
            push(temp, stack);
        } else {
            node_t *top = pop(stack);
            if (!top) {
                result = false; 
                break;
            }
            char val = top->val;
            free(top);
            if (!matchBrackets(s[i], val)) {
                result = false; 
                break;
            }
        }
    }

    if (!isEmpty(stack) && i == length) {
        result = false;
    }

    free(stack);

    return result;
}

