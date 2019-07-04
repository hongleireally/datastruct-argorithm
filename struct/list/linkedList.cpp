//
// Created by 洪磊 on 2019-06-24.
//
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef struct Node{
    int value;
    Node* next;
}Node,*linkedList;

Status initList(linkedList &);
Status destory(Node* &);
Status clearList(Node* &);
bool listEmpty(Node*);
Status listLength(Node*, int&);
Status getElem(Node*, int, int&);
Status locateElem(Node*, int, int&);
Status priorElem(Node*, int, int&);
Status nextElem(Node*, int, int&);
Status insertElem(Node*&, int, int);
Status deleteElem(Node*&, int);
Status traverse(Node*&);
Status inflateList(Node*);
void printList(Node*);
Status addElem(Node*&, int);
void unionList(Node*, Node*);
void unionSortedList(Node*, Node*);

int main() {
    Node* list;
    initList(list);
    addElem(list, 1);
    addElem(list, 2);
    addElem(list, 3);
    printList(list);
    return 0;
}

Status initList(linkedList &list) {
    list=NULL;
    return OK;
}

Status destory(Node* &list) {
    if (list) {
        while (list) {
            linkedList next = list->next;
            free(list);
            list = next;
        }
    }
    list = NULL;
    return OK;
}

Status clearList(Node* &list) {
    if (list) {
        while (list) {
            linkedList next = list->next;
            free(list);
            list = next;
        }
    }
    list = NULL;
    return OK;
}

bool listEmpty(Node* list) {
    return list == NULL;
}

Status listLength(Node* list, int& len) {
    len = 0;
    if (!list) {
        return OK;
    }
    while (list) {
        len++;
        list = list->next;
    }
    return OK;
}

Status getElem(Node* list, int num, int& val) {
    if (!list) {
        return ERROR;
    }
    int index = 1;
    while (list && index < num) {
        list = list->next;
        index++;
    }
    if (!list || index > num) {
        return ERROR;
    }
    val = list->value;
    return OK;
}

Status locateElem(Node* list, int val, int& num) {
    if (!list) {
        return ERROR;
    }
    num = 0;
    while (list) {
        num++;
        if (list->value == val) {
            break;
        }
        list = list->next;
    }
    if (!list) {
        return ERROR;
    }
    return OK;
}

Status priorElem(Node* list, int val, int &target) {
    Node* pre = NULL;
    while(list) {
        if (list->value == val) {
            break;
        }
        pre = list;
        list = list->next;
    }
    if (!pre) {
        return ERROR;
    }
    target = pre->value;
    return OK;
}

Status nextElem(Node* list, int val, int &target) {
    while (list) {
        if (list->value == val) {
            break;
        }
        list = list->next;
    }
    if (!list || !list->next) {
        return ERROR;
    }
    target = list->next->value;
    return OK;
}

Status insertElem(Node* &list, int num, int val) {
    if (num < 1) {
        return ERROR;
    }
    if (!list) {
        if (num == 1) {
            list = (Node*)malloc(sizeof(Node));
            list->value = val;
            list->next = NULL;
            return OK;
        } else{
            return ERROR;
        }
    }
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = val;
    if (num == 1) {
        node->next = list;
        list = node;
        return OK;
    }
    int index = 1;
    Node* pre = list;
    while (pre) {
        if (index = num-1) {
            node->next = pre->next;
            pre->next = node;
            break;
        }
        pre = pre->next;
        index++;
    }
    return OK;
}

Status deleteElem(Node* &list, int num) {
    if (!list || num < 1) {
        return ERROR;
    }
    Node* pre = list;
    if (num == 1) {
        list = list->next;
        free(pre);
        return OK;
    }
    int index = 1;
    while (pre) {
        if (index == num-1) {
            if (!pre->next) {
                return ERROR;
            } else {
                pre->next = pre->next->next;
                break;
            }
        }
        pre = pre->next;
        index++;
    }
    return OK;
}

Status traverse(Node* &list) {
    //设置头节点

}

void printList(Node* list) {
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
}

Status addElem(Node* &list, int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    if (!list) {
        list = node;
        return OK;
    }
    Node* pre = NULL;
    Node* cur = list;
    while (cur) {
        pre = cur;
        cur = cur->next;
    }
    pre->next = node;
    return OK;
}

//void unionList(Node* list1, Node* list2) {
//    if (!list2) {
//        return;
//    }
//}
//void unionSortedList(Node*, Node*);