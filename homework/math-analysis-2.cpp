#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3
#define TOLERANCE 0.0001
#define MAX_ITERATIONS 50

void gauss_seidel(double A[N][N], double b[N], double x0[N], double x[N]) {
    int i, k;
    double x_old[N];
    double norm;

    for (i = 0; i < N; i++) {
        x[i] = x0[i];
    }

    k = 0;
    do {
        for (i = 0; i < N; i++) {
            if (i == 0) {
                x[i] = (b[i] - A[i][1] * x[1] - A[i][2] * x[2]) / A[i][i];
            } else if (i == N - 1) {
                x[i] = (b[i] - A[i][0] * x[0] - A[i][N - 2] * x[N - 2]) / A[i][i];
            } else {
                x[i] = (b[i] - A[i][0] * x[0] - A[i][1] * x[1] - A[i][N - 1] * x[N - 1]) / A[i][i];
            }
        }

        norm = 0.0;
        for (i = 0; i < N; i++) {
            norm += pow(x[i] - x_old[i], 2);
        }
        norm = sqrt(norm);

        for (i = 0; i < N; i++) {
            x_old[i] = x[i];
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

    gauss_seidel(A, b, x0, x);

    printf("解向量:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}