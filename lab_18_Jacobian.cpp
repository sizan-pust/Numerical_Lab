// //jacobian iteration method for solving linear equations
// #include <iostream>
// #include <iomanip>
// #include <cmath>
// using namespace std;

// int main() {
//     int n;
//     double tol;

//     cout << "Enter number of equations: ";
//     cin >> n;

//     double a[20][21], x[20], x_old[20];

//     cout << "Enter augmented matrix coefficients:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j <= n; j++) {
//             cin >> a[i][j];
//         }
//     }

//     cout << "Enter tolerance: ";
//     cin >> tol;

//     for (int i = 0; i < n; i++) {
//         x[i] = 0;
//         x_old[i] = 0;
//     }

//     cout << fixed << setprecision(6);

//     cout << "\nIteration";
//     for (int i = 0; i < n; i++) {
//         cout << "\tx" << i + 1;
//     }
//     cout << "\tError\n";

//     double error = tol + 1.0;
//     int iter = 0;

//     while (error >= tol) {
//         for (int i = 0; i < n; i++) {
//             x_old[i] = x[i];
//         }

//         for (int i = 0; i < n; i++) {
//             double sum = a[i][n];

//             for (int j = 0; j < n; j++) {
//                 if (j != i) {
//                     sum -= a[i][j] * x_old[j];
//                 }
//             }

//             x[i] = sum / a[i][i];
//         }

//         error = 0;
//         for (int i = 0; i < n; i++) {
//             if (fabs(x[i] - x_old[i]) > error) {
//                 error = fabs(x[i] - x_old[i]);
//             }
//         }

//         iter++;
//         cout << iter;
//         for (int i = 0; i < n; i++) {
//             cout << "\t" << x[i];
//         }
//         cout << "\t" << error << endl;
//     }

//     cout << "\nApproximate solution:\n";
//     for (int i = 0; i < n; i++) {
//         cout << "x" << i + 1 << " = " << x[i] << endl;
//     }

//     return 0;
// }

// Jacobi iteration method for solving linear equations
#include<stdio.h>
#include<math.h>
int main(){
int n;
printf("Enter number of equations: ");
scanf("%d", &n);
double mat[n][n+1], x_old[n], x_new[n];
printf("Enter the augmented matrix: \n");
for(int i=0;i<n;i++){
    for(int j=0;j<=n;j++){
        scanf("%lf", &mat[i][j]);
    }
    x_old[i] = 0; // Initial guess
    x_new[i] = 0;
}
int maxitr;
printf("Enter the iterations: ");

scanf("%d", &maxitr);
int itr=0;
printf("\nIteration\t: ");
for(int i=0;i<n;i++){   
    printf("x%d \t\t", i+1);
}
printf("\n");  
while(itr<maxitr){
    for(int i=0;i<n;i++){
        x_old[i] = x_new[i];
    }
    itr++;
    printf("%d\t\t: ", itr);
    for(int i=0;i<n;i++){
        double sum = mat[i][n]; // Start with the constant term
        for(int j=0;j<n;j++){
            if(j!=i){
                sum  -= mat[i][j]*x_old[j]; // Subtract the contributions of other variables
            }
        }
        x_new[i] = sum / mat[i][i]; // Update the new value for variable i 
        printf("%lf \t", x_new[i]);
    }
    printf("\n");
}
printf("\nApproximate solution:\n");
for(int i=0;i<n;i++){   
    printf("x%d = %lf\n", i+1, x_new[i]);
}

    return 0;
}