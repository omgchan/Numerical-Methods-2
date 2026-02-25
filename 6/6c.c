#include<stdio.h>

int main() {
    int n, i, j;
    float x[10], y[10][10];
    float h, u, value, derivative;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter values of x and f(x):\n");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i][0]);
    }

    h = x[1] - x[0];   // Equal spacing assumed

    // Construct Backward Difference Table
    for(j = 1; j < n; j++) {
        for(i = n-1; i >= j; i--) {
            y[i][j] = y[i][j-1] - y[i-1][j-1];
        }
    }

    printf("Enter value of x where derivative is required: ");
    scanf("%f", &value);

    u = (value - x[n-1]) / h;

    // First derivative formula (upto 3rd difference)
    derivative = (1/h) * (
        y[n-1][1]
        + ((2*u + 1)/2) * y[n-1][2]
        + ((3*u*u + 6*u + 2)/6) * y[n-1][3]
    );

    printf("First derivative at x = %.4f is %.6f\n", value, derivative);
    printf("\nLab No.: 6(c) / Name: Chandan Vomjan / Roll No.:  96 / Section: C \n");

    return 0;
}
