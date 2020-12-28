#include <stdio.h>

void pyramid( int n );

int main()
{    
    int n;

    scanf("%d", &n);
    pyramid(n);

    return 0;
}

void pyramid(int n) {
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < n - i;j++) putchar(' ');
        for(int k = 1;k <= i;k++) {
            printf("%d",i);
            if(k != i)
                putchar(' ');
        }
        printf("\n");
    }
}