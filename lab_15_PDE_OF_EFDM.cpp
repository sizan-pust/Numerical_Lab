// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// #define PI 3.14159265358979323846

// int main() {
//     int nx, nt, i, j, choice;
//     float L, Tmax, alpha, dx, dt, r;
//     float **u;

//     printf("\n=== Explicit Finite Difference Method for 1D Heat Equation ===\n\n");

//     printf("Enter length of domain (L)         : ");
//     scanf("%f", &L);

//     printf("Enter maximum time (Tmax)          : ");
//     scanf("%f", &Tmax);

//     printf("Enter number of space divisions (nx): ");
//     scanf("%d", &nx);

//     printf("Enter number of time steps (nt)    : ");
//     scanf("%d", &nt);

//     printf("Enter thermal diffusivity (alpha)  : ");
//     scanf("%f", &alpha);

//     dx = L / nx;
//     dt = Tmax / nt;
//     r = alpha * alpha * dt / (dx * dx);

//     /* memory allocation */
//     u = (float **)malloc((nt + 1) * sizeof(float *));
//     for (i = 0; i <= nt; i++)
//         u[i] = (float *)calloc(nx + 1, sizeof(float));

//     /* Initial condition */
//     printf("\nChoose Initial Condition:\n");
//     printf("1. u(x,0) = sin(pi*x/L)\n");
//     printf("2. u(x,0) = x*(L - x)\n");
//     printf("3. u(x,0) = exp(-x)\n");
//     printf("Enter choice: ");
//     scanf("%d", &choice);

//     for (i = 0; i <= nx; i++) {
//         float x = i * dx;

//         if (choice == 1)
//             u[0][i] = sin(PI * x / L);
//         else if (choice == 2)
//             u[0][i] = x * (L - x);
//         else
//             u[0][i] = exp(-x);
//     }

//     /* Boundary Conditions: u(0,t) = u(L,t) = 0 */
//     for (j = 0; j <= nt; j++) {
//         u[j][0] = 0.0;
//         u[j][nx] = 0.0;
//     }

//     /* Explicit Finite Difference Loop */
//     for (j = 0; j < nt; j++) {
//         for (i = 1; i < nx; i++) {
//             u[j + 1][i] = u[j][i] + r * (u[j][i - 1] - 2 * u[j][i] + u[j][i + 1]);
//         }
//     }

//     /* Display Final Result */
//     printf("\nSolution at t = %.4f (Final Time):\n", Tmax);
//     printf("%-10s %-15s\n", "x", "u(x, Tmax)");
//     printf("------------------------------------------------\n");

//     for (i = 0; i <= nx; i += nx / 10) {
//         float x = i * dx;
//         printf("%-10.4f %-15.8f\n", x, u[nt][i]);
//     }

//     printf("\nStability Parameter (r) = %.4f ", r);
//     if (r > 0.5)
//         printf("-> WARNING: Unstable! (Reduce dt)\n");
//     else
//         printf("-> Stable\n");

//     /* Free memory */
//     for (i = 0; i <= nt; i++)
//         free(u[i]);
//     free(u);

//     return 0;
// }
// Explicit Finite Difference Method for 1D Heat Equation
// Initial condition: u(x,0) = e^(-x) + sin(x)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int nx, nt, i, j;
    float L, Tmax, alpha, dx, dt, r;
    float **u;

    printf("\n=== Explicit Finite Difference Method for 1D Heat Equation ===\n\n");

    printf("Enter length of domain (L)          : ");
    scanf("%f", &L);

    printf("Enter maximum time (Tmax)           : ");
    scanf("%f", &Tmax);

    printf("Enter number of space divisions (nx): ");
    scanf("%d", &nx);

    printf("Enter number of time steps (nt)     : ");
    scanf("%d", &nt);

    printf("Enter thermal diffusivity (alpha)   : ");
    scanf("%f", &alpha);

    dx = L / nx;
    dt = Tmax / nt;

    r = alpha * alpha * dt / (dx * dx);

    // Memory allocation
    u = (float **)malloc((nt + 1) * sizeof(float *));
    for (i = 0; i <= nt; i++) {
        u[i] = (float *)calloc(nx + 1, sizeof(float));
    }

    // Initial condition: u(x,0) = e^(-x) + sin(x)
    for (i = 0; i <= nx; i++) {
        float x = i * dx;
        u[0][i] = exp(-x) + sin(x);
    }

    // Boundary Conditions: u(0,t) = u(L,t) = 0
    for (j = 0; j <= nt; j++) {
        u[j][0] = 0.0;
        u[j][nx] = 0.0;
    }

    // Explicit Finite Difference Loop
    for (j = 0; j < nt; j++) {
        for (i = 1; i < nx; i++) {
            u[j + 1][i] = u[j][i] + r * (u[j][i - 1] - 2 * u[j][i] + u[j][i + 1]);
        }
    }

    // Display Final Result
    printf("\nSolution at t = %.4f (Final Time):\n", Tmax);
    printf("%-10s %-15s\n", "x", "u(x, Tmax)");
    printf("----------------------------------\n");

    for (i = 0; i <= nx; i += nx / 10) {
        float x = i * dx;
        printf("%-10.4f %-15.8f\n", x, u[nt][i]);
    }

    printf("\nStability Parameter (r) = %.4f ", r);

    if (r > 0.5) {
        printf("-> WARNING: Unstable! Reduce dt or increase nt.\n");
    } else {
        printf("-> Stable\n");
    }

    // Free memory
    for (i = 0; i <= nt; i++) {
        free(u[i]);
    }

    free(u);

    return 0;
}
// Explicit Finite Difference Method for 1D Heat Equation
// Initial condition: u(x,0) = e^(-x) + sin(x)

// #include <iostream>
// #include <iomanip>
// #include <cmath>
// #include <vector>
// using namespace std;

// int main() {
//     int nx, nt;
//     double L, Tmax, alpha, dx, dt, r;

//     cout << "\n=== Explicit Finite Difference Method for 1D Heat Equation ===\n\n";

//     cout << "Enter length of domain (L)          : ";
//     cin >> L;

//     cout << "Enter maximum time (Tmax)           : ";
//     cin >> Tmax;

//     cout << "Enter number of space divisions (nx): ";
//     cin >> nx;

//     cout << "Enter number of time steps (nt)     : ";
//     cin >> nt;

//     cout << "Enter thermal diffusivity (alpha)   : ";
//     cin >> alpha;

//     dx = L / nx;
//     dt = Tmax / nt;

//     r = alpha * alpha * dt / (dx * dx);

//     vector<vector<double>> u(nt + 1, vector<double>(nx + 1, 0.0));

//     // Initial condition: u(x,0) = e^(-x) + sin(x)
//     for (int i = 0; i <= nx; i++) {
//         double x = i * dx;
//         u[0][i] = exp(-x) + sin(x);
//     }

//     // Boundary conditions: u(0,t) = u(L,t) = 0
//     for (int j = 0; j <= nt; j++) {
//         u[j][0] = 0.0;
//         u[j][nx] = 0.0;
//     }

//     // Explicit finite difference loop
//     for (int j = 0; j < nt; j++) {
//         for (int i = 1; i < nx; i++) {
//             u[j + 1][i] = u[j][i] 
//                         + r * (u[j][i - 1] - 2 * u[j][i] + u[j][i + 1]);
//         }
//     }

//     // Display final result
//     cout << fixed << setprecision(8);

//     cout << "\nSolution at t = " << setprecision(4) << Tmax << " (Final Time):\n";
//     cout << left << setw(12) << "x" << setw(18) << "u(x, Tmax)" << endl;
//     cout << "----------------------------------\n";

//     cout << setprecision(8);

//     int step = nx / 10;
//     if (step == 0) {
//         step = 1;
//     }

//     for (int i = 0; i <= nx; i += step) {
//         double x = i * dx;
//         cout << left << setw(12) << setprecision(4) << x
//              << setw(18) << setprecision(8) << u[nt][i] << endl;
//     }

//     cout << "\nStability Parameter (r) = " << setprecision(4) << r << " ";

//     if (r > 0.5) {
//         cout << "-> WARNING: Unstable! Reduce dt or increase nt.\n";
//     } else {
//         cout << "-> Stable\n";
//     }

//     return 0;
// }