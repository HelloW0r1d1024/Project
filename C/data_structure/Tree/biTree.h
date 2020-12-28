#include<stdio.h>
#include<stdlib.h>
#include"status.h"
#define TElemType char

typedef struct BiTNode{
    TElemType data;
    struct BiTNode * lChild, * rChild;
}BiTNode, * BiTree;

Status printElem(TElemType e) {
    printf("%c", e);
    return OK;
}

Status CreateBiTree(BiTree &T) {
    char ch;
    ch = getchar();

    if (' ' == ch) 
        T = NULL;
    else {
        if (!(T = (BiTree)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        T->data = ch;
        CreateBiTree(T->lChild);
        CreateBiTree(T->rChild);
    }

    return OK;
}

Status InOrderTraverse(BiTree T, Status(* visit)(TElemType e)) {
    if (T) {
        InOrderTraverse(T->lChild, visit);
        (* visit)(T->data);
        InOrderTraverse(T->rChild, visit);
    } else return ERROR;

    return OK;
}