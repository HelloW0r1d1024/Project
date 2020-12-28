#include<stdio.h>

int main() {
    double x;

    while (scanf("%lf", &x) != EOF) {
        if (x < 0)
            x *= -1;
        printf("%.2lf\n", x);
    }
    
    return 0;
}