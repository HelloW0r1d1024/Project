#include<stdio.h>
#include<stdlib.h>
#include"status.h"

#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode * next;
} * LinkList;

Status GetElem(LinkList L, int i, ElemType &e) {
    LinkList p = L->next;
    int j = 1;
    
    while (p && j < i) {
        p = p->next;
        j++;
    }

    if (!p || j > i)
        return ERROR;
    e = p->data;

    return OK;
}

Status LinkInsert(LinkList &L, int i, ElemType e) {
    LinkList p = L;
    int j = 0;

    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return ERROR;

    LinkList q = (LinkList)malloc(sizeof(LNode));
    if (NULL == q)
        return ERROR;

    q->next = p->next;
    q->data = e;
    p->next = q;

    return OK;
}

Status LinkDelete(LinkList &L, int i, ElemType &e) {
    LinkList p = L;
    int j = 0;

    while (p && j < i - 1) {
        p = p->next;
        j++;
    }

    if (!p || j > i - 1)
        return ERROR;
    
    LinkList q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);

    return OK; 
}

void clearList(LinkList &L) {
    LinkList p;

    while (L->next) {
        p = L->next;
        L->next = p->next;
        free(p);
    }
}

void headCreateList(LinkList &L, int n) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    for (int i = 0; i < n; i++) {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &(p->data));
        p->next = L->next;
        L->next = p;
    }
}

void rearCreateList(LinkList &L, int n) {
    L = (LinkList)malloc(sizeof(LNode));
    LinkList p = L;
    L->next = NULL;

    for (int i = 0; i < n; i++) {
        LinkList q = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &(q->data));
        /*p->next = q;
        p = q;
        p->next = NULL;*/
        q->next = p->next;
        p->next = q;
        p = q;
    }
}