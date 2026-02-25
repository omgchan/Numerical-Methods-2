#include <stdio.h>

int main() {
    int n, i, j, k;
    float a[10][20], ratio;

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter elements of matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Form augmented matrix [A | I]
    for(i = 0; i < n; i++) {
        for(j = n; j < 2*n; j++) {
            if(j == i + n)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }

    // Gauss-Jordan Elimination
    for(i = 0; i < n; i++) {

        float pivot = a[i][i];

        if(pivot == 0) {
            printf("Matrix is singular, inverse does not exist.\n");
            return 0;
        }

        // Make pivot = 1
        for(j = 0; j < 2*n; j++) {
            a[i][j] = a[i][j] / pivot;
        }

        // Make other elements 0
        for(k = 0; k < n; k++) {
            if(k != i) {
                ratio = a[k][i];
                for(j = 0; j < 2*n; j++) {
                    a[k][j] = a[k][j] - ratio * a[i][j];
                }
            }
        }
    }

    printf("\nInverse Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = n; j < 2*n; j++) {
            printf("%.4f ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nLab No.: 11 / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}