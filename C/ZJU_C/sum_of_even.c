/* 习题5-2 使用函数求奇数和
 * 题目要求：本题要求实现一个函数，计算N个整数中所有奇数的和，同时实现一个判断奇偶性的函数。
 * 输入样例：6 2 -3 7 88 0 15
 * 输出样例：Sum of ( -3 7 15 ) = 19 
 */ 

#include <stdio.h>

#define MAXN 10

int even( int n );
int OddSum( int List[], int N );

int main()
{    
    int List[MAXN], N, i;

    scanf("%d", &N);
    printf("Sum of ( ");
    for ( i=0; i<N; i++ ) {
        scanf("%d", &List[i]);
        if ( even(List[i])==0 )
            printf("%d ", List[i]);
    }
    printf(") = %d\n", OddSum(List, N));

    return 0;
}

int even(int n) {
    if(0 == n % 2)
        return 1;
    else
        return 0;
}

int OddSum( int List[], int N ) {
    int sum = 0;
    int *start = List;
    for(int i = 0;i < N;i++) {
        if(!even(*start))
            sum += *start;
        start++;
    }
    
    return sum;
}