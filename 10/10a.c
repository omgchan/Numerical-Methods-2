#include <stdio.h>

int main() {
    int n, i, j, k;
    float a[10][10], x[10], ratio;

    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    printf("Enter coefficients of augmented matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Forward Elimination
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {

            ratio = a[j][i] / a[i][i];

            for(k = 0; k <= n; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    x[n-1] = a[n-1][n] / a[n-1][n-1];

    for(i = n-2; i >= 0; i--) {
        x[i] = a[i][n];

        for(j = i+1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }

        x[i] = x[i] / a[i][i];
    }

    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i+1, x[i]);
    }
    printf("\nLab No.: 10(a) / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}