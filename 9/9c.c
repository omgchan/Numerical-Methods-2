#include <stdio.h>

// Function representing dy/dx = f(x, y)
float f(float x, float y) {
    return x + y;
}

int main() {
    float x0, y0, h, xn, x, y;
    int n, i;

    printf("Enter initial value of x (x0): ");
    scanf("%f", &x0);

    printf("Enter initial value of y (y0): ");
    scanf("%f", &y0);

    printf("Enter step size (h): ");
    scanf("%f", &h);

    printf("Enter final value of x (xn): ");
    scanf("%f", &xn);

    n = (xn - x0) / h;

    x = x0;
    y = y0;

    for(i = 0; i < n; i++) {
        y = y + h * f(x, y);
        x = x + h;

        printf("Step %d: x = %.2f, y = %.4f\n", i+1, x, y);
    }

    printf("\nApproximate value of y at x = %.2f is %.4f\n", x, y);
    printf("\nLab No.: 9(c) / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}