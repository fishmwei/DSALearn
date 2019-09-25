/*
 * @Author: hmw 
 * @Date: 2019-09-20 11:23:36 
 * @Last Modified by: hmw
 * @Last Modified time: 2019-09-20 11:23:56
 */

/**
 *  检查链表中是否有环 
 *  快慢指针， 直到相等 或者一个为NULL
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "singleList.h"

typedef enum {
    false = 0,
    true = 1     
} myBool;

myBool hasCicleInList(List_t *list) {
    myBool result = false;
    Node_t *slowNode = list->head;
    Node_t *quickNode = list->head;
    while (quickNode->next && quickNode->next->next)
    {
        quickNode = quickNode->next->next;
        slowNode = slowNode->next;
        if (slowNode == quickNode) {
            result = true;
            break;
        }
    }
    
    return result;
}

int main() {
    int datas[] = {1, 2, 3, 9, 8, 7};

    List_t list;
    memset(&list, 0, sizeof(List_t));

    int count = sizeof(datas)/sizeof(int);
    for (int i = 0; i < count; i++) {
        Node_t *node = malloc(sizeof(Node_t));
        node->data = datas[i];
        node->next = NULL;
        appendNode2List(node, &list);
        // if (i == count - 1) {
        //     node->next = list.head;
        // }
    }

    myBool result = hasCicleInList(&list);

    // Node_t *middleNode = getMiddleNode(&list);
    if (result == true) {
        printf("has circle.\r\n");
    } else {
        printf("does not has circle\r\n");
    }
    freeList(&list);

    return 0;
}

