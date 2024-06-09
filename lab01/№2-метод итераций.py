import math

def g(x):
    return -1 - (math.log(x) / 3) ** 2

def solve_by_iteration(epsilon):
    x0 = 0.5  # начальное приближение
    x1 = g(x0)
    while abs(x1 - x0) >= epsilon:
        x0 = x1
        x1 = g(x0)
    return x1

epsilon = 1e-6
solution = solve_by_iteration(epsilon)
print(f"Корень уравнения: {solution}")

