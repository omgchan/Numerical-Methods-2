#include <stdio.h>
#include <math.h>

#define N 5
#define MAX_ITER 100
#define TOL 0.001

int main() {

    float u[N][N] = {0};
    float f[N][N] = {0};
    float error;
    int i, j, iter, choice;

    printf("Choose Equation:\n");
    printf("1. Laplace Equation\n");
    printf("2. Poisson Equation\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 2) {
        printf("Enter source function values f(i,j) for interior points:\n");
        for(i = 1; i < N-1; i++)
            for(j = 1; j < N-1; j++)
                scanf("%f", &f[i][j]);
    }

    for(iter = 0; iter < MAX_ITER; iter++) {

        error = 0;

        for(i = 1; i < N-1; i++) {
            for(j = 1; j < N-1; j++) {

                float old = u[i][j];

                if(choice == 1) {   // Laplace
                    u[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] +
                                      u[i][j+1] + u[i][j-1]);
                }
                else if(choice == 2) {  // Poisson
                    u[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] +
                                      u[i][j+1] + u[i][j-1]
                                      - f[i][j]);
                }

                error += fabs(u[i][j] - old);
            }
        }

        if(error < TOL)
            break;
    }

    printf("\nSolution after %d iterations:\n", iter);

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++)
            printf("%.4f ", u[i][j]);
        printf("\n");
    }

    printf("\nLab No.: 17 / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");
    return 0;
}