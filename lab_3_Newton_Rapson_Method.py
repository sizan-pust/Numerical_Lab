import math

# Define the function
def f(x):
    return x**3 - x - 2   # Example function

# Define derivative of the function
def df(x):
    return 3*x**2 - 1     # Derivative

x0 = float(input("Enter initial guess: "))
tolerance = float(input("Enter tolerance: "))

iteration = 0

print("\nIteration\t x\t\t f(x)")

while True:

    if df(x0) == 0:
        print("Derivative is zero. Method fails.")
        break

    x1 = x0 - f(x0) / df(x0)
    iteration += 1

    print(f"{iteration}\t\t{x1:.6f}\t{f(x1):.6f}")

    x0 = x1

    if abs(f(x1)) <= tolerance:
        break

print("\nRoot =", round(x1, 6))
print("Total Iterations =", iteration)