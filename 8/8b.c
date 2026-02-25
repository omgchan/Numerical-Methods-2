// WAP to implement Numerical Double Integration using Trapezoidal Rule

#include<stdio.h>

// Define function here
float f(float x, float y) {
    return x * y;   // Example function
}

int main() {

    int i, j, n, m;
    float a, b, c, d;
    float h, k, sum = 0, x, y;

    printf("Enter lower and upper limits for x (a b): ");
    scanf("%f %f", &a, &b);

    printf("Enter lower and upper limits for y (c d): ");
    scanf("%f %f", &c, &d);

    printf("Enter number of intervals for x and y: ");
    scanf("%d %d", &n, &m);

    h = (b - a) / n;
    k = (d - c) / m;

    for(i = 0; i <= n; i++) {
        x = a + i * h;

        for(j = 0; j <= m; j++) {
            y = c + j * k;

            if((i == 0 || i == n) && (j == 0 || j == m))
                sum += f(x, y);          // Corner points
            else if(i == 0 || i == n || j == 0 || j == m)
                sum += 2 * f(x, y);      // Edge points
            else
                sum += 4 * f(x, y);      // Interior points
        }
    }

    float integral = (h * k / 4) * sum;

    printf("\nApproximate value of double integral = %.6f\n", integral);
    printf("\nLab No.: 8(b) / Name: Chandan Vomjan / Roll No.:  96 / Section: C \n");

    return 0;
}