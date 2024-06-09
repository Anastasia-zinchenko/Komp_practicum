def _rectangle_rule(func, a, b, nseg, frac):

    dx = 1.0 * (b - a) / nseg
    sum = 0.0
    xstart = a + frac * dx 
    for i in range(nseg+1):
        sum += func(xstart + i * dx)
    return sum * dx

def func(x):
    return x**4*(25+x*x)**(-1)

from math import *

print("Используем метод прямоугольников.")
print("Интегрируемая функция: x**4*(25+x*x)**(-1)")


a=1 # левый край отрезка интегрирования
b=2 # правый край отрезка интегрирования
nseg = 10000 # количество сегментов
frac=0.5
'''
Параметр 0 <= frac <= 1 задаёт долю смещения точки, 
в которой вычисляется функция, от левого края отрезка dx
frac = 0 --> метод левых прямоугольников  
frac = 0.5 --> метод прямоугольников со средней точкой
frac = 1 --> метод правых прямоугольников
'''

print('a = ', a ,', b = ', b ,', frac = ', frac , sep='')
print("Количество разбиений:", nseg)
intg = _rectangle_rule(func, a, b, nseg, frac)

print("\nОтвет: I =", intg)

