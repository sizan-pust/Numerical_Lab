#include <iostream>
#include <iomanip>
using namespace std;

// ODE: dy/dx = x - y
double f(double x, double y) {
    return x - y;
}

int main() {
    double x0, y0, h, xn;

    cout << "Enter x0: ";
    cin >> x0;

    cout << "Enter y0: ";
    cin >> y0;

    cout << "Enter step size h: ";
    cin >> h;

    cout << "Enter final value xn: ";
    cin >> xn;

    cout << fixed << setprecision(6);

    cout << "\nIteration\t x\t\t y\n";

    int iteration = 0;

    while (x0 < xn) {
        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + h, y0 + k1);

        y0 = y0 + (k1 + k2) / 2.0;
        x0 = x0 + h;
        iteration++;

        cout << iteration << "\t\t" << x0 << "\t" << y0 << endl;
    }

    cout << "\nApproximate value at x = " << xn << " is y = " << y0 << endl;

    return 0;
}