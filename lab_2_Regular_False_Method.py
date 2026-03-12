import math

# Define the function
def f(x):
    return x**3 - x - 2   # Example function

a = float(input("Enter lower guess (a): "))
b = float(input("Enter upper guess (b): "))
tolerance = float(input("Enter tolerance: "))

iteration = 0

if f(a) * f(b) >= 0:
    print("Invalid initial guesses. f(a) and f(b) must have opposite signs.")
else:
    print("\nIteration\t a\t\t b\t\t c\t\t f(c)")

    while True:
        c = (a * f(b) - b * f(a)) / (f(b) - f(a))
        iteration += 1

        print(f"{iteration}\t\t{a:.6f}\t{b:.6f}\t{c:.6f}\t{f(c):.6f}")

        if f(c) == 0:
            break
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c

        if abs(f(c)) <= tolerance:
            break

    print("\nRoot =", round(c, 6))
    print("Total Iterations =", iteration)