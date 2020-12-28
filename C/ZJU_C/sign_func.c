/* 习题5-1 符号函数
 * 题目要求：本题要求实现符号函数sign(x)。
 * 输入样例：10
 * 输出样例：sign(x) = 1
 */ 

#include<stdio.h>

int sign(int x);

int main(void) {
    int x;

    scanf("%d", &x);
    printf("sign(x) = %d\n", sign(x));

    return 0;
}

int sign(int x) {
    if(0 == x)
        return 0;
    else
        return x > 0? 1 : -1;
}