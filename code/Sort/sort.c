#include "sort.h"

void bubbleSort(int *datas, int size) {
    if (!datas || size <= 1) {
        return;
    }

    for (int i = 0; i < size; i++) {

        // for (int i = 0; i < size; i++) {
        //     printf("%d ", datas[i]);
        // }
        // printf(" (i = %d)\r\n", i);

        bool flag = false;
        // 每次排序，最后一个
        for (int j = 0; j < size - i - 1; j++) {
            if (datas[j] > datas[j+1]) {
                int temp = datas[j];
                datas[j] = datas[j+1];
                datas[j+1] = temp;
                flag = true;
            }
        }
        if (!flag) {
            // printf("finish in i = %d\r\n", i);
            break;
        }
    }
}

