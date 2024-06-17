def f(x):
    return np.log(x) + (x + 1)**3

def bisection_method(a, b, eps):
    if f(a) * f(b) >= 0:
        print("Метод дихотомии не применим. На концах отрезка функция имеет одинаковый знак.")
        return None
    while (b - a) > eps:
        c = (a + b) / 2
        if f(c) == 0:
            return c
        elif f(c) * f(a) < 0:
            b = c
        else:
            a = c
    return (a + b) / 2

a = 0.1
b = 3
eps = 1e-6

root = bisection_method(a, b, eps)
if root:
    print("Корень уравнения: ", root)
