#include<stdio.h>

int main() {
    int x;
    char chs[] = "EEEEEEDCBAA";

    while (~scanf("%d", &x)) {
        if (x < 0 || x > 100)
            printf("Score is error!\n");
        else
            printf("%c\n", chs[x / 10]);
    }

    return 0;
}