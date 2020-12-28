/* 练习5-2 找两个数中最大者
 * 题目要求：本题要求对两个整数a和b，输出其中较大的数。
 * 输入样例：-5  8
 * 输出样例：max = 8
 */ 

#include <stdio.h>

int max( int a, int b );

int main()
{    
    int a, b;

    scanf("%d %d", &a, &b);
    printf("max = %d\n", max(a, b));

    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}