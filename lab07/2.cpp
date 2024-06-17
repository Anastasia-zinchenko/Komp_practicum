#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления правой части уравнения
double f(double x, double y) {
    return -y * cos(x) + 0.5 * sin(2*x);
}

// Точное решение для сравнения
double exact_solution(double x) {
    return sin(x) - 1 + exp(-sin(x));
}

int main() {
    // Начальные условия
    double x0 = 0.0, y0 = 0.0;
    double x_end = 1.0;
    double h = 0.1;
    int n = (int)((x_end - x0) / h);

    // Массивы для хранения значений
    double x[n+1], y[n+1];
    x[0] = x0;
    y[0] = y0;

    // Классический метод Эйлера
    for (int i = 0; i < n; ++i) {
        x[i+1] = x[i] + h;
        y[i+1] = y[i] + h * f(x[i], y[i]);
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
