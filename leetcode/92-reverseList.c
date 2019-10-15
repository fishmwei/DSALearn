
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


  struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode ListHead;
    ListHead.next = head;

    struct ListNode *begin = &ListHead;
    struct ListNode *start = head;

    int i = m;
    while (i > 1 && start) {
        begin = begin->next;
        start = start->next;
        i--;
    }
 
    struct ListNode *reverseTail = start;
    struct ListNode *next = start->next;
    struct ListNodev *prev = start;
    for (i = m; i < n && next; i++) { // 翻转
        struct ListNode *temp = next;
        next = next->next;
        temp->next = prev;
        prev = temp;
    }
    
    reverseTail->next = next;
    begin->next = prev; 

    return ListHead.next;
}

