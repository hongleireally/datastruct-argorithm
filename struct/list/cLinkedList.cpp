// 循环链表
// Created by 洪磊 on 2019-07-05.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef struct Node{
    int data;
    Node* next;
}Node,*cLinkedList;

const int OK = 1;
const int ERROR = 0;
const int OVERFLOW = -1;
const int INFEACIBLE = -2;

Status initList(cLinkedList &list);
Status addElem(cLinkedList list, int val);
void printList(cLinkedList list);
Status insertElem(cLinkedList list, int index, int val);
Status delElem(cLinkedList list, int val);
Status delElemByIndex(cLinkedList list, int index);
int len(cLinkedList list);
void mergeList(cLinkedList a, cLinkedList b);

int main() {
    cLinkedList list;
    initList(list);
    addElem(list, 1);
    addElem(list, 2);
    addElem(list, 3);
    cLinkedList list2;
    initList(list2);
    addElem(list, 4);
    addElem(list, 5);
    addElem(list, 6);
    mergeList(list, list2);
    printList(list);
    printf("len = %d\n", len(list));
    return 0;
}

Status initList(cLinkedList &list) {
    if (!(list = (Node*) malloc(sizeof(Node)))) {
        return OVERFLOW;
    }
    list->next = list;
    return OK;
}

Status addElem(cLinkedList list, int val) {
    Node* head = list;
    while (list->next != head) {
        list = list->next;
    }
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = val;
    list->next = node;
    node->next = head;
    return OK;
}

void printList(cLinkedList list) {
    Node* head = list;
    list = list->next;
    while (list != head) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

Status insertElem(cLinkedList list, int index, int val) {
    Node* head = list;
    Node* pre = list;
    int num = 1;
    list = list->next;
    while (list!=head && num<index) {
        pre = list;
        list = list->next;
        num++;
    }
    if (list == head || num > index) {
        return ERROR;
    }
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = val;
    node->next = pre->next;
    pre->next = node;
    return OK;
}

Status delElem(cLinkedList list, int val) {
    Node* pre = list;
    Node* head = list;
    list = list->next;
    while (list != head && list->data != val) {
        pre = list;
        list = list->next;
    }
    if (list == head) {
        return ERROR;
    }
    pre->next = list->next;
    free(list);
    return OK;
}

Status delElemByIndex(cLinkedList list, int index) {
    Node* pre = list;
    Node* head = list;
    list = list->next;
    int num = 1;
    while (list != head && num < index) {
        pre = list;
        list = list->next;
        num++;
    }
    if (list == head || num > index) {
        return ERROR;
    }
    pre->next = list->next;
    free(list);
    return OK;
}

int len(cLinkedList list) {
    int num = 0;
    Node* head = list;
    while (list->next != head) {
        num++;
        list = list->next;
    }
    return num;
}

void mergeList(cLinkedList a, cLinkedList b) {
    if (b->next == b) {
        return;
    }
    Node* head = a;
    while (a->next != head) {
        a = a->next;
    }
    a->next = b->next;
    Node* head2 = b;
    while (b->next != head2) {
        b = b->next;
    }
    b->next = head;
    free(head2);
}

