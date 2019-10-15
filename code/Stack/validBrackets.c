#include "stack.h"
#include <string.h>



bool isRightChar(char c) {
    return c == ']' || c == ')' || c == '}';
}

bool matchBrackets(char right, char test) {
    if (!isRightChar(right)) {
        return false;
    }

    return (right == ']' && test == '[') || (right == ')' && test == '(') || (right == '}' && test == '{');
}

bool validBrackets(char *s) {
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
                printf("111111\r\n");
                break;
            }
            char val = top->val;
            free(top);
            if (!matchBrackets(s[i], val)) {
                result = false;
                printf("222222\r\n");
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


int main() {
    char *expression = "(((";
    bool result = validBrackets(expression);
    printf("%s\r\n", result ? "yes":"no");

    return 0;
}