#include"biTree.h"

int main() {
    BiTree T;
    CreateBiTree(T);
    InOrderTraverse(T, printElem);
}