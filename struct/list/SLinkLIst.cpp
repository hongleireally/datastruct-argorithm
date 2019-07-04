//
// Created by 洪磊 on 2019-06-28.
//

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

const int OK = 1;
const int ERROR = 0;
const int INFEACIBLE = -1;
const int OVERFLOW = -2;

typedef int Status;

typedef struct {
    int data;
    int next;
} component, SLinkList[MAXSIZE];

Status initList(SLinkList &l);
/**
 * 查看值是否在链表中，若在链表中，求对应数组的下标
 * @param list
 * @param val
 * @param i
 * @return
 */
int locateElem(SLinkList list, int val, int &i);

int main() {
//    SLinkList l;
//    printf("%d", sizeof(l));
    if (-1) {
        printf("1");
    } else {
        printf("2");
    }
}


Status initList(SLinkList l) {
//    l[0].data = NULL;
//    l[0].next = 0;
    for (int i = 0; i < MAXSIZE; ++i) {
        l[i].next = i+1;
    }
    l[MAXSIZE-1].data = 0;
    return OK;
}

Status locateElem(SLinkList list, int val, int &i) {
    int index = list[0].next;
    if (index && list[index].data!=val) {
        index = list[index].next;
    }
    if (!index) {
        return ERROR;
    }
    i = index;
    return OK;
}






