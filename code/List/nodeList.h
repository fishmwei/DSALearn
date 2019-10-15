  #include <stdio.h>
  #include <stdlib.h>

  
  struct ListNode {
      int val;
      struct ListNode *next;
  };

typedef enum {
    false, 
    true
} bool ;

struct ListNode *reverse(struct ListNode *head);

void showList(struct ListNode *list);

// 插入头部
struct ListNode *insertNode2List(struct ListNode *node, struct ListNode *head);

struct ListNode *appendNode2List(struct ListNode *node, struct ListNode *head);

void freeList(struct ListNode *head);