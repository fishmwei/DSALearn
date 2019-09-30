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
 *  leetcode 第9题
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "singleList.h"

Node_t* reverseBetween(Node_t *head, int m, int n) {
    Node_t ListHead;
    ListHead.next = head;

    Node_t *begin = &ListHead;
    Node_t *start = head;

    int i = m;
    while (i > 1 && start) {
        begin = begin->next;
        start = start->next;
        i--;
    }
 
    Node_t *reverseTail = start;
    Node_t *next = start->next;
    Node_t *prev = start;
    for (i = m; i < n && next; i++) { // 翻转
        Node_t *temp = next;
        next = next->next;
        temp->next = prev;
        prev = temp;
    }
    
    reverseTail->next = next;
    begin->next = prev; 

    return ListHead.next;
}

int main() {
    int datas[] = {1,   5};

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
    list.head = reverseBetween(list.head, 1, 2);
    showList(&list);
    freeList(&list);

    return 0;
}

