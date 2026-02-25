#include <stdio.h>
#include <math.h>

int main() {
    float x, y;

    printf("Enter the value of x: ");
    scanf("%f", &x);

    // Third approximation of Picard's method
    y = 1 + x + x*x + (x*x*x)/6;

    printf("Approximate solution at x = %.2f is %.4f\n", x, y);
    printf("\nLab No.: 9(b) / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}