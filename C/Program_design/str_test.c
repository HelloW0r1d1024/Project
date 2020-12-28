#include<stdio.h>

int main(void) {
    char str[6] = "AB1234";

    for (int i = 0; i < 10; i++) {
        printf("%d:%c\n", i, str[i]);
    }

    gets(str);
    for (int i = 0; i < 10; i++) {
        printf("%d:%c\n", i, str[i]);
    }

    
}