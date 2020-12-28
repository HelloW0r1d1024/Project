/* 习题5-4 使用函数求素数和
 * 题目要求：本题要求实现一个判断素数的简单函数、以及利用该函数计算给定区间内素数和的函数。
 *          素数就是只能被1和自身整除的正整数。注意：1不是素数，2是素数。
 * 输入样例：-1 10
 * 输出样例：Sum of ( 2 3 5 7 ) = 17
 */ 

#include <stdio.h>
#include <math.h>

int prime(int p );     //判断数p是否为素数 是素数返回1，是合数返回0
int PrimeSum(int m, int n );    //计算m ~ n之间所有素数之和

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p = m; p <= n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

int prime(int p) {
    //素数一定是大于1的正整数
    if(1 == p || p <= 0) //也可以写为 p <= 1
        return 0;
    
    for(int i = 2;i <= sqrt(p);i++) {   //只要2 ~ sqrt(p)中间出现了p的因数，则p一定为合数
        if(0 == p % i) 
            return 0;
    }
    return 1;

}

int PrimeSum( int m, int n ) {
    int sum = 0;
    
    if(m == n) 
        return prime(m) == 1? m : 0;
    else {
        while(m <= n) {
            if(prime(m))
                sum += m;   //此处不可写为 sum += m++; 因为如果m不是素数的话m是不会自增的
            m++;            //以后尽量避免使用这种写法
        }
    }
    return sum;
}