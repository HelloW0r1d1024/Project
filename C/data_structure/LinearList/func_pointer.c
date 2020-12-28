#include<stdio.h>

int max(int a, int b);

int main(void) {
    int a, b;
    /* definition form of func_ptr:
     * return_type (*ptr_name)(param list);
     */
    printf("%p", max);
    int (* func_ptr)(int, int) = max;
    scanf("%d %d", &a, &b);

    printf("%d", (*func_ptr)(a, b));

    return 0;
}

int max(int a, int b) {
    return a > b? a : b;
}