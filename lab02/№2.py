import numpy as np

# Генерация случайных координат для трех векторов в трехмерном пространстве
vector1 = np.random.randint(1, 10, 3)
vector2 = np.random.randint(1, 10, 3)
vector3 = np.random.randint(1, 10, 3)

print("Вектор 1:", vector1)
print("Вектор 2:", vector2)
print("Вектор 3:", vector3)

# Вычисление длин векторов
length_vector1 = np.linalg.norm(vector1)
length_vector2 = np.linalg.norm(vector2)
length_vector3 = np.linalg.norm(vector3)

print("\nДлины векторов:")
print("Длина вектора 1:", length_vector1)
print("Длина вектора 2:", length_vector2)
print("Длина вектора 3:", length_vector3)

# Вычисление углов между векторами
angle1_2 = np.arccos(np.dot(vector1, vector2) / (length_vector1 * length_vector2))
angle1_3 = np.arccos(np.dot(vector1, vector3) / (length_vector1 * length_vector3))
angle2_3 = np.arccos(np.dot(vector2, vector3) / (length_vector2 * length_vector3))

print("\nУглы между векторами (в радианах):")
print("Угол между вектором 1 и вектором 2:", angle1_2)
print("Угол между вектором 1 и вектором 3:", angle1_3)
print("Угол между вектором 2 и вектором 3:", angle2_3)

# Сумма и разность векторов
sum_1_2 = vector1 + vector2
diff_1_2 = vector1 - vector2
sum_1_3 = vector1 + vector3
diff_1_3 = vector1 - vector3
sum_2_3 = vector2 + vector3
diff_2_3 = vector2 - vector3

print("\nСумма и разность векторов:")
print("Сумма вектора 1 и вектора 2:", sum_1_2)
print("Разность вектора 1 и вектора 2:", diff_1_2)
print("Сумма вектора 1 и вектора 3:", sum_1_3)
print("Разность вектора 1 и вектора 3:", diff_1_3)
print("Сумма вектора 2 и вектора 3:", sum_2_3)
print("Разность вектора 2 и вектора 3:", diff_2_3)

# Проверка коллинеарности векторов
if np.cross(vector1, vector2).sum() == 0 or np.cross(vector1, vector3).sum() == 0 or np.cross(vector2, vector3).sum() == 0:
    print("\nВекторы коллинеарны (лежат на одной прямой)")
else:
    print("\nВекторы не коллинеарны (не лежат на одной прямой)")

# Вычисление смешанного произведения трех векторов
scalar_triple_product = np.dot(np.cross(vector1, vector2), vector3)

print("\nСмешанное произведение трех векторов:", scalar_triple_product)
