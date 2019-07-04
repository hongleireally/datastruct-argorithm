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
typedef int* Triplet;

Status initTriplet(Triplet*, int, int, int);
Status destoryTriplet(Triplet&);
Status get(Triplet, int, int*);
Status put(Triplet, int, int);
bool isAscending(Triplet);
bool isDescending(Triplet);
void max(Triplet, int*);
void min(Triplet, int*);

int main() {
    Triplet t;
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if (initTriplet(&t, a, b, c) != OK) {
        return -1;
    }
    int val;
    get(t, 2, &val);
    printf("t[2]=%d\n", val);
    printf("%p\n", t);
    destoryTriplet(t);
    printf("%p", t);
    return 0;
}

Status initTriplet(Triplet* tp, int a, int b, int c) {
    *tp = (int*) malloc(3* sizeof(int));
    if (!tp) {
        return OVERFLOW;
    }
    (*tp)[0] = a;
    (*tp)[1] = b;
    (*tp)[2] = c;
    return OK;
}

Status destoryTriplet(Triplet &t) {
    free(t);
    t = NULL;
    return OK;
}

Status get(Triplet t, int i, int* value) {
    if (i<1 || i>3) {
        return INFEASIBLE;
    }
    *value = t[i-1];
    return OK;
}
Status put(Triplet t, int i, int value) {
    if(i<1 || i>3) {
        return INFEASIBLE;
    }
    t[i-1] = value;
    return OK;
}

bool isAscending(Triplet t) {
    return t[0]<= t[1] && t[1]<=t[2];
}

bool isDescending(Triplet t) {
    return t[0]>= t[1] && t[1]>=t[2];
}

void max(Triplet t, int* value) {
    *value = t[0]>=t[1]?(t[0]>=t[2]?t[0]:t[2]):(t[1]>=t[2]?t[1]:t[2]);
}
void min(Triplet t, int* value) {
    *value = t[0]<=t[1]?(t[0]<=t[2]?t[0]:t[2]):(t[1]<=t[2]?t[1]:t[2]);
}

