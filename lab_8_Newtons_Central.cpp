//numerical differentiation using newton's central difference method
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n][n];

    cout << "Enter x and y values:\n";
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i][0];
    }

    double h = x[1] - x[0];

    // Create Difference Table
    for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++){
            y[i][j] = y[i+1][j-1] - y[i][j-1];
        }
    }

    cout << "\nDifference Table:\n";
    for(int i=0;i<n;i++){
        cout << x[i] << "\t";
        for(int j=0;j<n-i;j++){
            cout << y[i][j] << "\t";
        }
        cout << endl;
    }

    double value;
    cout << "\nEnter x where derivative is needed: ";
    cin >> value;

    int pos = -1;

    for(int i=0;i<n;i++){
        if(x[i] == value){
            pos = i;
            break;
        }
    }

    if(pos < 2 || pos > n-3){
        cout << "Point must have two neighbors on each side.\n";
        return 0;
    }

    double first  = (y[pos+1][0] - y[pos-1][0])/(2*h);
    double second = (y[pos+1][0] - 2*y[pos][0] + y[pos-1][0])/(h*h);
    double third  = (y[pos+2][0] - 2*y[pos+1][0] + 2*y[pos-1][0] - y[pos-2][0])/(2*h*h*h);

    cout << fixed << setprecision(6);

    cout << "\nDerivatives at x = " << value << endl;
    cout << "First Derivative  = " << first << endl;
    cout << "Second Derivative = " << second << endl;
    cout << "Third Derivative  = " << third << endl;

    return 0;
}