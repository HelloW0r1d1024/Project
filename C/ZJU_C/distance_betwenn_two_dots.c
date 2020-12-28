/* 习题5-3 使用函数计算两点间的距离
 * 题目要求：本题要求实现一个函数，对给定平面任意两点坐标(x1, y1) (x2, y2)，求这两点之间的距离。
 * 输入样例：10 10 200 100
 * 输出样例：dist = 210.24
 */ 

#include<stdio.h>
#include<math.h>

double dist(double x1, double y1, double x2, double y2);

int main(void) {
    double x1, y1;
    double x2, y2;

    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    printf("dist = %.2lf\n", dist(x1, y1, x2, y2));

    return 0;
}

double dist(double x1, double y1, double x2, double y2) {
    double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    return dist;
}