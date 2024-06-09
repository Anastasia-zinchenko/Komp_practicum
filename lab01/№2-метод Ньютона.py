import math

def f(x):
    return math.log(x) + (x + 1)**3

def f_prime(x):
    return 1/x + 3*(x + 1)**2

def newton_method(f, f_prime, x0, epsilon):
    x1 = x0 - f(x0) / f_prime(x0)
    while abs(x1 - x0) >= epsilon:
        x0 = x1
        x1 = x0 - f(x0) / f_prime(x0)
    return x1

# Начальное приближение
x0 = 1

# Точность
epsilon = 1e-6

# Нахождение корня уравнения
root = newton_method(f, f_prime, x0, epsilon)
print(f"Корень уравнения: {root}")
print(f"Значение функции в корне: {f(root)}")
