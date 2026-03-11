import math

# Define the function
def f(x):
    return x**3 - x - 2   # Example function

x0 = float(input("Enter first initial guess (x0): "))
x1 = float(input("Enter second initial guess (x1): "))
tolerance = float(input("Enter tolerance: "))

iteration = 0

print("\nIteration\t x\t\t f(x)")

while True:
    if f(x1) - f(x0) == 0:
        print("Division by zero error. Method fails.")
        break

    x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0))
    iteration += 1

    print(f"{iteration}\t\t{x2:.6f}\t{f(x2):.6f}")

    x0 = x1
    x1 = x2

    if abs(f(x2)) <= tolerance:
        break

print("\nRoot =", round(x2, 6))
print("Total Iterations =", iteration)