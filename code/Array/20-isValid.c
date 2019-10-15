#include  <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef enum {
    false, 
    true
} bool ;




bool isRightChar(char c) {
    return c == ']' || c == ')' || c == '}';
}

bool matchBrackets(char right, char test) {
    if (!isRightChar(right)) {
        return false;
    }

    return (right == ']' && test == '[') || (right == ')' && test == '(') || (right == '}' && test == '{');
}

bool isValid(char *s) {
    int length = strlen(s);
    char *temp = (char *)malloc(length);
    memset(temp, 0, length);
    bool result = true;

    int i = 0;
    int count = 0;
    for (i = 0; i < length; i++) {
        if (!isRightChar(s[i])) {
            temp[count] = s[i];
            count++;
        } else {
            if (count == 0) {
                result = false; 
                break;
            }

            char left = temp[count-1];
            count--;
            if (!matchBrackets(s[i], left)) {
                result = false; 
                break;
            }
        }
    }

    if (i == length && count != 0) {
        result = false; 
    }

    free(temp);
    return result;
}


int main() {
    char *expression = "(((())))(){";
    bool result = isValid(expression);
    printf("%s\r\n", result ? "yes":"no");
}