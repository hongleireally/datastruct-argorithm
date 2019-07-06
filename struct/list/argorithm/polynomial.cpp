// 多项式运算：加、减、乘
// Created by 洪磊 on 2019-07-06.
//
#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef struct Node{
    float coef;//系数
    int expn;//指数
    Node* next;
}Node, *Polynomial;

const int OK = 1;
const int ERROR = 0;
const int OVERFLOW = -1;
const int INFEACIBAL = -2;

Status initPolynomial(Polynomial &polynomial);
Status addPosition(float coef, int expn, Polynomial p);
Status destroyPolynomial(Polynomial &polynomial);
Status cleanPolynomial(Polynomial polynomial);
Status add(Polynomial a, Polynomial b, Polynomial &c, bool (*comp)(int,int));
Status substract(Polynomial a, Polynomial b, Polynomial &c, bool (*comp)(int,int));
Status multi(Polynomial a, Polynomial b, Polynomial &c);
Status multiElem(Polynomial polynomial, Node* node, Polynomial &res);
bool compare(int a, int b);
Status addElem(float coef, int expn, Node* p);
void printPolynomial(Polynomial polynomial);

int main() {
    Polynomial p;
    initPolynomial(p);
    addPosition(1.0f, 0, p);
    addPosition(2.0f, 1, p);
    addPosition(3.5f, 2, p);
    printPolynomial(p);
    Polynomial q;
    initPolynomial(q);
    addPosition(1.5f, 1, q);
    addPosition(2.5f, 2, q);
    addPosition(10.0f, 4, q);
    printPolynomial(q);
    Polynomial res;
    multi(p, q, res);
    printPolynomial(res);
//    Polynomial r;
//    add(p, q, r, *compare);
//    printPolynomial(r);
//    substract(p, q, r, *compare);
//    printPolynomial(r);
    return 0;
}

Status initPolynomial(Polynomial &polynomial) {
    if(!(polynomial = (Polynomial) malloc(sizeof(Node)))) {
        return ERROR;
    }
    polynomial->next = NULL;
    return OK;
}

Status addPosition(float coef, int expn, Polynomial p) {
    while (p->next) {
        p = p->next;
    }
    Node* node = (Node*) malloc(sizeof(Node));
    node->coef = coef;
    node->expn = expn;
    node->next = p->next;
    p->next = node;
    return OK;
}

Status destroyPolynomial(Polynomial &polynomial) {
    free(polynomial);
    polynomial = NULL;
    return OK;
}

Status cleanPolynomial(Polynomial polynomial) {
    Node* p = polynomial;
    Node* q;
    p = p->next;
    while (p!= NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    polynomial->next = NULL;
    return OK;
}

Status add(Polynomial a, Polynomial b, Polynomial &c, bool (*comp)(int,int)) {
    if (!(c=(Polynomial) malloc(sizeof(Node)))) {
        return ERROR;
    }
    c->next = NULL;
    Node* d = c;
    Node *p = a->next, *q = b->next;
    while (p && q) {
        if (comp(p->expn, q->expn)) {
            addElem(p->coef+q->coef, p->expn, d);
            d = d->next;
            p = p->next;
            q = q->next;
        } else if (p->expn < q->expn) {
            addElem(p->coef, p->expn, d);
            d = d->next;
            p = p->next;
        } else {
            addElem(q->coef, q->expn, d);
            d = d->next;
            q = q->next;
        }
    }
    while (p) {
        addElem(p->coef, p->expn, d);
        d = d->next;
        p = p->next;
    }
    while (q) {
        addElem(q->coef, q->expn, d);
        d = d->next;
        q = q->next;
    }
    return OK;
}

/**
 * a-b
 * @param a
 * @param b
 * @param c
 * @param comp
 * @return
 */
Status substract(Polynomial a, Polynomial b, Polynomial &c, bool (*comp)(int,int)) {
    Node* p = b->next;
    while (p) {
        p->coef *=-1;
        p = p->next;
    }
    add(a, b, c, comp);
    return OK;
}

Status multi(Polynomial a, Polynomial b, Polynomial &c) {
    initPolynomial(c);
    Node* p = b->next;
    while (p) {
        Polynomial d,e;
        multiElem(a, p, d);
        add(c, d, e, *compare);
        c = e;
        p = p->next;
    }
    return OK;
}

Status multiElem(Polynomial polynomial, Node* node, Polynomial &res) {
    initPolynomial(res);
    Node* a = res;
    Node* p = polynomial->next;
    while (p) {
        float coef = p->coef*node->coef;
        int expn = p->expn+node->expn;
        addElem(coef, expn, a);
        a = a->next;
        p = p->next;
    }
    return OK;
}

bool compare(int a, int b) {
    if (a == b) {
        return true;
    } else {
        return false;
    }
}

Status addElem(float coef, int expn, Node* p) {
    Node* tar;
    if(!(tar = (Node*) malloc(sizeof(Node)))) {
        return ERROR;
    }
    tar->coef = coef;
    tar->expn = expn;
    tar->next = p->next;
    p->next = tar;
    return OK;
}

void printPolynomial(Polynomial polynomial) {
    Node* p = polynomial->next;
    while (p) {
        printf("%.2fx%d ", p->coef, p->expn);
        p = p->next;
    }
    printf("\n");
}