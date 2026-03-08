// Curve Fitting of a quadratic curve parabola using Least Squares Method
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "Enter number of points: ";
    cin >> n;

    double x, y;
    double sx=0, sy=0, sx2=0, sx3=0, sx4=0, sxy=0, sx2y=0;

    cout << "Enter x and y values:\n";

    for(int i=0;i<n;i++){
        cin >> x >> y;

        sx += x;
        sy += y;
        sx2 += x*x;
        sx3 += x*x*x;
        sx4 += x*x*x*x;
        sxy += x*y;
        sx2y += x*x*y;
    }

    double D = n*(sx2*sx4 - sx3*sx3) - sx*(sx*sx4 - sx2*sx3) + sx2*(sx*sx3 - sx2*sx2);

    double Da = sy*(sx2*sx4 - sx3*sx3) - sx*(sxy*sx4 - sx3*sx2y) + sx2*(sxy*sx3 - sx2*sx2y);
    double Db = n*(sxy*sx4 - sx3*sx2y) - sy*(sx*sx4 - sx2*sx3) + sx2*(sx*sx2y - sxy*sx2);
    double Dc = n*(sx2*sx2y - sxy*sx3) - sx*(sx*sx2y - sxy*sx2) + sy*(sx*sx3 - sx2*sx2);

    double a = Da/D;
    double b = Db/D;
    double c = Dc/D;
cout << fixed << setprecision(12);
    cout << "\nCurve: y = " << a << " + " << b << "x + " << c << "x^2";

    return 0;
}