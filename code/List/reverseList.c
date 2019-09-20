#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct node {
    int data;
    struct node *next;
} Node_t;

typedef struct {
    Node_t *head;
} List_t;

List_t *reverse(List_t *list) {
    if (list == NULL) {
        return list;
    }

    Node_t *pos = list->head;
    if (pos == NULL) {
        return list;
    }

    Node_t *next = pos->next;
    pos->next = NULL;
    while (next != NULL) {
        Node_t *temp = next;
        next = next->next;
        temp->next = pos;
        pos = temp;
    }

    list->head = pos;

    return list;
}

void showList(List_t *list) {
    if (NULL == list || list->head == NULL) {
        printf("list is empty.\r\n");
        return;
    }

    printf("list nodes:\r\n");
    Node_t *pos = list->head;
    while (pos != NULL) {
        printf("%d ", pos->data);
        pos = pos->next;
    }
    printf("\r\n");
}

// 插入头部
void insertNode2List(Node_t *node, List_t *list) {
    
    if (!list || !node) {
        return;
    }

    printf("insert %d\r\n", node->data);
    if (!list->head) {
        list->head = node;
        return;
    }

    Node_t *temp = list->head;
    node->next = temp;
    list->head = node;
}

void freeList(List_t *list) {
    if (!list || !list->head) {
        return;
    }

    Node_t *pos = list->head;
    while (pos != NULL) {
        Node_t *next = pos->next;
        free(pos);
        pos = next;
    }
}

int main() {
    int datas[] = {1, 2, 3, 4, 9, 9, 8, 3};

    List_t list;
    memset(&list, 0, sizeof(List_t));
    // list.head = NULL;
    for (int i = 0; i < sizeof(datas)/sizeof(int); i++) {
        Node_t *node = malloc(sizeof(Node_t));
        node->data = datas[i];
        node->next = NULL;
        insertNode2List(node, &list);
    }

    showList(&list);
    reverse(&list);
    showList(&list);
    freeList(&list);

    return 0;
}

