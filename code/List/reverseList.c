/*
 * @Author: hmw 
 * @Date: 2019-09-20 11:23:36 
 * @Last Modified by: hmw
 * @Last Modified time: 2019-09-20 11:23:56
 */

/**
 *  gcc reverseList.c singleList.c -o a
 * 
 *  ./a
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "singleList.h"

int main() {
    int datas[] = {1, 2, 3, 4, 9, 9, 8, 3};

    List_t list;
    memset(&list, 0, sizeof(List_t));
    // list.head = NULL;
    for (int i = 0; i < sizeof(datas)/sizeof(int); i++) {
        Node_t *node = malloc(sizeof(Node_t));
        node->data = datas[i];
        node->next = NULL;
        // insertNode2List(node, &list);
        appendNode2List(node, &list);
    }

    showList(&list);
    reverse(&list);
    showList(&list);
    freeList(&list);

    return 0;
}

