#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int nx, nt, i, j, choice;
    float L, Tmax, alpha, dx, dt, r;
    float **u;

    printf("\n=== Explicit Finite Difference Method for 1D Heat Equation ===\n\n");

    printf("Enter length of domain (L)         : ");
    scanf("%f", &L);

    printf("Enter maximum time (Tmax)          : ");
    scanf("%f", &Tmax);

    printf("Enter number of space divisions (nx): ");
    scanf("%d", &nx);

    printf("Enter number of time steps (nt)    : ");
    scanf("%d", &nt);

    printf("Enter thermal diffusivity (alpha)  : ");
    scanf("%f", &alpha);

    dx = L / nx;
    dt = Tmax / nt;
    r = alpha * alpha * dt / (dx * dx);

    /* memory allocation */
    u = (float **)malloc((nt + 1) * sizeof(float *));
    for (i = 0; i <= nt; i++)
        u[i] = (float *)calloc(nx + 1, sizeof(float));

    /* Initial condition */
    printf("\nChoose Initial Condition:\n");
    printf("1. u(x,0) = sin(pi*x/L)\n");
    printf("2. u(x,0) = x*(L - x)\n");
    printf("3. u(x,0) = exp(-x)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    for (i = 0; i <= nx; i++) {
        float x = i * dx;

        if (choice == 1)
            u[0][i] = sin(PI * x / L);
        else if (choice == 2)
            u[0][i] = x * (L - x);
        else
            u[0][i] = exp(-x);
    }

    /* Boundary Conditions: u(0,t) = u(L,t) = 0 */
    for (j = 0; j <= nt; j++) {
        u[j][0] = 0.0;
        u[j][nx] = 0.0;
    }

    /* Explicit Finite Difference Loop */
    for (j = 0; j < nt; j++) {
        for (i = 1; i < nx; i++) {
            u[j + 1][i] = u[j][i] + r * (u[j][i - 1] - 2 * u[j][i] + u[j][i + 1]);
        }
    }

    /* Display Final Result */
    printf("\nSolution at t = %.4f (Final Time):\n", Tmax);
    printf("%-10s %-15s\n", "x", "u(x, Tmax)");
    printf("------------------------------------------------\n");

    for (i = 0; i <= nx; i += nx / 10) {
        float x = i * dx;
        printf("%-10.4f %-15.8f\n", x, u[nt][i]);
    }

    printf("\nStability Parameter (r) = %.4f ", r);
    if (r > 0.5)
        printf("-> WARNING: Unstable! (Reduce dt)\n");
    else
        printf("-> Stable\n");

    /* Free memory */
    for (i = 0; i <= nt; i++)
        free(u[i]);
    free(u);

    return 0;
}