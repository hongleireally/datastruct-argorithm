//
// Created by 洪磊 on 2019-06-25.
//带头节点的单链表
//
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef struct Node {
    int value;
    Node* next;
} Node, *linkedList;

Status initList(linkedList &);
Status destroyList(linkedList &);
Status clearList(linkedList);
bool isEmpty(linkedList);
Status getLen(linkedList, int&);
Status getElem(linkedList, int, int&);
Status locateElem(linkedList, int, int&);
Status priorElem(linkedList, int, int&);
Status nextElem(linkedList , int, int&);
Status insertElem(linkedList, int, int);
Status addElem(linkedList, int);
Status deleteElem(linkedList, int);
Status deleteElemByIndex(linkedList, int);
Status traverse(linkedList);
void printList(linkedList);
Status unionList(linkedList, linkedList);
Status unionSortedList(linkedList, linkedList);
Status mergeSortedList(linkedList, linkedList&);
Status createReverseList(linkedList&, int);

int main() {
    linkedList list1, list2;
    initList(list1);
    initList(list2);
    addElem(list1,1);
    addElem(list1,2);
    addElem(list2,3);
    addElem(list2,4);
    printList(list1);
    printList(list2);
    mergeSortedList(list1, list2);
    printList(list1);
    return 0;
}

Status initList(linkedList &l) {
    l = (Node*) malloc(sizeof(Node));
    if (!l) {
        return ERROR;
    }
    l->next = NULL;
    return OK;
}

Status destroyList(linkedList &l) {
    free(l);
    l=NULL;
    return OK;
}

Status clearList(linkedList l) {
    l->next = NULL;
    return OK;
}

bool isEmpty(linkedList l) {
    return l->next==NULL;
}

Status getLen(linkedList l, int& len) {
    len=1;
    l = l->next;
    while (l) {
        l= l->next;
        len++;
    }
    len--;
    return OK;
}

Status getElem(linkedList l, int num, int &val) {
    int pos = 1;
    l = l->next;
    while (l && pos < num) {
        l=l->next;
        pos++;
    }
    if (!l || pos > num) {
        return ERROR;
    }
    val = l->value;
    return OK;
}

Status locateElem(linkedList l, int val, int &num) {
    int pos = 1;
    l = l->next;
    while (l) {
        if (l->value == val) {
            break;
        }
        l=l->next;
        pos++;
    }
    if (!l) {
        return ERROR;
    }
    num = pos;
    return OK;
}

Status priorElem(linkedList l, int val, int &prior) {
    Node* pre = l;
    Node* cur = l->next;
    while (cur && cur->value!=val) {
        pre = cur;
        cur = cur->next;
    }
    if (!cur) {
        return ERROR;
    }
    prior = pre->value;
    return OK;
}

Status nextElem(linkedList l, int val, int &next) {
    l = l->next;
    while (l && l->value!=val) {
        l=l->next;
    }
    if (!l || !l->next) {
        return ERROR;
    }
    next = l->next->value;
    return OK;
}

Status insertElem(linkedList l, int num, int val) {
    Node *pre = l;
    int index = 1;
    l = l->next;
    while (l && index < num) {
        pre = l;
        l = l->next;
        index++;
    }
    if (!l || index > num) {
        return ERROR;
    }
    Node* node = (Node*) malloc(sizeof(int));
    node->value = val;
    node->next = pre->next;
    pre->next = node;
    return OK;
}

Status addElem(linkedList l, int val) {
    Node* pre = l;
    l = l->next;
    while (l) {
        pre = l;
        l = l->next;
    }
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    pre->next = node;
    return OK;
}

Status deleteElem(linkedList l, int val) {
    Node* pre = l;
    l = l->next;
    while (l && l->value!=val) {
        pre = l;
        l = l->next;
    }
    if (!l) {
        return ERROR;
    }
    pre->next = l->next;
    free(l);
    return OK;
}

Status deleteElemByIndex(linkedList l, int num) {
    Node* pre = l;
    int index = 1;
    l = l->next;
    while (l && index < num) {
        pre = l;
        l = l->next;
        index++;
    }
    if (!l || index > num) {
        return ERROR;
    }
    pre->next = l->next;
    free(l);
    return OK;
}

Status traverse(linkedList l) {
    if (isEmpty(l) || !l->next->next) {
        return OK;
    }
    Node* start = l;
    Node* pre = l->next;
    l = l->next->next;
    pre->next = NULL;
    Node *a;
    while (l) {
        a = pre;
        pre = l;
        l = l->next;
        pre->next = a;
    }
    start->next = pre;
    return OK;
}

void printList(linkedList l) {
    l = l->next;
    while (l) {
        printf("%d ", l->value);
        l = l->next;
    }
    printf("\n");
}

Status unionList(linkedList l1, linkedList l2) {
    Node* pre = l1;
    l1 = l1->next;
    while (l1) {
        pre = l1;
        l1 = l1->next;
    }
    pre->next = l2->next;
    return OK;
}

Status unionSortedList(linkedList l1, linkedList l2) {
    Node* pre = l1;
    Node *cur1 = l1->next,*cur2 = l2->next;
    Node* node;
    while (cur2) {
        node = (Node*) malloc(sizeof(Node));
        node->value = cur2->value;
        node->next = NULL;
        if (cur1) {
            if (cur2->value < cur1->value) {
                node->next = cur1;
                pre->next = node;
                cur2 = cur2->next;
            } else {
                pre = cur1;
                cur1 = cur1->next;
            }
        } else {
            pre->next = node;
            pre = node;
            cur2 = cur2->next;
        }
    }
    return OK;
}

Status mergeSortedList(linkedList l1, linkedList &l2) {
    Node *pre = l1, *node;
    Node *cur1 = l1->next, *cur2 = l2->next;
    while (cur1 && cur2) {
        if (cur1->value<cur2->value) {
            pre = cur1;
            cur1=cur1->next;
        } else {
            node = cur2->next;
            cur2->next = pre->next;
            pre->next = cur2;
            pre = cur2;
            cur2 = node;
        }
    }
    pre->next = cur1?cur1:cur2;
//    if (cur2) {
//        pre->next = cur2;
//    }
    free(l2);
    l2 = NULL;
    return OK;
}

Status createReverseList(linkedList &l, int n) {
    l = (Node*) malloc(sizeof(Node));
    l->next = NULL;
    Node* p;
    int val;
    for (int i = 0; i< n; i++) {
        p = (Node*) malloc(sizeof(Node));
        p->next = l->next;
        scanf("%d", &val);
        p->value = val;
        l->next = p;
    }
    return OK;
}



