// Simpson's three-eighth rule for numerical integration of log (x)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
    return log(x);// user can change the function here as per requirement
}

int main()
{
    printf("==Simpson three-eight===\n");

    double a, b, h, sum, integral;
    int n, i;
    printf("Enter lower limit: ");
    scanf("%lf", &a);
    printf("Enter upper limit: ");
    scanf("%lf", &b);
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    if (n % 3 != 0)
    {
        printf("Interval must be odd number.");
        return 1;
    }

    h = (b - a) / n;
    sum = f(a) + f(b);
    for (i = 1; i < n; i++)
    {

        if (i % 3 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 3 * f(a + i * h);
    }
    integral = (3.0 * h / 8.0) * sum;

    printf("=================================\n");
    printf("\n Step Size (h)   = %.7f\n", h);
    printf("Integral value = %.12f\n", integral);
    printf("=================================\n");
    return 0;
}
