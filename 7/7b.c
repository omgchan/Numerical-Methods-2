#include<stdio.h>
float f(float x) {
    return (3*x*x + 2*x -5);   
}

int main() {
    int i, k;

    float a, h, x0, xn, term, v;
    printf("Enter upper limit and lower limit: ");
    scanf("%f %f", &xn, &x0);

    printf("Enter number of subintervals: ");
    scanf("%f", &k);
    h = (xn - x0) / k;
    
    term = f(x0) + f(xn);
    for(i = 1; i < k; i++) {
        a = x0 + i*h;
        term += 2*f(a);
    }
    printf("Approximate value of integral is: %.4f\n", (h/2) * term);
    printf("\nLab No.: 7(b) / Name: Chandan Vomjan / Roll No.:  96 / Section: C \n");


    return 0;
}