n = int(input("Enter number of data points: "))

x = []
y = []

sumx = 0
sumy = 0
sumxy = 0
sumx2 = 0

print("Enter x and y values:")

for i in range(n):
    xi = float(input("x: "))
    yi = float(input("y: "))

    x.append(xi)
    y.append(yi)

    sumx += xi
    sumy += yi
    sumxy += xi * yi
    sumx2 += xi * xi

b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx)
a = (sumy - b * sumx) / n

print("\nFitted line equation:")
print("y = {:.6f} + {:.6f}x".format(a, b))