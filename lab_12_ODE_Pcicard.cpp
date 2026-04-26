#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Given ODE: dy/dx = x - y
double f(double x, double y) {
    return x - y;
}

int main() {

    double x0, y0, x, tolerance;

    cout << "Enter x0: ";
    cin >> x0;

    cout << "Enter y0: ";
    cin >> y0;

    cout << "Enter value of x: ";
    cin >> x;

    cout << "Enter tolerance: ";
    cin >> tolerance;

    int n = 100; // number of steps for integration
    double h = (x - x0) / n;

    double t[n+1], y_prev[n+1], y_next[n+1];

    // Generate x values
    for(int i = 0; i <= n; i++)
        t[i] = x0 + i*h;

    // Initial approximation y0(x) = constant
    for(int i = 0; i <= n; i++)
        y_prev[i] = y0;

    cout << fixed << setprecision(6);

    int iteration = 0;

    while(true) {
        iteration++;

        for(int i = 0; i <= n; i++) {

            double sum = 0;

            // Trapezoidal Rule
            for(int j = 0; j < i; j++) {
                sum += (f(t[j], y_prev[j]) + f(t[j+1], y_prev[j+1])) / 2.0;
            }

            y_next[i] = y0 + h * sum;
        }

        cout << "Iteration " << iteration 
             << " -> y(" << x << ") = " << y_next[n] << endl;

        // Check stopping condition
        if (fabs(y_next[n] - y_prev[n]) < tolerance)
            break;

        // Update
        for(int i = 0; i <= n; i++)
            y_prev[i] = y_next[i];
    }

    cout << "\nFinal Answer = " << y_next[n] << endl;
    cout << "Total Iterations = " << iteration << endl;

    return 0;
}