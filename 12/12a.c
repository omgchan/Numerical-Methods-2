#include <stdio.h>

int main() {
    int n, i, j, k;
    float A[10][10], L[10][10] = {0}, U[10][10] = {0}, sum;

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter elements of matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    for(i = 0; i < n; i++) {

        // Upper Triangular Matrix U
        for(j = i; j < n; j++) {
            sum = 0;
            for(k = 0; k < i; k++)
                sum += L[i][k] * U[k][j];

            U[i][j] = A[i][j] - sum;
        }

        // Lower Triangular Matrix L
        for(j = i; j < n; j++) {
            if(i == j)
                L[i][i] = 1;   // Diagonal = 1
            else {
                sum = 0;
                for(k = 0; k < i; k++)
                    sum += L[j][k] * U[k][i];

                L[j][i] = (A[j][i] - sum) / U[i][i];
            }
        }
    }

    printf("\nLower Triangular Matrix L:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%.4f ", L[i][j]);
        printf("\n");
    }

    printf("\nUpper Triangular Matrix U:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%.4f ", U[i][j]);
        printf("\n");
    }
    printf("\nLab No.: 12(a) / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}