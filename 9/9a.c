#include <stdio.h>
#include <math.h>

// Given differential equation dy/dx = x + y
float f(float x, float y) {
    return (x + y);
}

// Second derivative y''
float f2(float x, float y) {
    return (1 + x + y);
}

int main() {
    float x0, y0, h, xn, y;
    
    printf("Enter initial value of x0 and y0: ");
    scanf("%f %f", &x0, &y0);
    
    printf("Enter step size (h): ");
    scanf("%f", &h);
    
    printf("Enter value of x at which y is required: ");
    scanf("%f", &xn);
    
    while (x0 < xn) {
        y = y0 + h * f(x0, y0) + (h * h / 2) * f2(x0, y0);
        y0 = y;
        x0 = x0 + h;
    }
    
    printf("Approximate value of y at x = %.2f is %.4f\n", xn, y0);
    printf("\nLab No.: 9(a) / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");
    
    return 0;
}