#include<stdio.h>
#include"link_list.h"

int main() {
    LinkList L;
    rearCreateList(L, 3);
    LinkList p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
    clearList(L);

    headCreateList(L, 3);
    p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}