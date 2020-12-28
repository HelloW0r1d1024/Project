#include<stdio.h>
#include<math.h>

int narcissistic(int number);

int main(void) {
    if(narcissistic(370))
        printf("Yes");
    else
        printf("No");    
}

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