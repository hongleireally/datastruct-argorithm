// 顺序栈，使用一组连续的存储单元存储栈的元素
// 栈：先进后出，后进先出（LIFO）
// Created by 洪磊 on 2019-07-06.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef struct {
    int* base;
    int* top;
    int len;
    int size;
}SqStack;

const int DEFAULTSIZE = 100;
const int INCREMENTSIZE = 20;
const int OK = 1;
const int ERROR = 0;
const int OVERFLOW = -1;
const int INFEACIBLE = -2;

Status initStack(SqStack &stack);
Status destroyStack(SqStack &stack);
Status cleanStack(SqStack &stack);
int getLen(SqStack stack);
bool empty(SqStack stack);
Status inflate(SqStack &stack);
Status push(SqStack &stack, int val);
int peek(SqStack stack);
int pop(SqStack &stack);
Status stackVisit(SqStack stack, void (*visit)(int));
void visit(int);

int main() {
    SqStack stack;
    initStack(stack);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    stackVisit(stack, *visit);
    printf("%d\n", peek(stack));
    pop(stack);
    printf("%d\n", peek(stack));
    return 0;
}

Status initStack(SqStack &stack) {
    int* base = (int*) malloc(sizeof(int)*DEFAULTSIZE);
    if (!base) {
        return OVERFLOW;
    }
    stack.base = base;
    stack.top = base;
    stack.len = 0;
    stack.size = DEFAULTSIZE;
    return OK;
}
Status destroyStack(SqStack &stack) {
    free(stack.base);
    return OK;
}

Status cleanStack(SqStack &stack) {
    stack.top = stack.base;
    stack.len = 0;
    return OK;
}

int getLen(SqStack stack) {
    return stack.len;
}

bool empty(SqStack stack) {
    return stack.len == 0;
}

Status inflate(SqStack &stack) {
    stack.base = (int*) realloc(stack.base, (stack.size+INCREMENTSIZE)* sizeof(int));
    if (!stack.base) {
        return OVERFLOW;
    }
    stack.top = stack.base+stack.len;
    stack.size = stack.size+INCREMENTSIZE;
    return OK;
}

Status push(SqStack &stack, int val) {
    if (stack.len == stack.size) {
        //扩容
        inflate(stack);
    }
    *stack.top = val;
    stack.top++;
    stack.len++;
    return OK;
}

int peek(SqStack stack) {
    if (empty(stack)) {
        return NULL;
    }
    return *--stack.top;
}

int pop(SqStack &stack) {
    if (empty(stack)) {
        return NULL;
    }
    int res = *--stack.top;
    return res;
}

Status stackVisit(SqStack stack, void (*visit)(int)) {
    if (empty(stack)) {
        return OK;
    }
    int *p = stack.top-1;
    while (p>=stack.base) {
        visit(*p);
        p = p-1;
    }
    return OK;
}

void visit(int val) {
    printf("%d\n", val);
}


