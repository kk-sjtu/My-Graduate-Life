
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3
#define TOLERANCE 0.0001
#define MAX_ITERATIONS 50
void jacobi(double A[N][N], double b[N], double x0[N], double x[N]) {
    int i, j, k;
    double x_new[N];
    double norm;
    for (i = 0; i < N; i++) {
        x[i] = x0[i];
    }
    k = 0;
    do {
        for (i = 0; i < N; i++) {
            double sum = 0.0;
            for (j = 0; j < N; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }
        norm = 0.0;
        for (i = 0; i < N; i++) {
            norm += pow(x_new[i] - x[i], 2);
        }
        norm = sqrt(norm);

        for (i = 0; i < N; i++) {
            x[i] = x_new[i];
        }

        k++;
    } while (norm > TOLERANCE && k < MAX_ITERATIONS);

    if (k == MAX_ITERATIONS) {
        printf("迭代次数已达上限\n");
    }
    printf("迭代次数: %d\n", k);
}

int main() {
    double A[N][N] = {{5, 2, 1}, {-1, 4, 2}, {2, -3, 10}};
    double b[N] = {-12, 20, 3};
    double x0[N] = {1, 1, 1};
    double x[N];

    jacobi(A, b, x0, x);

    printf("解向量:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}