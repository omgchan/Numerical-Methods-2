#include <stdio.h>
#include <math.h>

#define SIZE 3

int main() {

    float A[SIZE][SIZE], X[SIZE], Y[SIZE];
    float lambda = 0, lambda_old = 0;
    float tol;
    int i, j, iter = 0;

    printf("Enter 3x3 Matrix:\n");
    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            scanf("%f", &A[i][j]);

    printf("Enter Initial Vector:\n");
    for(i = 0; i < SIZE; i++)
        scanf("%f", &X[i]);

    printf("Enter Tolerance: ");
    scanf("%f", &tol);

    do {
        for(i = 0; i < SIZE; i++) {
            Y[i] = 0;
            for(j = 0; j < SIZE; j++)
                Y[i] += A[i][j] * X[j];
        }

        lambda_old = lambda;

        lambda = fabs(Y[0]);
        for(i = 1; i < SIZE; i++)
            if(fabs(Y[i]) > lambda)
                lambda = fabs(Y[i]);

        for(i = 0; i < SIZE; i++)
            X[i] = Y[i] / lambda;

        iter++;

    } while(fabs(lambda - lambda_old) > tol);

    printf("\nDominant Eigenvalue = %.6f\n", lambda);

    printf("Corresponding Eigenvector:\n");
    for(i = 0; i < SIZE; i++)
        printf("%.6f\n", X[i]);

    printf("\nNumber of iterations = %d\n", iter);
    printf("\nLab No.: 15 / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}