import numpy as np

# Функция для вычисления правой части уравнения
def f(x, y):
    return -y * np.cos(x) + 0.5 * np.sin(2*x)

# Точное решение для сравнения
def exact_solution(x):
    return np.sin(x) - 1 + np.exp(-np.sin(x))

# Начальные условия
x0, y0 = 0, 0
x_end = 1
h = 0.1
n = int((x_end - x0) / h)

# Массивы для хранения значений
x = np.linspace(x0, x_end, n+1)
y = np.zeros(n+1)
y[0] = y0

# Классический метод Эйлера
for i in range(n):
    y[i+1] = y[i] + h * f(x[i], y[i])

# Вычисление точного решения и погрешности
exact_y = exact_solution(x)
errors = np.abs(exact_y - y)

# Вывод результатов
for i in range(n+1):
    print(f"x = {x[i]:.1f}, Numerical y = {y[i]:.6f}, Exact y = {exact_y[i]:.6f}, Error = {errors[i]:.6f}")
