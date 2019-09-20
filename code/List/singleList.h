

typedef struct Node_s {
    int data;
    struct Node_s *next;
} Node_t;

typedef struct list {
    Node_t *head; // 是否为空， 看情况吧
    Node_t *tail;
} List_t;


List_t *reverse(List_t *list);

void showList(List_t *list);

// 插入头部
void insertNode2List(Node_t *node, List_t *list);

void appendNode2List(Node_t *node, List_t *list);

void freeList(List_t *list);




