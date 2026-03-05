#include <iostream>
#include <cmath>
using namespace std;

// Define the function
double f(double x) {
    return x*x*x - x - 2;   // predefined function Example: x^3 - x - 2
}

// Define derivative of the function
double df(double x) {
    return 3*x*x - 1;       // Derivative: 3x^2 - 1
}

int main() {
    double x0, x1, tolerance;
    int iteration = 0;

    cout << "Enter initial guess: ";
    cin >> x0;

    cout << "Enter tolerance: ";
    cin >> tolerance;

    cout << "\nIteration\t x\t\t f(x)\n";

    do {
        if (df(x0) == 0) {
            cout << "Derivative is zero. Method fails.\n";
            return 0;
        }

        x1 = x0 - f(x0) / df(x0);
        iteration++;

        cout << iteration << "\t\t"
             << x1 << "\t"
             << f(x1) << endl;

        x0 = x1;

    } while (fabs(f(x1)) > tolerance);

    cout << "\nRoot = " << x1 << endl;
    cout << "Total Iterations = " << iteration << endl;

    return 0;
}
