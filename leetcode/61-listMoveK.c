
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>


// 循环右移k位

/**
 * 1. 获取链表长度，保存尾部
 * 2. 组成循环链表
 * 3. 后移 length - k % lenght位， 前一位next置空
 * 
 * leetcode 第61题
 * */

// [1,2,3,4,5]  2

// [4,5,1,2,3]


  struct ListNode {
     int val;
     struct ListNode *next;
 };

int getLength(struct ListNode* head, struct ListNode **tail) {
    int count = 0;
    struct  ListNode *pos = head;
    struct ListNode *temp = pos;

    while (pos != NULL) {
        count++;
        temp = pos;
        pos = temp->next;
    }
    *tail = temp;

    return count;    
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    if (!head) {
        return head;
    }

    struct ListNode *tail = NULL;
    int length = getLength(head, &tail);
    if (k%length == 0) {
        return head;
    }

    k = k%length;
    tail->next = head;
    struct ListNode *prev = tail;
    struct ListNode *pos = head;
    k = length - k;
    while (k > 0) {  // 3  B  2  c  1 d
        k--;
        prev = pos;
        pos = pos->next;
    }

    prev->next = NULL;
    return pos;
}

