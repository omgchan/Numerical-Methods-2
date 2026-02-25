#include <stdio.h>

int main() {
    int n, i, j, k;
    float a[10][11], ratio;

    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    printf("Enter coefficients of augmented matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for(i = 0; i < n; i++) {

        // Make pivot element = 1
        float pivot = a[i][i];
        for(j = 0; j <= n; j++) {
            a[i][j] = a[i][j] / pivot;
        }

        // Make other elements in column = 0
        for(k = 0; k < n; k++) {
            if(k != i) {
                ratio = a[k][i];
                for(j = 0; j <= n; j++) {
                    a[k][j] = a[k][j] - ratio * a[i][j];
                }
            }
        }
    }

    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i+1, a[i][n]);
    }
    printf("\nLab No.: 10(c) / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}