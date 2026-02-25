#include<stdio.h>
float f(float x) {
    return x + 2;   // Example: f(x) = x^2
}

int main() {
    float h,x0, xn, v;
    printf("Enter upper limit and lower limit: ");
    scanf("%f %f", &xn, &x0);

    h = (xn - x0);
    v = (h/2) * (f(x0) + f(xn));
    printf("Approximate value of integral is: %.4f\n", v);

    printf("\nLab No.: 7(a) / Name: Chandan Vomjan / Roll No.:  96 / Section: C \n");  

    return 0;
}