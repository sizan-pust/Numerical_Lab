import math

n = int(input("Enter number of points: "))

sx = sy = sx2 = sx3 = sx4 = sxy = sx2y = 0

print("Enter x and y values:")

for i in range(n):
    x = float(input("x: "))
    y = float(input("y: "))

    sx += x
    sy += y
    sx2 += x*x
    sx3 += x*x*x
    sx4 += x*x*x*x
    sxy += x*y
    sx2y += x*x*y

D = n*(sx2*sx4 - sx3*sx3) - sx*(sx*sx4 - sx2*sx3) + sx2*(sx*sx3 - sx2*sx2)

Da = sy*(sx2*sx4 - sx3*sx3) - sx*(sxy*sx4 - sx3*sx2y) + sx2*(sxy*sx3 - sx2*sx2y)
Db = n*(sxy*sx4 - sx3*sx2y) - sy*(sx*sx4 - sx2*sx3) + sx2*(sx*sx2y - sxy*sx2)
Dc = n*(sx2*sx2y - sxy*sx3) - sx*(sx*sx2y - sxy*sx2) + sy*(sx*sx3 - sx2*sx2)

a = Da / D
b = Db / D
c = Dc / D

print("\nCurve: y = {:.12f} + {:.12f}x + {:.12f}x^2".format(a, b, c))