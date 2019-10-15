#include "nodeList.h"

struct ListNode *reverseB(struct ListNode *head) {
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

bool isPalindrome(struct ListNode* head){
    if (!head || head->next == NULL) {
        return true;
    }

    struct ListNode List;
    List.next = head;

    struct ListNode *one = head; // head 1
    struct ListNode *two = head->next && head->next->next ? head->next->next : NULL; // 2

    while (two != NULL) {
        one = one->next; 
        // printf("%d  xxx\r\n", one->val);
        two = two->next && two->next->next ? two->next->next : NULL;
    }

    two = one->next;
    one->next = NULL;
    struct ListNode *twoHead = reverseB(two);
    // showList(twoHead);

    bool isPalindrome = true;

    struct ListNode *left = head;
    struct ListNode *right = twoHead;
    one->next = NULL;

    while (left && right) {
        if (left->val != right->val) {
            isPalindrome = false;
            break;
        }

        left = left->next;
        right = right->next;
    }

    one->next = reverseB(twoHead);

    return isPalindrome;
}

int main() {
    int datas[] = {1, 2, 1};

    struct ListNode *head = NULL;

    int n = sizeof(datas)/sizeof(int);
    for (int i = n-1; i >= 0; i--) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = datas[i];
        node->next = NULL;
        head = insertNode2List(node, head);
    }

    showList(head);
    printf("result %s\r\n", isPalindrome(head) ? "YES":"NO");

    freeList(head);

    return 0;
}