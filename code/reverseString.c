#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverseString(char *originStr) {
    if (originStr == NULL) {
        return originStr;
    }

    int len = strlen(originStr);
    if (len <= 1) {
        return originStr;
    }
    // return originStr;

    char *temp = malloc(len+1);
    for (int i = len-1; i >=0; i--) {
        int j = len - 1 - i;
        temp[j] = originStr[i];
    }

    temp[len] = 0;
    strcpy(originStr,temp);
    free(temp);

    return originStr;
}

// 大端模式 高字节低地址、 小端模式 低字节低地址
int isSmallEndian() {
    short int a = 0x0100;
    unsigned char *b = (void *)&a;
 
    return (int)b[0] == 0; // 低位在前
}

int main() {
    char originStr[20] = "";
    strcpy(originStr, "abcdefg");

    printf("reverse is %s\r\n",   reverseString(originStr));
    printf("isSmallEndian %s\r\n", isSmallEndian() ? "Yes": "No");
    return 0;
}