#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k, maxRow;
    float a[10][11], x[10], temp, ratio;

    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    printf("Enter coefficients of augmented matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Forward Elimination with Partial Pivoting
    for(k = 0; k < n-1; k++) {

        // Pivoting
        maxRow = k;
        for(i = k+1; i < n; i++) {
            if(fabs(a[i][k]) > fabs(a[maxRow][k])) {
                maxRow = i;
            }
        }

        // Swap rows if needed
        if(maxRow != k) {
            for(j = 0; j <= n; j++) {
                temp = a[k][j];
                a[k][j] = a[maxRow][j];
                a[maxRow][j] = temp;
            }
        }

        // Elimination
        for(i = k+1; i < n; i++) {
            ratio = a[i][k] / a[k][k];
            for(j = 0; j <= n; j++) {
                a[i][j] = a[i][j] - ratio * a[k][j];
            }
        }
    }

    // Back Substitution
    for(i = n-1; i >= 0; i--) {
        x[i] = a[i][n];

        for(j = i+1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }

        x[i] = x[i] / a[i][i];
    }

    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i+1, x[i]);
    }

    printf("\nLab No.: 10(b) / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");    
    return 0;
}