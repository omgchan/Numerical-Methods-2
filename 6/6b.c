// WAP to find the first derivative using Newton's Forward Difference Formula

#include <stdio.h>

int main() {
    int n, i, j;
    float x[10], y[10][10];
    float h, u, value, derivative = 0;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter values of x and f(x):\n");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i][0]);
    }

    // Step size (equal spacing assumed)
    h = x[1] - x[0];

    // Construct Forward Difference Table
    for(j = 1; j < n; j++) {
        for(i = 0; i < n - j; i++) {
            y[i][j] = y[i+1][j-1] - y[i][j-1];
        }
    }

    printf("Enter value of x where derivative is required: ");
    scanf("%f", &value);

    u = (value - x[0]) / h;

    // First derivative (upto 3rd difference)
    derivative = (1/h) * (
        y[0][1]
        + ((2*u - 1)/2) * y[0][2]
        + ((3*u*u - 6*u + 2)/6) * y[0][3]
    );

    printf("First derivative at x = %.4f is %.6f\n", value, derivative);

    printf("\nLab No.: 6(b) / Name: Chandan Vomjan / Roll No.:  96 / Section: C \n");

    return 0;
}
