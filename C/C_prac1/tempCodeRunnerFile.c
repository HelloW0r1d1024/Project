#include<stdio.h>
#include<math.h>

#define PI 3.1415927

int main() {
    float r;

    while (scanf("%f", &r) != EOF) {
        printf("%.3f\n", (4 * PI * pow(r, 3)) / 3.0);
    }

    return 0;
}