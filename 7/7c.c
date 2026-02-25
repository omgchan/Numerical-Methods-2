// Simpson's 1/3 Rule for Numerical Integration

#include<stdio.h>

float f(float x) {
    return (3*x*x + 2*x - 5);   
}

int main() {

    float x0, x2, x1, h, integral;
    int n = 2;   // Simpson's 1/3 requires n = 2

    printf("Enter lower limit and upper limit: ");
    scanf("%f %f", &x0, &x2);

    h = (x2 - x0) / n;
    x1 = x0 + h;

    integral = (h/3) * (f(x0) + 4*f(x1) + f(x2));

    printf("Approximate value of integral = %.4f\n", integral);

    printf("\nLab No.: 7(c) / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}
