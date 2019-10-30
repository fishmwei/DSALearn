#include "sort.h"

void  callback_init () __attribute__((constructor));

 void  callback_init() {
    printf("before main %s\r\n", __func__);
}

int main() {
    printf("\r\nstart %s\r\n", __func__);

    int datas[] = {1, 2, 3, 2, 0, 4, 5};
    int size = sizeof(datas)/sizeof(int);

    for (int i = 0; i < size; i++) {
        printf("%d ", datas[i]);
    }
    printf("\r\n");

    selectSort(datas, size);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", datas[i]);
    }
    printf("\r\nend %s\r\n", __func__);

    return 0;
}


