//
// Created by 洪磊 on 2019-07-10.
//

#include <stdio.h>
#include <stdlib.h>

const int OK = 1;
const int ERROR = 0;
const int OVERFLOW = -1;
const int INFEACIBLE = -2;

typedef int Status;
typedef struct Node{
    int data;
    Node* next;
}Node;

typedef struct {
    Node *base,*top;
    int len;
}linkStack;

Status initStack(linkStack &stack);
Status cleanStack(linkStack &stack);
Status push(linkStack &stack, int val);
Status peek(linkStack stack, int &val);
Status pop(linkStack stack, int &val);
void printStack(linkStack stack);

int main() {
    linkStack stack;
    initStack(stack);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    int val;
    peek(stack, val);
    printStack(stack);
    printf("%d\n", val);
    return 0;
}

Status initStack(linkStack &stack) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    stack.base = node;
    stack.top = node;
    stack.len = 0;
    return OK;
}

Status cleanStack(linkStack &stack) {
    stack.top->next = NULL;
    stack.base = stack.top;
    stack.len = 0;
    return OK;
}

Status push(linkStack &stack, int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = val;
    if (stack.top->next == NULL) {
        stack.base = node;
    }
    node->next = stack.top->next;
    stack.top->next = node;
    stack.len++;
    return OK;
}

Status peek(linkStack stack, int &val) {
    if (stack.top->next == NULL) {
        return ERROR;
    }
    val = stack.top->next->data;
    return OK;
}

Status pop(linkStack stack, int &val) {
    if (stack.top->next == NULL) {
        return ERROR;
    }
    val = stack.top->next->data;
    Node* p = stack.top->next;
    stack.top->next = stack.top->next->next;
    free(p);
    return OK;
}

void printStack(linkStack stack) {
    Node* p = stack.top->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}



