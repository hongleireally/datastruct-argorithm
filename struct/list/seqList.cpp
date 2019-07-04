//
// Created by 洪磊 on 2019-06-24.
//
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define defaultSize 10
#define increment 5

typedef int Status;
typedef struct {
    int *p;
    int length;
    int size;
} seqList;

Status initList(seqList*);
Status destory(seqList*);
Status clearList(seqList*);
bool listEmpty(seqList*);
Status listLength(seqList*, int&);
Status getElem(seqList*, int, int&);
Status locateElem(seqList*, int, int&);
Status priorElem(seqList*, int, int&);
Status nextElem(seqList*, int, int&);
Status insertElem(seqList*, int, int);
Status deleteElem(seqList*, int);
Status traverse(seqList*);
Status inflateList(seqList*);
void printList(seqList*);
void addElem(seqList*, int);
void unionList(seqList*, seqList*);
void unionSortedList(seqList*, seqList*);

int main() {
    seqList* list, * list2;
    if (list == NULL) {
        list = (seqList*)malloc(sizeof(seqList));
    }
    if (list2 == NULL) {
        list2 = (seqList*)malloc(sizeof(seqList));
    }
    if (!(initList(list) == OK)) {
        printf("线性表初始化失败");
    }
    if (!(initList(list2) == OK)) {
        printf("线性表初始化失败");
    }
    seqList* list3;
    initList(list3);
    printf("complete");
//    insertElem(list, 1, 1);
//    insertElem(list, 2, 2);
//    addElem(list2, 3);
//    addElem(list2, 4);
//    printList(list);
//    printList(list2);
//    unionSortedList(list, list2);
//    printList(list);
    return 0;
}

Status initList(seqList* list) {
    if (!(list->p = (int*) malloc(defaultSize* sizeof(int)))) {
        printf("error");
        return ERROR;
    }
    list->size = defaultSize;
    list->length = 0;
    return OK;
}
Status destory(seqList* list) {
    free(list->p);
    list->length = 0;
    return OK;
}

Status clearList(seqList* list) {
    list->length = 0;
    return OK;
}
bool listEmpty(seqList* list) {
    return list->length==0;
}
Status listLength(seqList* list, int& len) {
    len = list->length;
    return OK;
}
Status getElem(seqList* list, int n, int& val) {
    if (n < 1 || n > list->length) {
        return ERROR;
    }
    val = list->p[n-1];
    return OK;
}
Status locateElem(seqList* list, int val, int& n) {
    bool isFind = false;
    for (int i = 0; i < list->length; ++i) {
        if (list->p[i] == val) {
            isFind = true;
            n = i+1;
            break;
        }
    }
    if (isFind) {
        return OK;
    } else{
        return ERROR;
    }
}

Status priorElem(seqList* list, int target, int& val) {
    int num;
    if (!(locateElem(list, target, num) == OK)) {
        return ERROR;
    }
    if (num == 1) {
        return ERROR;
    }
    val = list->p[num-2];
    return OK;
}

Status nextElem(seqList* list, int target, int& val) {
    int num;
    if (!(locateElem(list, target, num) == OK)) {
        return ERROR;
    }
    if (num == list->length) {
        return ERROR;
    }
    val = list->p[num];
    return OK;
}

Status insertElem(seqList* list, int num, int val) {
    if (num < 1 || num > list->length+1) {
        return ERROR;
    }
    if (list->length == list->size) {
        //扩容
        inflateList(list);
    }
    if (num == list->length+1) {
        list->p[list->length] = val;
        list->length++;
        return OK;
    }
    for (int i = list->length-1; i >=num-1 ; ++i) {
        list->p[i+1] = list->p[i];
    }
    list->p[num-1] = val;
    list->length++;
    return OK;
}

Status deleteElem(seqList* list, int val) {
    int index;
    if (!(locateElem(list, val, index) == OK)) {
        return ERROR;
    }
    if (list->length == index) {
        list->length--;
        return OK;
    }
    for (int i = --index; i < list->length-1; ++i) {
        list->p[i] = list->p[i+1];
    }
    list->length--;
    return OK;
}

Status traverse(seqList* list) {
    if (list->length == 0 || list->length == 1) {
        return OK;
    }
    int* origin = list->p;
    list->p = (int*) malloc(list->length* sizeof(int));
    for (int i = 0; i < list->length; ++i) {
        list->p[i] = origin[list->length-1-i];
    }
    return OK;
}

Status inflateList(seqList* list) {
    //realloc函数用于数组的扩展
    int* newbase = (int*)realloc(list->p, list->size+increment);
    if (!newbase) {
        return ERROR;
    }
    list->p = newbase;
    return OK;
}

void printList(seqList* list) {
    for (int i = 0; i < list->length; ++i) {
        printf("%d ", list->p[i]);
    }
    printf("\n");
}

void addElem(seqList* list, int val) {
    insertElem(list, list->length+1, val);
}

void unionList(seqList* list1, seqList* list2) {
    int index;
    int val;
    for (int i = 0; i < list2->length; ++i) {
        getElem(list2, i+1, val);
        if (!locateElem(list1, val, index)) {
            addElem(list1, val);
        }
    }
}

/**
 * 将两个从小到大排列的线性表合并
 * @param list1
 * @param list2
 */
void unionSortedList(seqList* list1, seqList* list2) {
    seqList* target;
    initList(target);
    if (list1->length+list2->length>target->size) {
        target->p=(int*) malloc((list1->length+list2->length)* sizeof(int));
    }
    int a=0,b=0;
    int index = 0;
    int min;
    while (a<list1->length && b<list2->length) {
        if (list1->p[a]<list2->p[b]) {
            min = list1->p[a++];
        } else{
            min = list2->p[b++];
        }
        target->p[index++] = min;
    }
    while (a<list1->length) {
        target->p[index++] = list1->p[a++];
    }
    while (b<list2->length) {
        target->p[index++] = list2->p[b++];
    }
    printList(target);
    destory(list1);
    list1=target;
}


