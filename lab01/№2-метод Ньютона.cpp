#include <iostream>
#include <cmath>

double f(double x) {
    return log(x) + pow((x + 1), 3);
}

double f_prime(double x) {
    return 1/x + 3*pow((x + 1), 2);
}

double newton_method(double x0, double epsilon) {
    double x = x0;
    int iteration = 0;
    
    do {
        x0 = x;
        x = x0 - f(x0) / f_prime(x0);
        
        iteration++;
    } while(abs(x - x0) >= epsilon);
    
    std::cout << "Root: " << x << std::endl;
    std::cout << "Number of iterations: " << iteration << std::endl;
    
    return x;
}

int main() {
    double x0 = 0.1; // Изначальное приближение для метода Ньютона
    double epsilon = 1e-6;
    
    newton_method(x0, epsilon);
    
    return 0;
}
