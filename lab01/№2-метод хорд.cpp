#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return log(x) + pow((x + 1), 3);
}

double chordMethod(double a, double b, double epsilon) {
    double x0 = a;
    double x1 = b;
    while (fabs(x1 - x0) > epsilon) {
        x0 = x1 - f(x1) * (x1 - a) / (f(x1) - f(a));
        a = x1;
        x1 = x0;
    }
    return x1;
}

int main() {
    double a = 1.0; // Начальное приближение интервала
    double b = 2.0; // Конечное приближение интервала
    double epsilon = 1e-6; // Точность

    double root = chordMethod(a, b, epsilon);

    cout << "Корень уравнения: " << root << endl;

    return 0;
}
