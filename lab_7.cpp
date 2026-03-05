#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n][n];

    cout << "Enter x and y values:\n";
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i][0];
    }

    double value;
    cout << "Enter the value of x where derivative is needed: ";
    cin >> value;

    double h = x[1] - x[0];
    double u = (value - x[0]) / h;
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < n - j; i++) {
            y[i][j] = y[i+1][j-1] - y[i][j-1];
        }
    }

    cout << "\nForward Difference Table:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            cout << y[i][j] << "\t";
        }
        cout << endl;
    }

    double first = 0, second = 0, third = 0;

    if(n >= 2)
        first += y[0][1];

 if(n >= 3)
        first += ((2*u - 1)/2.0) * y[0][2];

    if(n >= 4)
        first += ((3*u*u - 6*u + 2)/6.0) * y[0][3];

    first = first / h;

    if(n >= 3)
        second += y[0][2];

    if(n >= 4)
        second += (u - 1) * y[0][3];

    second = second / (h*h);

    if(n >= 4)
        third = y[0][3] / (h*h*h);

    cout << "\nFirst Derivative  = " << first << endl;
    cout << "Second Derivative = " << second << endl;
    cout << "Third Derivative  = " << third << endl;

    return 0;
}
