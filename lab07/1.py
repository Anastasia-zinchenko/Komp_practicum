import numpy as np

# Функция для вычисления правой части уравнения
def f(x, y):
    return -y**2 - 1/x**4

# Точное решение для сравнения
def exact_solution(x):
    return -((x - np.tan((-1 + x)/x)) / x**2)

# Начальные условия
x0, y0 = 1, 1
x_end = 2
h = 0.1
n = int((x_end - x0) / h)

# Массивы для хранения значений
x = np.linspace(x0, x_end, n+1)
y = np.zeros(n+1)
y[0] = y0

# Первый улучшенный метод Эйлера
for i in range(n):
    k1 = f(x[i], y[i])
    k2 = f(x[i] + h, y[i] + h * k1)
    y[i+1] = y[i] + h/2 * (k1 + k2)

# Вычисление точного решения и погрешности
exact_y = exact_solution(x)
errors = np.abs(exact_y - y)

# Вывод результатов
for i in range(n+1):
    print(f"x = {x[i]:.1f}, Numerical y = {y[i]:.6f}, Exact y = {exact_y[i]:.6f}, Error = {errors[i]:.6f}")
