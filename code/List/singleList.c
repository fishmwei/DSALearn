#include "singleList.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

List_t *reverse(List_t *list) {
    if (list == NULL) {
        return list;
    }

    Node_t *pos = list->head;
    if (pos == NULL) {
        return list;
    }

    Node_t *next = pos->next;
    Node_t *tail = list->tail;
    pos->next = NULL;
    while (next != NULL) {
        Node_t *temp = next;
        next = next->next;
        temp->next = pos;
        pos = temp;
        tail = temp;
    }

    list->head = pos;
    list->tail = tail;

    return list;
}



void showList(List_t *list) {
    if (NULL == list || list->head == NULL) {
        printf("list is empty.\r\n");
        return;
    }

    printf("list nodes:\r\n");
    Node_t *pos = list->head;
    while (pos != NULL) {
        printf("%d ", pos->data);
        pos = pos->next;
    }
    printf("\r\n");
}

// 插入头部
void insertNode2List(Node_t *node, List_t *list) {
    
    if (!list || !node) {
        return;
    }

    printf("insert %d\r\n", node->data);
    if (!list->head) {
        list->head = node;
        list->tail = node;
        return;
    }

    Node_t *temp = list->head;
    node->next = temp;
    list->head = node;
}

void appendNode2List(Node_t *node, List_t *list) {
    if (!list || !node) {
        return;
    }

    if (!list->head) {
        list->head = node;
        list->tail = node;
        return;
    }

    list->tail->next = node;
    list->tail = node;

    // Node_t *temp = list->tail;
    // node->next = temp;
    // list->head = node;
}


void freeList(List_t *list) {
    if (!list || !list->head) {
        return;
    }

    // 防止循环了， 释放不了
    if (list->tail->next != NULL) {
        list->tail->next = NULL;
    }

    Node_t *pos = list->head;
    while (pos != NULL) {
        Node_t *next = pos->next;
        pos->next = NULL;
        free(pos);
        pos = next;
    }
    list->head = NULL;
    list->tail = NULL;
}


