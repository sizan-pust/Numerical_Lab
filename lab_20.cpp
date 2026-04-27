//newton forward interpolation with step by step explanation and display of forward difference table
// not checked
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[20], y[20][20];

    cout << "Enter x and y values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i][0];
    }

    double value;
    cout << "Enter value of x to interpolate: ";
    cin >> value;

    double h = x[1] - x[0];
    double p = (value - x[0]) / h;

    // Forward difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    // Print difference table
    cout << "\nForward Difference Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << setw(12) << y[i][j];
        }
        cout << endl;
    }

    // Newton forward interpolation
    double result = y[0][0];
    double term = 1.0;

    for (int i = 1; i < n; i++) {
        term = term * (p - (i - 1)) / i;
        result += term * y[0][i];
    }

    cout << fixed << setprecision(6);
    cout << "\nInterpolated value at x = " << value << " is " << result << endl;

    return 0;
}