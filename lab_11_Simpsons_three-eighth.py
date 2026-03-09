import math

def f(x):
    return math.log(x)   # user can change the function here


print("============ Simpson Three-Eighth Rule ==============")

a = float(input("Enter lower limit: "))
b = float(input("Enter upper limit: "))
n = int(input("Enter number of intervals: "))

if n % 3 != 0:
    print("Number of intervals must be a multiple of 3.")
    exit()

h = (b - a) / n

sum_val = f(a) + f(b)

for i in range(1, n):
    if i % 3 == 0:
        sum_val += 2 * f(a + i*h)
    else:
        sum_val += 3 * f(a + i*h)

integral = (3 * h / 8) * sum_val

print("=================================")
print("Step Size (h) =", round(h,7))
print("Integral value =", round(integral,12))
print("=================================")