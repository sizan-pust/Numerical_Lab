import math

n = int(input("Enter number of data points: "))

x = []
y = [[0 for _ in range(n)] for _ in range(n)]

print("Enter x and y values:")
for i in range(n):
    xi = float(input())
    yi = float(input())
    x.append(xi)
    y[i][0] = yi

value = float(input("Enter the value of x where derivative is needed: "))

h = x[1] - x[0]
u = (value - x[0]) / h

# Forward Difference Table
for j in range(1, n):
    for i in range(n - j):
        y[i][j] = y[i+1][j-1] - y[i][j-1]

print("\nForward Difference Table:")
for i in range(n):
    for j in range(n - i):
        print(y[i][j], end="\t")
    print()

first = 0
second = 0
third = 0

if n >= 2:
    first += y[0][1]

if n >= 3:
    first += ((2*u - 1)/2.0) * y[0][2]

if n >= 4:
    first += ((3*u*u - 6*u + 2)/6.0) * y[0][3]

first = first / h

if n >= 3:
    second += y[0][2]

if n >= 4:
    second += (u - 1) * y[0][3]

second = second / (h*h)

if n >= 4:
    third = y[0][3] / (h*h*h)

print("\nFirst Derivative =", first)
print("Second Derivative =", second)
print("Third Derivative =", third)