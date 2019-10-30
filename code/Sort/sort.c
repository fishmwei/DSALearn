#include "sort.h"

void bubbleSort(int *datas, int size) {
    if (!datas || size <= 1) {
        return;
    }

    // 排序size个元素
    for (int i = 0; i < size; i++) {
        bool flag = false;
        // 每次排序，比较相邻的元素，比较交换  每一次循环， 最大的值跑到后面去了
        for (int j = 0; j < size - i - 1; j++) {
            if (datas[j] > datas[j+1]) {
                int temp = datas[j];
                datas[j] = datas[j+1];
                datas[j+1] = temp;
                flag = true;
            }
        }

        if (!flag) {
            break;
        }
    }
}


void insertionSort(int *datas, int size) {
    if (size <= 1) {
        return;
    }

    // 遍历size-1次, 把i插入到前面去
    for (int i = 1; i < size; ++i) {
        int value = datas[i];
        int j = i - 1;

        for (; j >= 0; j--) {
            // 从后往前比较， 需要移动就移动， 不需要移动就跳出
            if (datas[j] > value) {
                datas[j + 1] = datas[j];
            } else {
                break;
            }
        }

        datas[j + 1] = value;
    }
}

void selectSort(int *datas, int size) {
    if (size <= 1) {
        return;
    }

    // 最后一个不会比较了， 比较size-1次
    for (int i = 0; i < size - 1; i++) {
        // printf("time %ld :", i);
        // for (int m = 0; m < size; m++) {
        //     printf("%ld ", datas[m]);
        // }
        // printf("\r\n");

        int minIndex = i;
        int min = datas[i];
        for (int j = i + 1; j < size; j++) {
            if (min > datas[j]) {
                min = datas[j];
                minIndex = j;
            }
        }

        int temp = datas[i];
        datas[i] = datas[minIndex];
        datas[minIndex] = temp;
    }
}