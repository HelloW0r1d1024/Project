#include<stdio.h>
#include<stdlib.h>
#include"Status.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define SElemType int

typedef struct {
    SElemType * base;
    SElemType * top;
    int stackSize;
} SqStack;

Status InitStack (SqStack &S) {
    S.base = (SElemType *)malloc(STACK_INIT_SIZE);
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stackSize = STACK_INIT_SIZE;

    return OK;
}

Status Push(SqStack &S, SElemType e) {
    if (S.top - S.base >= S.stackSize) {
        S.base = (SElemType *)realloc(S.base, (S.stackSize + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stackSize;
        S.stackSize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e) {
    
}