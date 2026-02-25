// WAP to compute numerical integration using
// Gauss-Legendre Two-Point and Three-Point Formula

#include <stdio.h>
#include <math.h>

// Define the function here
float f(float x) {
    return x * x;   // Example: f(x) = x^2
}

int main() {

    float a, b;
    float I2, I3;
    float t1, t2, t3;
    float x1, x2, x3;

    printf("Enter lower limit (a) and upper limit (b): ");
    scanf("%f %f", &a, &b);

    // ----------------------------
    // Two-Point Gauss-Legendre
    // ----------------------------
    t1 = -1.0 / sqrt(3);
    t2 =  1.0 / sqrt(3);

    x1 = ((b - a) / 2) * t1 + (a + b) / 2;
    x2 = ((b - a) / 2) * t2 + (a + b) / 2;

    I2 = ((b - a) / 2) * (f(x1) + f(x2));

    // ----------------------------
    // Three-Point Gauss-Legendre
    // ----------------------------
    t1 = -sqrt(3.0 / 5.0);
    t2 = 0;
    t3 =  sqrt(3.0 / 5.0);

    x1 = ((b - a) / 2) * t1 + (a + b) / 2;
    x2 = ((b - a) / 2) * t2 + (a + b) / 2;
    x3 = ((b - a) / 2) * t3 + (a + b) / 2;

    I3 = ((b - a) / 2) * (
            (5.0/9.0) * f(x1)
          + (8.0/9.0) * f(x2)
          + (5.0/9.0) * f(x3)
         );

    printf("\nTwo-Point Gauss Result = %.6f\n", I2);
    printf("Three-Point Gauss Result = %.6f\n", I3);

    printf("\nLab No.: 7(g) / Name: Chandan Vomjan / Roll No.:  96 / Section: C \n");


    return 0;
}
