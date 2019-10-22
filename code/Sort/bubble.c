#include "sort.h"

void main() {
    int datas[] = {1, 2, 3, 2, 0, 4, 5};
    int size = sizeof(datas)/sizeof(int);

    for (int i = 0; i < size; i++) {
        printf("%d ", datas[i]);
    }
    printf("\r\n");

    bubbleSort(datas, size);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", datas[i]);
    }
    printf("\r\n");
}