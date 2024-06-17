#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления правой части уравнения
double f(double x, double y) {
    return -y*y - 1/(x*x*x*x);
}

// Точное решение для сравнения
double exact_solution(double x) {
    return -( (x - tan((-1 + x)/x)) / (x*x) );
}

int main() {
    // Начальные условия
    double x0 = 1.0, y0 = 1.0;
    double x_end = 2.0;
    double h = 0.1;
    int n = (int)((x_end - x0) / h);

    // Массивы для хранения значений
    double x[n+1], y[n+1];
    x[0] = x0;
    y[0] = y0;

    // Первый улучшенный метод Эйлера (метод Эйлера с модификацией)
    for (int i = 0; i < n; ++i) {
        x[i+1] = x[i] + h;
        double k1 = f(x[i], y[i]);
        double k2 = f(x[i] + h, y[i] + h * k1);
        y[i+1] = y[i] + h/2 * (k1 + k2);
    }

    // Вывод результатов
    cout << fixed << setprecision(6);
    for (int i = 0; i <= n; ++i) {
        double exact_y = exact_solution(x[i]);
        double error = fabs(exact_y - y[i]);
        cout << "x = " << x[i] << ", Numerical y = " << y[i] << ", Exact y = " << exact_y << ", Error = " << error << endl;
    }

    return 0;
}
