#include <iostream>
#include <cmath>

double f(double x) {
    return log(x) + pow(x + 1, 3);
}

double findRoot(double a, double b, double epsilon) {
    if (f(a) * f(b) >= 0) {
        std::cout << "Root is not in the given interval." << std::endl;
        return -1;
    }

    double c;
    
    while ((b - a) >= epsilon) {
        c = (a + b) / 2;

        if (f(c) == 0.0) {
            break;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    return c;
}

int main() {
    double a = 0.1;
    double b = 1.0;
    double epsilon = 1e-6;

    double root = findRoot(a, b, epsilon);

    if (root != -1) {
        std::cout << "Root: " << root << std::endl;
        std::cout << "f(root): " << f(root) << std::endl;
    }

    return 0;
}
