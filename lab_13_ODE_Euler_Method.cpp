#include <stdio.h>

// Change this function according to your differential equation
float f(float x, float y) {
    return x - y;                 // Example: dy/dx = x - y
    // return -2*x*y;             // Another common: dy/dx = -2xy
    // return (x - y)/(x + y);    // Try your own
}

int main() {
    float x0, y0, h, xn, x, y;
    int n, i;

    printf("\n=== Euler's Method for Solving ODE ===\n\n");

    printf("Enter initial value of x (x0) : ");
    scanf("%f", &x0);

    printf("Enter initial value of y (y0) : ");
    scanf("%f", &y0);

    printf("Enter step size (h)          : ");
    scanf("%f", &h);

    printf("Enter final value of x (xn)  : ");
    scanf("%f", &xn);

    n = (xn - x0) / h ;   // Calculate number of steps

    x = x0;
    y = y0;

    printf("\n%-10s %-15s\n", "x", "y(x)");
    printf("-----------------------------------\n");
    printf("%-10.4f %-15.6f\n", x, y);

    for(i = 1; i <= n; i++) {
        y = y + h * f(x, y);      // Euler's formula
        x = x + h;
        printf("%-10.4f %-15.6f\n", x, y);
    }

    printf("-----------------------------------\n");
    printf("Approximate value of y(%.4f) = %.8f\n", xn, y);

    return 0;
}