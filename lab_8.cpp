// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {

//     int n;
//     cout << "Enter number of data points: ";
//     cin >> n;

//     double x[n], y[n];

//     cout << "Enter x and y values:\n";
//     for(int i=0;i<n;i++){
//         cin >> x[i] >> y[i];
//     }

//     double value;
//     cout << "Enter value of x where derivative is needed: ";
//     cin >> value;

//     double h = x[1] - x[0];

//     int pos = -1;

//     // find index of required x
//     for(int i=0;i<n;i++){
//         if(x[i] == value){
//             pos = i;
//             break;
//         }
//     }

//     if(pos == 0 || pos == n-1){
//         cout << "Central difference cannot be applied at boundary points\n";
//         return 0;
//     }

//     double first = (y[pos+1] - y[pos-1])/(2*h);
//     double second = (y[pos+1] - 2*y[pos] + y[pos-1])/(h*h);

//     cout << fixed << setprecision(6);

//     cout << "\nFirst Derivative  = " << first << endl;
//     cout << "Second Derivative = " << second << endl;

//     return 0;
// }