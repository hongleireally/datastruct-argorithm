//
// Created by 洪磊 on 2019-07-06.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef struct Node{
    int data;
    Node* next;
}*Link, *Position;

typedef struct {
    Link head, tail;
    int len;
}LinkList;

const int OK = 1;
const int ERROR = 0;
const int OVERFLOW = -1;
const int INFEACIBLE = -2;

Status initList(LinkList list);
Status makeNode(Link &P, int val);
Status freeNode(Link &p);
Status destroyList(LinkList &list);
Status cleanList(LinkList list);
Status append(LinkList list, int val);

int main() {
    printf("123");
    return 0;
}

Status initList(LinkList list) {
    Link link = (Link) malloc(sizeof(Node));
    list.head = link;
    list.tail = link;
    list.len = 0;
    return OK;
}

Status makeNode(Link &P, int val) {

    return OK;
}

Status freeNode(Link &p) {

    return OK;
}

Status destroyList(LinkList &list) {

    return OK;
}

Status cleanList(LinkList list) {

    return OK;
}

Status append(LinkList list, int val) {

    return OK;
}