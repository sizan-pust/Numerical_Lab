#include <stdio.h>

int main() {
    float x[20], y[20][20];
    int n, i, j;
    float value, h, u, sum, term;

    printf("--- Newton Forward Interpolation ---\n");

    // 1. Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // 2. Input data points (x and y)
    printf("Enter the data points (x and y):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    // 3. Construct the Forward Difference Table
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    // 4. Display the Difference Table
    printf("\n--- Forward Difference Table ---\n");
    for (i = 0; i < n; i++) {
        printf("%0.2f", x[i]);
        for (j = 0; j < n - i; j++) {
            printf("\t%0.2f", y[i][j]);
        }
        printf("\n");
    }

    // 5. Input the interpolation value
    printf("\nEnter the value of x to interpolate for: ");
    scanf("%f", &value);

    // 6. Applying the Formula
    // u = (x - x0) / h
    h = x[1] - x[0];
    u = (value - x[0]) / h;

    sum = y[0][0]; // Initial term (y0)
    term = 1.0;

    for (i = 1; i < n; i++) {
        // Calculate (u * (u-1) * (u-2) * ...) / i!
        term = term * (u - i + 1) / i;

        // Multiply by the forward difference and add to sum
        sum = sum + term * y[0][i];
    }

    printf("\nThe interpolated value at x = %0.2f is %0.4f\n", value, sum);

    return 0;
}