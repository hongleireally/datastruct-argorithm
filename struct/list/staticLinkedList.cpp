//
// 静态链表
// 用数组实现的静态链表
// 游标为0即表示该下标是最后一个元素
// Created by 洪磊 on 2019-06-26.
//

#include <stdio.h>

const int MAXSIZE = 100;
const int OK = 1;
const int ERROR = 0;
const int OVERFLOW = -1;
const int INFEASIBLE = -2;

typedef int Status;
typedef struct {
    int data;
    int cur;//游标，下一个元素的下标
}Node, SLinkedList[MAXSIZE];

/**
 * 初始化备用链表
 * @param list
 * @return
 */
Status initList(SLinkedList list);
Status addElem(SLinkedList list, int val);
Status emptyList(SLinkedList list);
/**
 * 拿到备用链表的第一个节点，即获取第一个空元素的下标
 * @param list
 * @param index
 * @return
 */
Status mallocList(SLinkedList list, int &index);
Status freeList(SLinkedList list, int index);
Status locateElem(SLinkedList list, int val, int &index);
/**
 * list 备用链表
 * s    已使用元素链表的头节点
 * @param list
 * @param s
 */
void diffrence(SLinkedList list, int &s);
void printList(SLinkedList list, int s);

int main() {
    SLinkedList list;
    int s;
    diffrence(list, s);
    printList(list, s);
}

Status initList(SLinkedList list) {
    for (int i = 0; i < MAXSIZE; ++i) {
        list[i].data = NULL;
        list[i].cur = i+1;
    }
    list[MAXSIZE-1].cur= 0;
    return OK;
}

Status addElem(SLinkedList list, int val) {

}

Status emptyList(SLinkedList list) {
    initList(list);
    return OK;
}

Status mallocList(SLinkedList list, int &index) {
    index = list[0].cur;
    if (index) {
        list[0].cur = list[index].cur;
    }
    if (!index) {
        return ERROR;
    }
    return OK;
}

Status freeList(SLinkedList list, int index) {
    if (!index) {
        return ERROR;
    }
    list[index].cur = list[0].cur;
    list[0].cur = index;
    return OK;
}

Status locateElem(SLinkedList list, int val, int &index) {
    index = list[0].cur;
    if (index && list[index].data != val) {
        index = list[index].cur;
    }
    if (index == 0) {
        return ERROR;
    }
    return OK;
}

void diffrence(SLinkedList list, int &s) {
    initList(list);
    mallocList(list, s);
    int m, n;
    scanf("%d %d", &m, &n);
    int val;
    int e = s;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &val);
        int cur;
        mallocList(list, cur);
        list[cur].data = val;
        list[e].cur = cur;
        e = cur;
    }
    list[e].cur = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        int index = s;
        int cur = index;
        while(cur && list[cur].data != val) {
            index = cur;
            cur = list[cur].cur;
        }
        if (!cur) {
            //cur=0，表示已经比较到最后一个元素了，没有重复元素
            int p;
            mallocList(list, p);
            list[p].data = val;
            list[e].cur = p;
            e = p;
            list[e].cur = 0;
        } else {
            //存在重复元素，cur下标处就是重复元素
            list[index].cur = list[cur].cur;
            freeList(list, cur);
            if (e == cur) {
                e = index;
            }
        }
    }
}

void printList(SLinkedList list, int s) {
    s= list[s].cur;
    while (s) {
        printf("%d ", list[s].data);
        s = list[s].cur;
    }
    printf("\n");
}









