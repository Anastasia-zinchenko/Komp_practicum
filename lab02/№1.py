import numpy as np
import math

# Генерируем координаты случайным образом
v1 = np.random.randint(-10, 10, (2,))
v2 = np.random.randint(-10, 10, (2,))
v3 = np.random.randint(-10, 10, (2,))

# Находим длины векторов
length_v1 = np.linalg.norm(v1)
length_v2 = np.linalg.norm(v2)
length_v3 = np.linalg.norm(v3)

# Находим углы между векторами
angle_v1_v2 = np.arccos(np.dot(v1, v2) / (length_v1 * length_v2))
angle_v1_v3 = np.arccos(np.dot(v1, v3) / (length_v1 * length_v3))
angle_v2_v3 = np.arccos(np.dot(v2, v3) / (length_v2 * length_v3))

# Находим суммы и разности векторов
sum_v1_v2 = v1 + v2
sum_v1_v3 = v1 + v3
sum_v2_v3 = v2 + v3

diff_v1_v2 = v1 - v2
diff_v1_v3 = v1 - v3
diff_v2_v3 = v2 - v3

# Проверяем параллельность
is_parallel = False
if np.cross(v1, v2) == 0 or np.cross(v1, v3) == 0 or np.cross(v2, v3) == 0:
    is_parallel = True

print("Вектор 1:", v1)
print("Длина вектора 1:", length_v1)
print("Вектор 2:", v2)
print("Длина вектора 2:", length_v2)
print("Вектор 3:", v3)
print("Длина вектора 3:", length_v3)

print("Угол между вектором 1 и вектором 2:", math.degrees(angle_v1_v2))
print("Угол между вектором 1 и вектором 3:", math.degrees(angle_v1_v3))
print("Угол между вектором 2 и вектором 3:", math.degrees(angle_v2_v3))

print("Сумма векторов 1 и 2:", sum_v1_v2)
print("Сумма векторов 1 и 3:", sum_v1_v3)
print("Сумма векторов 2 и 3:", sum_v2_v3)

print("Разность векторов 1 и 2:", diff_v1_v2)
print("Разность векторов 1 и 3:", diff_v1_v3)
print("Разность векторов 2 и 3:", diff_v2_v3)

if is_parallel:
    print("Среди векторов есть параллельные.")
else:
    print("Среди векторов нет параллельных.")
