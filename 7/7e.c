// Simpson's 3/8 Rule for Numerical Integration

#include<stdio.h>
float f(float x) {
    return (x*x*x);   
}

int main() {
    float x0, h, x3, v;
    int n = 3;   // Simpson's 3/8 requires n = 3
    printf("Enter lower limit and upper limit: ");
    scanf("%f %f", &x0, &x3);
    h = (x3 - x0) / n;
    v = (3*h/8) * (f(x0) + 3*f(x0 + h) + 3*f(x0 + 2*h) + f(x3));
    printf("Approximate value of integral is: %.4f\n", v);

    printf("\nLab No.: 7(e) / Name: Chandan Vomjan / Roll No.:  96 / Section: C \n");

    return 0;
}