#include<stdio.h>
float f(float x) {
    return (3*x*x + 2*x -5);   
}


int main() {
    int i, k;

    float a, h, x0, xn, term, v;
    printf("Enter lower limit and upper limit: ");
    scanf("%f %f", &x0, &xn);
    printf("Enter number of subintervals: ");
    scanf("%f", &k);
    h = (xn - x0) / k;
    term = f(x0) + f(xn);
    for(i = 1; i < k; i++) {
        if(i % 2 == 0) {
            a = x0 + i*h;
            term += 2*f(a);
        } 

        a = x0 + i*h;
        term += 4*f(a);
        
    }
    v = (h/3) * term;

    printf("Approximate value of integral is: %.4f\n", v);
    printf("\nLab No.: 7(d) / Name: Chandan Vomjan / Roll No.:  96 / Section: C \n");
    return 0;
}