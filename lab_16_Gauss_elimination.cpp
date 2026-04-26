// #include <iostream>
// #include <iomanip>
// #include <cmath>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter number of equations: ";
//     cin >> n;

//     double a[20][21];   // works for up to 20 equations

//     cout << "Enter augmented matrix coefficients:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j <= n; j++) {
//             cin >> a[i][j];
//         }
//     }

//     // Forward Elimination
//     for (int k = 0; k < n - 1; k++) {
//         for (int i = k + 1; i < n; i++) {
//             double factor = a[i][k] / a[k][k];
//             for (int j = k; j <= n; j++) {
//                 a[i][j] = a[i][j] - factor * a[k][j];
//             }
//         }
//     }

//     // Back Substitution
//     double x[20];
//     for (int i = n - 1; i >= 0; i--) {
//         x[i] = a[i][n];
//         for (int j = i + 1; j < n; j++) {
//             x[i] = x[i] - a[i][j] * x[j];
//         }
//         x[i] = x[i] / a[i][i];
//     }

//     cout << fixed << setprecision(6);
//     cout << "\nSolution:\n";
//     for (int i = 0; i < n; i++) {
//         cout << "x" << i + 1 << " = " << x[i] << endl;
//     }

//     return 0;
// }


//Gauss Elimination with step by step explanation and display of intermediate matrices


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of equations: ";
    cin >> n;

    double a[20][21];  // augmented matrix

    cout << "\nEnter augmented matrix coefficients:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cout << fixed << setprecision(4);

    // Display initial matrix
    cout << "\nInitial Augmented Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << setw(10) << a[i][j];
        }
        cout << endl;
    }

    // Forward Elimination
    for (int k = 0; k < n - 1; k++) {

        cout << "\nStep " << k + 1 << " (Making column " << k + 1 << " zero below pivot)\n";

        for (int i = k + 1; i < n; i++) {
            double factor = a[i][k] / a[k][k];

            cout << "R" << i + 1 << " = R" << i + 1 
                 << " - (" << factor << ") * R" << k + 1 << endl;

            for (int j = k; j <= n; j++) {
                a[i][j] = a[i][j] - factor * a[k][j];
            }
        }

        // Print matrix after each step
        cout << "\nMatrix after Step " << k + 1 << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                cout << setw(10) << a[i][j];
            }
            cout << endl;
        }
    }

    // Back Substitution
    double x[20];

    cout << "\nBack Substitution Steps:\n";

    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];

        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }

        x[i] /= a[i][i];

        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    cout << "\nFinal Solution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}