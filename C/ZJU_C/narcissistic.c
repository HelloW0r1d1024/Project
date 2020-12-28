#include <stdio.h>
#include<math.h>
int narcissistic( int number );
void PrintN( int m, int n );

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

/* 你的代码将被嵌在这里 */
int narcissistic(int number) {
    int temp = number; //使用临时的一个变量代替number
    int digit[10]; //存放number的每一位
    int cnt = 0; //number的位数
    int sum = 0; //位的位次幂和
    int i = 0;
    
    while(temp) {
        digit[i] = temp % 10;
        cnt++;
        i++;
        temp /= 10; //剔除当前个位
    }
    
    for(i = 0;i < cnt;i++) {
        sum += pow(digit[i], cnt);
    }

    return sum == number ? 1 : 0;
}

void PrintN(int m, int n) {
    m++;
    while(m < n) {
        if(narcissistic(m))
            printf("%d\n", m);
        m++;
    }
}
