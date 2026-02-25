//Composite Simpson's 3/8 Rule for Numerical Integration


#include<stdio.h>
float f(float x) {
    return (x*x*x + 3*x);   
}   
int main() {

    float a, h, x0, xn, term, v;
    int i, k;

    printf("Enter lower limit and upper limit: ");
    scanf("%f %f", &x0, &xn);
    printf("Enter number of subintervals: ");
    scanf("%f", &k);
    h = (xn - x0) / k;
    term = f(x0) + f(xn);

    for(i = 1; i < k; i++) {
        if(i % 3 == 0) {
            a = x0 + i*h;
            term += 2*f(a);
        } 

        a = x0 + i*h;
        term += 3*f(a);
        
    }
    v = (3*h*term)/8;
    printf("The value of integral is %f", v);
    printf("\nLab No.: 7(f) / Name: Chandan Vomjan / Roll No.:  96 / Section: C \n");
}