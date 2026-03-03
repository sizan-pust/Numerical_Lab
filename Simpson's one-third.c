// Simpson's one-third rule for numerical integration of log (x)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
    return log(x);// user can change the function here as per requirement
}

int main()
{
    printf("==Simpson one-third===\n");

    double a, b, h, sum, integral;
    int n, i;
    printf("Enter lower limit: ");
    scanf("%lf", &a);
    printf("Enter upper limit: ");
    scanf("%lf", &b);
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    if (n % 2 != 0)
    {
        printf("Interval must be even number.");
        return 1;
    }

    h = (b - a) / n;
    sum = f(a) + f(b);
    for (i = 1; i < n; i++)
    {

        if (i % 2 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 4 * f(a + i * h);
    }
    integral = (h / 3.0) * sum;

    printf("=================================\n");
    printf("\n Step Size (h)   = %.7f\n", h);
    printf("Integral value = %.12f\n", integral);
    printf("=================================\n");
    return 0;
}
