// WAP to implement Romberg Integration Formula

#include<stdio.h>
#include<math.h>

// Define the function here
float f(float x) {
    return x*x;   // Example function
}

int main() {

    int i, j, n;
    float a, b;
    float R[10][10];
    float h, sum;

    printf("Enter lower limit and upper limit: ");
    scanf("%f %f", &a, &b);

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    // Initial trapezoidal approximation
    h = b - a;
    R[0][0] = (h/2) * (f(a) + f(b));

    for(i = 1; i <= n; i++) {

        h = h / 2;
        sum = 0;

        // Add new points
        for(j = 1; j <= pow(2, i-1); j++) {
            sum += f(a + (2*j - 1) * h);
        }

        R[i][0] = 0.5 * R[i-1][0] + h * sum;

        // Richardson Extrapolation
        for(j = 1; j <= i; j++) {
            R[i][j] = (pow(4, j) * R[i][j-1] - R[i-1][j-1]) 
                      / (pow(4, j) - 1);
        }
    }

    printf("\nRomberg Integration Result = %.6f\n", R[n][n]);

    printf("\nLab No.: 8(a) / Name: Chandan Vomjan / Roll No.:  96 / Section: C \n");

    return 0;
}