#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return log(x) + pow(x + 1, 3);
}

double df(double x) {
    return 1 / x + 3 * pow(x + 1, 2);
}

double iterate(double x0, double epsilon) {
    double x = x0;
    while (true) {
        double x_next = x - f(x) / df(x);
        if (abs(x_next - x) < epsilon) {
            return x_next;
        }
        x = x_next;
    }
}

int main() {
    double x0 = 0.5;  // Начальное приближение
    double epsilon = 1e-6;
    
    double root = iterate(x0, epsilon);
    
    cout << "Корень уравнения: x = " << root << endl;
    
    return 0;
}
