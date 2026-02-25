#include <stdio.h>

// Function dy/dx = f(x, y)
float f(float x, float y) {
    return x + y;
}

int main() {
    float x0, y0, h, xn, x, y;
    float k1, k2, k3, k4;
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

        k1 = h * f(x, y);
        k2 = h * f(x + h/2, y + k1/2);
        k3 = h * f(x + h/2, y + k2/2);
        k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x = x + h;

        printf("Step %d: x = %.2f, y = %.5f\n", i+1, x, y);
    }

    printf("\nApproximate value of y at x = %.2f is %.5f\n", x, y);

    printf("\nLab No.: 9(e) / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");
    return 0;
}