/* 练习5-3 数字金字塔 
 * 题目要求：本题要求实现函数输出n行数字金字塔。
 * 输入样例：5
 * 输出样例 ：     
 *     1 
      2 2 
     3 3 3 
    4 4 4 4 
   5 5 5 5 5 
 */ 

#include<stdio.h>

void pyramid(int n);

int main(void) {
    int n;

    scanf("%d", &n);
    pyramid(n);

    return 0;
}

void pyramid(int n) {
    for(int i = 1;i <= n;i++) {     //第一层for循环：打印n行
        for(int j = 1;j <= n - i;j++)   putchar(' ');   //先打印n - i 个空格
        for(int k = 1;k <= i;k++)   printf("%d ", i);   //行数是几就要打印几次行数
        putchar('\n');
    }
}