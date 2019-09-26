

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL;
    struct ListNode *tail;

    while (l1 && l2) {
        struct ListNode *temp = l1;
        if (l1->val > l2->val) {
            temp = l2;
            l2 = l2->next;
        } else {
            l1 = l1->next;
        }

        if (!head) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    while (l1) {
        struct ListNode *temp = l1;
        l1 = l1->next;
        if (!head) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    while (l2) {
        struct ListNode *temp = l2;
        l2 = l2->next;
        if (!head) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}