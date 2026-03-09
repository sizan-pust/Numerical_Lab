import math

def f(x):
    return math.log(x)   # user can change the function here


print("========== Trapezoidal Rule ==========")

a = float(input("Enter lower limit: "))
b = float(input("Enter upper limit: "))
n = int(input("Enter number of intervals: "))

h = (b - a) / n

sum_val = f(a) + f(b)

for i in range(1, n):
    sum_val += 2 * f(a + i*h)

integral = (h / 2) * sum_val

print("=================================")
print("Step Size (h) =", round(h,7))
print("Integral value =", round(integral,12))
print("=================================")