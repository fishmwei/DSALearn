
/*
 * @Author: hmw 
 * @Date: 2019-09-20 11:23:36 
 * @Last Modified by: hmw
 * @Last Modified time: 2019-09-20 11:23:56
 */

/**
 *  删除链表中倒数第N个结点 
 *  引入头结点，然后分别往后数N个
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "singleList.h"

Node_t *deleteReverseNNode(Node_t *head, int n) {
    if (!head) {
        return head;
    }

    Node_t newHead;
    newHead.next = head;

    Node_t *cur = &newHead;
    for (int i = 0; i < n; i++) {
        if (!cur->next) {
            break;
        }
        cur = cur->next;        
    }

    Node_t *p = &newHead;
    while (cur->next) {
        p = p->next;
        cur = cur->next;
    }
    
    cur = p->next;
    p->next = cur->next;
    free(cur);

    return newHead.next;
}

int main() {
    int datas[] = {1};

    List_t list;
    memset(&list, 0, sizeof(List_t));

    int count = sizeof(datas)/sizeof(int);
    for (int i = 0; i < count; i++) {
        Node_t *node = malloc(sizeof(Node_t));
        node->data = datas[i];
        node->next = NULL;
        appendNode2List(node, &list);
    }

    showList(&list);
    list.head = deleteReverseNNode(list.head, 2);
    showList(&list);

    freeList(&list);

    return 0;
}

