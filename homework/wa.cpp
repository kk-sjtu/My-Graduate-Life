#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3
#define TOLERANCE 5e-6
#define MAX_ITERATIONS 1000

void sor(double A[N][N], double b[N], double x[N], double w, int *iterations) {
    int i, j, k;
    double x_old[N];
    double norm;

    for (i = 0; i < N; i++) {
        x[i] = 0; // Initialize x to zero
    }

    k = 0;
    do {
        for (i = 0; i < N; i++) {
            double sum = b[i];
            for (j = 0; j < N; j++) {
                if (j != i) {
                    sum -= A[i][j] * x[j];
                }
            }
            x_old[i] = x[i];
            x[i] = (1 - w) * x[i] + (w / A[i][i]) * sum;
        }

        norm = 0.0;
        for (i = 0; i < N; i++) {
            norm = fmax(norm, fabs(x[i] - x_old[i]));
        }

        k++;
    } while (norm >= TOLERANCE && k < MAX_ITERATIONS);

    *iterations = k;
}

int main() {
    double A[N][N] = {{4, -1, 0}, {-1, 4, -1}, {0, -1, 4}};
    double b[N] = {1, 4, -3};
    double x[N];
    int iterations;
    double w_values[] = {1.03, 1.0, 1.1};

    for (int i = 0; i < 3; i++) {
        double w = w_values[i];
        sor(A, b, x, w, &iterations);
        printf("With omega = %.2f, iterations = %d, solution = (%.4f, %.4f, %.4f)\n",
               w, iterations, x[0], x[1], x[2]);
    }

    return 0;
}