#include <stdio.h>
#include <math.h>

int main() {
    int choice, i, j, k;
    float A[3][3], B[3], X[3];

    printf("Enter 3x3 Coefficient Matrix A:\n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%f",&A[i][j]);

    printf("Enter Constant Matrix B:\n");
    for(i=0;i<3;i++)
        scanf("%f",&B[i]);

    printf("\nChoose Method:\n");
    printf("1. Matrix Inversion Method\n");
    printf("2. Doolittle LU Decomposition\n");
    printf("3. Cholesky Decomposition\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch(choice) {

    // ---------------- MATRIX INVERSION ----------------
    case 1: {
        float inv[3][3], det;

        det = A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])
            - A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])
            + A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);

        if(det == 0) {
            printf("Matrix is singular!\n");
            return 0;
        }

        inv[0][0]=(A[1][1]*A[2][2]-A[1][2]*A[2][1])/det;
        inv[0][1]=(A[0][2]*A[2][1]-A[0][1]*A[2][2])/det;
        inv[0][2]=(A[0][1]*A[1][2]-A[0][2]*A[1][1])/det;

        inv[1][0]=(A[1][2]*A[2][0]-A[1][0]*A[2][2])/det;
        inv[1][1]=(A[0][0]*A[2][2]-A[0][2]*A[2][0])/det;
        inv[1][2]=(A[0][2]*A[1][0]-A[0][0]*A[1][2])/det;

        inv[2][0]=(A[1][0]*A[2][1]-A[1][1]*A[2][0])/det;
        inv[2][1]=(A[0][1]*A[2][0]-A[0][0]*A[2][1])/det;
        inv[2][2]=(A[0][0]*A[1][1]-A[0][1]*A[1][0])/det;

        for(i=0;i<3;i++) {
            X[i]=0;
            for(j=0;j<3;j++)
                X[i]+=inv[i][j]*B[j];
        }

        break;
    }

    // ---------------- DOOLITTLE LU ----------------
    case 2: {
        float L[3][3]={0}, U[3][3]={0}, Y[3];

        for(i=0;i<3;i++) {
            for(k=i;k<3;k++) {
                float sum=0;
                for(j=0;j<i;j++)
                    sum+=L[i][j]*U[j][k];
                U[i][k]=A[i][k]-sum;
            }

            for(k=i;k<3;k++) {
                if(i==k)
                    L[i][i]=1;
                else {
                    float sum=0;
                    for(j=0;j<i;j++)
                        sum+=L[k][j]*U[j][i];
                    L[k][i]=(A[k][i]-sum)/U[i][i];
                }
            }
        }

        // Forward substitution LY=B
        for(i=0;i<3;i++) {
            float sum=0;
            for(j=0;j<i;j++)
                sum+=L[i][j]*Y[j];
            Y[i]=B[i]-sum;
        }

        // Backward substitution UX=Y
        for(i=2;i>=0;i--) {
            float sum=0;
            for(j=i+1;j<3;j++)
                sum+=U[i][j]*X[j];
            X[i]=(Y[i]-sum)/U[i][i];
        }

        break;
    }

    // ---------------- CHOLESKY ----------------
    case 3: {
        float L[3][3]={0}, Y[3];

        for(i=0;i<3;i++) {
            for(j=0;j<=i;j++) {
                float sum=0;
                for(k=0;k<j;k++)
                    sum+=L[i][k]*L[j][k];

                if(i==j)
                    L[i][j]=sqrt(A[i][i]-sum);
                else
                    L[i][j]=(A[i][j]-sum)/L[j][j];
            }
        }

        // Forward substitution LY=B
        for(i=0;i<3;i++) {
            float sum=0;
            for(j=0;j<i;j++)
                sum+=L[i][j]*Y[j];
            Y[i]=(B[i]-sum)/L[i][i];
        }

        // Back substitution LᵀX=Y
        for(i=2;i>=0;i--) {
            float sum=0;
            for(j=i+1;j<3;j++)
                sum+=L[j][i]*X[j];
            X[i]=(Y[i]-sum)/L[i][i];
        }

        break;
    }

    default:
        printf("Invalid choice!\n");
        return 0;
    }

    printf("\nSolution:\n");
    for(i=0;i<3;i++)
        printf("X%d = %.4f\n",i+1,X[i]);

    printf("\nLab No.: 13 / Name: Chandan Vomjan / Roll No.: 96 / Section: C\n");

    return 0;
}