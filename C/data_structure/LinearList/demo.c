#include<stdio.h>

int max(int a, int b);
int min(int a, int b);

int main(void) {
    int a, b;
    int (* cmp)(int, int);
    int x;
    printf("求最大值请按1，求最小值请按2\n");
    scanf("%d", &x);
    if (1 == x)
        cmp = max;
    else if (2 == x)
        cmp = min;

    scanf("%d %d", &a, &b);

    printf("%d", (* cmp)(a, b));

    return 0;
}

int max(int a, int b) {
    return a > b? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}