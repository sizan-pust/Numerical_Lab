//finding root using bisection method
#include <iostream>
#include <cmath>
using namespace std;

// Define the function here
double f(double x) {
    return x*x*x - x - 2;   // predefined function Example: x^3 - x - 2
}

int main() {
    double a, b, c, tolerance;
    int iteration = 0;

    cout << "Enter lower guess (a): ";
    cin >> a;

    cout << "Enter upper guess (b): ";
    cin >> b;

    cout << "Enter tolerance: ";
    cin >> tolerance;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid initial guesses. f(a) and f(b) must have opposite signs.\n";
        return 0;
    }

    cout << "\nIteration\t a\t\t b\t\t c\t\t f(c)\n";

    do {
        c = (a + b) / 2;
        iteration++;

        cout << iteration << "\t\t"
             << a << "\t\t"
             << b << "\t\t"
             << c << "\t\t"
             << f(c) << endl;

        if (f(c) == 0.0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

    } while (fabs(f(c)) > tolerance);

    cout << "\nRoot = " << c << endl;
    cout << "Total Iterations = " << iteration << endl;

    return 0;
}
