// //jacobian iteration method for solving linear equations
// #include <iostream>
// #include <iomanip>
// #include <cmath>
// using namespace std;

// int main() {
//     int n;
//     double tol;

//     cout << "Enter number of equations: ";
//     cin >> n;

//     double a[20][21], x[20], x_old[20];

//     cout << "Enter augmented matrix coefficients:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j <= n; j++) {
//             cin >> a[i][j];
//         }
//     }

//     cout << "Enter tolerance: ";
//     cin >> tol;

//     for (int i = 0; i < n; i++) {
//         x[i] = 0;
//         x_old[i] = 0;
//     }

//     cout << fixed << setprecision(6);

//     cout << "\nIteration";
//     for (int i = 0; i < n; i++) {
//         cout << "\tx" << i + 1;
//     }
//     cout << "\tError\n";

//     double error = tol + 1.0;
//     int iter = 0;

//     while (error >= tol) {
//         for (int i = 0; i < n; i++) {
//             x_old[i] = x[i];
//         }

//         for (int i = 0; i < n; i++) {
//             double sum = a[i][n];

//             for (int j = 0; j < n; j++) {
//                 if (j != i) {
//                     sum -= a[i][j] * x_old[j];
//                 }
//             }

//             x[i] = sum / a[i][i];
//         }

//         error = 0;
//         for (int i = 0; i < n; i++) {
//             if (fabs(x[i] - x_old[i]) > error) {
//                 error = fabs(x[i] - x_old[i]);
//             }
//         }

//         iter++;
//         cout << iter;
//         for (int i = 0; i < n; i++) {
//             cout << "\t" << x[i];
//         }
//         cout << "\t" << error << endl;
//     }

//     cout << "\nApproximate solution:\n";
//     for (int i = 0; i < n; i++) {
//         cout << "x" << i + 1 << " = " << x[i] << endl;
//     }

//     return 0;
// }

// Jacobi iteration method for solving linear equations
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, maxIter;

    cout << "Enter number of equations: ";
    cin >> n;

    double a[20][21], x[20], x_old[20];

    cout << "Enter augmented matrix coefficients:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
         x[i] = 0;
        x_old[i] = 0;
    }
    cout << "Enter number of iterations: ";
    cin >> maxIter;

    cout << fixed << setprecision(6);
    cout << "\nIteration\t";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1<<"\t\t";
    }
    cout << endl;

    int iter = 0;

    while (iter < maxIter) {
        for (int i = 0; i < n; i++) {
            x_old[i] = x[i];
        }
iter++;

        cout << iter<<"\t\t";
        for (int i = 0; i < n; i++) {
            double sum = a[i][n];

            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum -= a[i][j] * x_old[j];
                }
            }

            x[i] = sum / a[i][i];
            cout  << x[i]<<"\t";
        }
        cout << endl;
    }

    cout << "\nApproximate solution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}