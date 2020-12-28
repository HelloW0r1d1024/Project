/* 习题5-5 使用函数统计指定数字的个数
 * 题目要求：本题要求实现一个统计整数中指定数字的个数的简单函数。
 * 输入样例：-21252 2
 * 输出样例：Number of digit 2 in -21252: 3
 */ 

#include <stdio.h>

int CountDigit( int number, int digit );

int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

    return 0;
}

int CountDigit(int number, int digit) {
    if(number < 0)
        number *= -1;
    if(0 == number && number == digit)
        return 1;
    
    int cnt = 0;
    
    do {
        if(digit == number%10)
            cnt++;
    } while(number /= 10);
    
    return cnt;
}