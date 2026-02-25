#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float A[10][10], L[10][10] = {0}, sum;

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter elements of symmetric positive definite matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Cholesky Decomposition
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            sum = 0;

            if(i == j) {
                // Diagonal elements
                for(k = 0; k < j; k++)
                    sum += L[j][k] * L[j][k];
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                // Off-diagonal elements
                for(k = 0; k < j; k++)
                    sum += L[i][k] * L[j][k];
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }

    printf("\nLower Triangular Matrix L:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++)
            printf("%.4f ", L[i][j]);
        printf("\n");
    }
    printf("Lab No.: 12(b) / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}