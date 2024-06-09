import math

def f(x):
    return math.log(x) + (x + 1)**3

def false_position_method(x0, x1, eps):
    max_iter = 1000
    iter = 0
    
    while abs(x1 - x0) > eps:
        x = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        x0, x1 = x1, x
        iter += 1
        
        if iter > max_iter:
            print("Невозможно найти корень с заданной точностью, превышено максимальное количество итераций")
            return None

    return x

x0 = 0.5
x1 = 1.0
epsilon = 1e-6

root = false_position_method(x0, x1, epsilon)
if root is not None:
    print("Корень уравнения: {:.6f}".format(root))
