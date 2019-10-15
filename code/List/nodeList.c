#include "nodeList.h"


struct ListNode *reverse(struct ListNode *head) {
    if (!head) {
        return head;
    }

    struct ListNode *prev = NULL;
    struct ListNode *cur = head;
    struct ListNode *next = head;
    // cur->next = prev;

    while (next) {
        cur = next;
        next = next->next;
        cur->next = prev;
        prev = cur;
         
    }

    return cur;
}

void showList(struct ListNode *head) {
    if (!head) {
        printf("list is empty!\r\n");
        return;
    }

    struct ListNode *cur = head;
    while (cur) {
        printf("%d ", cur->val);
        cur = cur->next;
    }

    printf("\r\n");
}

// 插入头部
struct ListNode *insertNode2List(struct ListNode *node, struct ListNode *head) {
    node->next = head;
    return node;
}

struct ListNode * appendNode2List(struct ListNode *node, struct ListNode *head) {
    return NULL;
}

void freeList(struct ListNode *head) {
    struct ListNode *cur = head;
    while (cur) {
        struct ListNode *temp = cur;
        printf("%d ", cur->val);
        cur = cur->next;

        free(temp);
    }
}