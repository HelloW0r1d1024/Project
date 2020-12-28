#include<stdio.h>

int main(void) {

    char a[3] = {'\0'};
    while (scanf("%c%c%c", &a[0], &a[1], &a[2]) != EOF) {
        getchar();

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2 - i; j++) {
                if (a[j] > a[j + 1]) {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                }
            }
        }

        printf("%c %c %c\n", a[0], a[1], a[2]);  
        
    }

    return 0;
}