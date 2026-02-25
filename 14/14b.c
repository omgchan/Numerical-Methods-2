#include <stdio.h>
#include <math.h>

int main() {
    float a[3][3], b[3], x[3]={0,0,0};
    float x_old[3], error, tol;
    int i, iter=0;

    printf("Enter 3x3 coefficient matrix:\n");
    for(i=0;i<3;i++)
        scanf("%f %f %f",&a[i][0],&a[i][1],&a[i][2]);

    printf("Enter constants:\n");
    for(i=0;i<3;i++)
        scanf("%f",&b[i]);

    printf("Enter tolerance: ");
    scanf("%f",&tol);

    do {
        for(i=0;i<3;i++)
            x_old[i] = x[i];

        x[0] = (b[0] - a[0][1]*x[1] - a[0][2]*x[2]) / a[0][0];
        x[1] = (b[1] - a[1][0]*x[0] - a[1][2]*x[2]) / a[1][1];
        x[2] = (b[2] - a[2][0]*x[0] - a[2][1]*x[1]) / a[2][2];

        error = fabs(x[0]-x_old[0]) +
                fabs(x[1]-x_old[1]) +
                fabs(x[2]-x_old[2]);

        iter++;

    } while(error > tol);

    printf("\nSolution after %d iterations:\n", iter);
    printf("x = %.4f\ny = %.4f\nz = %.4f\n", x[0], x[1], x[2]);
    printf("\nLab No.: 14(b) / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}