#include <iostream>
#include <cmath>
using namespace std;

// Define the function
double f(double x) {
    return x*x*x - x - 2;   // Example: x^3 - x - 2
}

int main() {
    double x0, x1, x2, tolerance;
    int iteration = 0;

    cout << "Enter first initial guess (x0): ";
    cin >> x0;

    cout << "Enter second initial guess (x1): ";
    cin >> x1;

    cout << "Enter tolerance: ";
    cin >> tolerance;

    cout << "\nIteration\t x\t\t f(x)\n";

    do {
        if (f(x1) - f(x0) == 0) {
            cout << "Division by zero error. Method fails.\n";
            return 0;
        }

        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        iteration++;

        cout << iteration << "\t\t"
             << x2 << "\t"
             << f(x2) << endl;

        x0 = x1;
        x1 = x2;

    } while (fabs(f(x2)) > tolerance);

    cout << "\nRoot = " << x2 << endl;
    cout << "Total Iterations = " << iteration << endl;

    return 0;
}
