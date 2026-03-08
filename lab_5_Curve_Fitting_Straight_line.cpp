// Curve Fitting of a straight line using Least Squares Method
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n];
    double sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;

    cout << "Enter x and y values:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];

        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2 += x[i] * x[i];
    }

    double b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    double a = (sumy - b * sumx) / n;

    cout << fixed << setprecision(6);

    cout << "\nFitted line equation:\n";
    cout << "y = " << a << " + " << b << "x" << endl;

    return 0;
}
