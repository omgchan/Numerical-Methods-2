#include <stdio.h>
#include <math.h>

#define h 0.1
#define a 0.0
#define b 1.5708   // pi/2
#define alpha 0.0
#define beta 1.0
#define tol 0.0001

// y'' = -y
float f1(float x, float y, float z) {
    return z;      // y' = z
}

float f2(float x, float y, float z) {
    return -y;     // z' = -y
}

// Solve IVP using RK4
float rk4(float slope) {

    float x = a, y = alpha, z = slope;
    float k1, k2, k3, k4;
    float l1, l2, l3, l4;

    while(x < b) {

        k1 = h * f1(x, y, z);
        l1 = h * f2(x, y, z);

        k2 = h * f1(x + h/2, y + k1/2, z + l1/2);
        l2 = h * f2(x + h/2, y + k1/2, z + l1/2);

        k3 = h * f1(x + h/2, y + k2/2, z + l2/2);
        l3 = h * f2(x + h/2, y + k2/2, z + l2/2);

        k4 = h * f1(x + h, y + k3, z + l3);
        l4 = h * f2(x + h, y + k3, z + l3);

        y += (k1 + 2*k2 + 2*k3 + k4) / 6;
        z += (l1 + 2*l2 + 2*l3 + l4) / 6;

        x += h;
    }

    return y;   // value at x = b
}

int main() {

    float s1 = 0.5, s2 = 1.0;
    float y1, y2, s_new;

    do {
        y1 = rk4(s1);
        y2 = rk4(s2);

        s_new = s1 + (beta - y1) * (s2 - s1) / (y2 - y1);

        if(fabs(rk4(s_new) - beta) < tol)
            break;

        s1 = s2;
        s2 = s_new;

    } while(1);

    printf("Correct Initial Slope = %.6f\n", s_new);
    printf("Solution satisfies boundary condition.\n");
    printf("\nLab No.: 16 / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}