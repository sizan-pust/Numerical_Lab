#include <stdio.h>

// Change this function for your ODE
float f(float x, float y) {
    return x - y;                    // Example: dy/dx = x - y
    // return 1 + y*y;               // dy/dx = 1 + yÂ² â†’ y = tan(x)
    // return -2*x*y;                // dy/dx = -2xy
}

int main() {
    float x0, y0, h, xn, x;
    int n, iterations, i, j;

    printf("\n=== Picard's Iterative Method ===\n\n");

    printf("Enter x0 : ");
    scanf("%f", &x0);

    printf("Enter y0 : ");
    scanf("%f", &y0);

    printf("Enter step size (h)     : ");
    scanf("%f", &h);

    printf("Enter final x (xn)      : ");
    scanf("%f", &xn);

    printf("Enter number of iterations : ");
    scanf("%d", &iterations);

    n = (xn - x0) / h ;     // Number of steps

    float y[iterations+1][n+1];         // y[iteration][point]

    // Initialize first approximation: y0(x) = y0 (constant)
    for(i = 0; i <= n; i++) {
        y[0][i] = y0;
    }

    printf("\n%-10s", "x");
    for(i = 1; i <= iterations; i++)
        printf("   y%-8d", i);
    printf("\n-----------------------------------------------------\n");

    // Picard Iterations
    for(j = 1; j <= iterations; j++) {

        y[j][0] = y0;                    // y(x0) = y0 for all iterations

        for(i = 1; i <= n; i++) {
            x = x0 + i * h;

            // Trapezoidal Rule for integration
            float integral = 0.0;
            integral += f(x0, y[j-1][0]);               // First term

            for(int k = 1; k < i; k++)
                integral += 2 * f(x0 + k*h, y[j-1][k]); // Middle terms

            integral += f(x, y[j-1][i]);                // Last term

            integral = integral * (h / 2.0);

            y[j][i] = y0 + integral;
        }
    }

    // Print Results
    for(i = 0; i <= n; i++) {
        x = x0 + i * h;
        printf("%-10.4f", x);
        for(j = 1; j <= iterations; j++) {
            printf("   %-10.6f", y[j][i]);
        }
        printf("\n");
    }

    printf("\nFinal Approximation after %d iterations:\n", iterations);
    printf("y(%.4f) = %.8f\n", xn, y[iterations][n]);

    return 0;
}