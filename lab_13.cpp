//there is a problem with this code, not giving  right results.

#include <iostream>
#include <iomanip>
using namespace std;

// dy/dx = x - y
double f(double x, double y) {
    return x - y;
}

int main() {

    double x0, y0, h, x;

    cout << "Enter x0: ";
    cin >> x0;

    cout << "Enter y0: ";
    cin >> y0;

    cout << "Enter step size h: ";
    cin >> h;

    cout << "Enter value of x: ";
    cin >> x;

    double xn = x0;
    double yn = y0;

    cout << fixed << setprecision(6);

    cout << "\nIteration\t x\t\t y\n";

    int i = 0;

    while (xn < x) {

        // Predictor (Euler)
        double y_pred = yn + h * f(xn, yn);

        // Corrector (Trapezoidal)
        double y_next = yn + (h/2) * (f(xn, yn) + f(xn + h, y_pred));

        xn = xn + h;
        yn = y_next;

        i++;
        cout << i << "\t\t" << xn << "\t" << yn << endl;
    }

    cout << "\nFinal Answer: y(" << x << ") = " << yn << endl;

    return 0;
}