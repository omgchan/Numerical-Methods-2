#include<stdio.h>

float f(float x) {
    return x * x; // Example function: f(x) = x^2
}

int main() {

    float centralFirst, centralSecond, h, x;
    printf("Enter the point at which derivative is to be calculated: ");
    scanf("%f", &x);

    printf("Enter the value of h (small increment): ");
    scanf("%f", &h);

    centralFirst = (f(x + h) - f(x - h)) / (2 * h);     
    centralSecond = (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);

    printf("Central Difference Approximation of f' at x = %.4f is: %.4f\n", x, centralFirst);
    printf("Central Difference Approximation of f'' at x = %.4f is: %.4f\n", x, centralSecond);

    printf("\nLab No.: 5(b) / Name: Chandan Vomjan / Roll No.:  96 / Section: C \n");

    return 0;
}
