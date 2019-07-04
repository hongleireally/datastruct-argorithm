//
// Created by 洪磊 on 2019-07-01.
//

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef struct Node{
    int data;
    Node* prior;
    Node* next;
}Node, *DuLinkList;

Status initList(DuLinkList &l);
Status addElem(DuLinkList l, int val);
Node* getElem(DuLinkList l, int index);
Status insertElem(DuLinkList l, int index, int val);
void printList(DuLinkList l);

int main() {
    DuLinkList l;
    initList(l);
    addElem(l, 1);
    addElem(l, 2);
    addElem(l, 3);
    printList(l);
//    insertElem(l, 5, 4);
//    printList(l);
    return 0;
}

Status initList(DuLinkList &l) {
    l = (Node*)malloc(sizeof(Node));
    if (!l) {
        return ERROR;
    }
    l->prior = l;
    l->next = l;
    l->data = NULL;
    return OK;
}

Status addElem(DuLinkList l, int val) {
    Node* head = l;
    while (l->next != head) {
        l = l->next;
    }
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = val;
    node->next = l->next;
    node->prior = l;
    l->next->prior = node;
    l->next = node;
    return OK;
}

Node* getElem(DuLinkList l, int index) {
    Node* head = l;
    l = l->next;
    int i=1;
    while (l != head && i++<index) {
        l = l->next;
    }
    if (l == head || i != index) {
        return 0;
    }
    return l;
}

Status insertElem(DuLinkList l, int index, int val) {
    Node* head = l;
    l = l->next;
    int i=1;
    while (l != head && i<index) {
        l = l->next;
        i++;
    }
    if (!(l == head && i == index) && (l == head || i != index)) {
        return 0;
    }
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = val;
    node->next = l;
    node->prior = l->prior;
    l->prior->next = node;
    l->prior = node;
    return 1;
}

void printList(DuLinkList l) {
    Node* head = l;
    l = l->next;
    while (l != head) {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}

