// WAP to find first derivative of a tabulated function
// using Newton's Divided Difference Formula

#include <stdio.h>

int main() {
    int n, i, j, k;
    float x[10], dd[10][10];
    float value, derivative = 0, term, sum;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter values of x and f(x):\n");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &dd[i][0]);
    }

    // Construct Divided Difference Table
    for(j = 1; j < n; j++) {
        for(i = 0; i < n - j; i++) {
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    printf("Enter value of x where derivative is required: ");
    scanf("%f", &value);

    // Compute derivative
    for(i = 1; i < n; i++) {
        sum = 0;

        for(k = 0; k < i; k++) {
            term = 1;
            for(j = 0; j < i; j++) {
                if(j != k)
                    term *= (value - x[j]);
            }
            sum += term;
        }

        derivative += dd[0][i] * sum;
    }

    printf("First derivative at x = %.4f is %.6f\n", value, derivative);
    printf("\nLab No.: 6(a) / Name: Chandan Vomjan / Roll No.:  96 / Section: C \n");

    return 0;
}
