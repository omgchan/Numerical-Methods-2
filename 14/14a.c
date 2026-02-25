#include <stdio.h>
#include <math.h>

int main() {
    float a[3][3], b[3], x[3]={0,0,0}, x_new[3];
    float error, tol;
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
            x_new[i] = (b[i]
                        - a[i][(i+1)%3]*x[(i+1)%3]
                        - a[i][(i+2)%3]*x[(i+2)%3])
                        / a[i][i];

        error = fabs(x_new[0]-x[0]) +
                fabs(x_new[1]-x[1]) +
                fabs(x_new[2]-x[2]);

        for(i=0;i<3;i++)
            x[i] = x_new[i];

        iter++;

    } while(error > tol);

    printf("\nSolution after %d iterations:\n", iter);
    printf("x = %.4f\ny = %.4f\nz = %.4f\n", x[0], x[1], x[2]);
    printf("\nLab No.: 14(a) / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}