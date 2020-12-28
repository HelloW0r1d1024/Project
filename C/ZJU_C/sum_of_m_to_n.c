/* 练习5-1 求m到n之和
 * 题目要求：本题要求实现一个计算m~n（m<n）之间所有整数的和的简单函数。
 * 输入样例：  -5   8
 * 输出样例：  sum = 21
 */

#include<stdio.h>

int sum(int m, int n);

int main(void) {
    int m, n;

    scanf("%d %d", &m, &n);
    printf("sum = %d\n", sum(m, n));

    return 0;
}

int sum(int m, int n) {
    int sum = 0;
    while(m <= n) 
        sum += m++;
    return sum;
}