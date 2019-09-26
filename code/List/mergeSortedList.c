/*
 * @Author: hmw 
 * @Date: 2019-09-20 11:23:36 
 * @Last Modified by: hmw
 * @Last Modified time: 2019-09-20 11:23:56
 */

/**
 *  合并两个有序链表
 *  
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "singleList.h"

List_t *mergeSortedList(List_t *list1, List_t *list2) {
    List_t *mergedList = malloc(sizeof(List_t));
    memset(mergedList, 0, sizeof(List_t));

    Node_t *index1 = list1->head;
    Node_t *index2 = list2->head;
    while (index1 && index2) {
        Node_t *temp = index1;
        if (index1->data > index2->data) {
            temp = index2;
            index2 = index2->next;
        } else {
            index1 = index1->next;
        }
        temp->next = NULL;
        appendNode2List(temp, mergedList);
    }

    while (index1) {
        Node_t *temp = index1;
        index1 = index1->next;
        appendNode2List(temp, mergedList);
    }

    while (index2) {
        Node_t *temp = index2;
        index2 = index2->next;
        appendNode2List(temp, mergedList);
    }

    list1->head = NULL;
    list1->tail = NULL;

    list2->head = NULL;
    list2->tail = NULL;

    return mergedList;
}

// struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

//     struct ListNode *head = NULL;
//     struct ListNode *tail;

//     while (l1 && l2) {
//         struct ListNode *temp = l1;
//         if (l1->val > l2->val) {
//             temp = l2;
//             l2 = l2->next;
//         } else {
//             l1 = l1->next;
//         }

//         if (!head) {
//             head = temp;
//             tail = temp;
//         } else {
//             tail->next = temp;
//             tail = temp;
//         }
//     }

//     while (l1) {
//         struct ListNode *temp = l1;
//         l1 = l1->next;
//         if (!head) {
//             head = temp;
//             tail = temp;
//         } else {
//             tail->next = temp;
//             tail = temp;
//         }
//     }

//     while (l2) {
//         struct ListNode *temp = l2;
//         l2 = l2->next;
//         if (!head) {
//             head = temp;
//             tail = temp;
//         } else {
//             tail->next = temp;
//             tail = temp;
//         }
//     }

//     return head;
// }

int main() {
    int datas1[] = {1, 2, 3, 8, 9};
    int datas2[] = {-11, -2, 3, 7, 8, 99};

    List_t list1, list2;
    memset(&list1, 0, sizeof(List_t));
    memset(&list2, 0, sizeof(List_t));

    for (int i = 0; i < sizeof(datas1)/sizeof(int); i++) {
        Node_t *node = malloc(sizeof(Node_t));
        node->data = datas1[i];
        node->next = NULL;
        appendNode2List(node, &list1);
    }

    for (int i = 0; i < sizeof(datas2)/sizeof(int); i++) {
        Node_t *node = malloc(sizeof(Node_t));
        node->data = datas2[i];
        node->next = NULL;
        appendNode2List(node, &list2);
    }

    List_t *mergeList = mergeSortedList(&list1, &list2);
    showList(mergeList);
    freeList(mergeList);
    free(mergeList);

    freeList(&list1);
    freeList(&list2);

    return 0;
}

