/*
 * @Author: hmw 
 * @Date: 2019-09-20 11:23:36 
 * @Last Modified by: hmw
 * @Last Modified time: 2019-09-20 11:23:56
 */

/**
 *  获取单链表的中间结点， 
 *  快慢指针
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "singleList.h"

Node_t *getMiddleNode(List_t *list) {
    if (!list || !list->head) {
        return NULL;
    }

    Node_t *slowNode = list->head;
    Node_t *quickNode = list->head;

    while (quickNode->next && quickNode->next->next) {
        quickNode = quickNode->next->next;
        slowNode = slowNode->next;
    }

    // while (1) {
    //     Node_t *next = quickNode->next;
    //     if (!next || !next->next) {
    //         break;
    //     }

    //     quickNode = next->next;
    //     slowNode = slowNode->next;
    // }

    return slowNode;
}

int main() {
    int datas[] = {1, 2, 3, 9, 8, 7};

    List_t list;
    memset(&list, 0, sizeof(List_t));

    for (int i = 0; i < sizeof(datas)/sizeof(int); i++) {
        Node_t *node = malloc(sizeof(Node_t));
        node->data = datas[i];
        node->next = NULL;
        appendNode2List(node, &list);
    }

    Node_t *middleNode = getMiddleNode(&list);
    if (!middleNode) {
        printf("can not find middle node.\r\n");
    } else {
        printf("middle node data is %d\r\n", middleNode->data);
    }
    freeList(&list);

    return 0;
}

