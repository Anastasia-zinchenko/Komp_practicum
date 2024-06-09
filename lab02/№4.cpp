#include <iostream>
#include <cmath>
#include <cstdlib>

// Уравнение параболического цилиндра: ax^2 + by^2 = z
double a_cylinder = 1.0, b_cylinder = 2.0;

// Уравнение плоскости: Ax + By + Cz + D = 0
double A_plane = -1.0, B_plane = 1.0, C_plane = 2.0, D_plane = 3.0;

// Уравнение прямой: x = x0 + at, y = y + bt, z = z0 + ct
double x0 = 1.0, y = 2.0, z0 = 3.0;
double a_line = 0.5, b_line = -1.0, c_line = 1.5;

// Координаты случайной точки
double x_point = 0.5, y_point = -1.5, z_point = 2.0;

int main() {
    // Проверка пересечения плоскости и параболического цилиндра
    double discriminant_plane_cylinder = 4 * a_cylinder * b_cylinder * D_plane * D_plane;
    if (discriminant_plane_cylinder >= 0) {
        std::cout << "Плоскость пересекает параболический цилиндр." << std::endl;
    } else {
        std::cout << "Плоскость не пересекает параболический цилиндр." << std::endl;
    }

    // Проверка пересечения прямой и параболического цилиндра
    double discriminant_line_cylinder = b_cylinder * (4 * a_cylinder * x0 * x0 - 4 * z0) - 4 * a_cylinder * b_cylinder * (a_line * a_line + b_line * b_line);
    if (discriminant_line_cylinder >= 0) {
        std::cout << "Прямая пересекает параболический цилиндр." << std::endl;
    } else {
        std::cout << "Прямая не пересекает параболический цилиндр." << std::endl;
    }

    // Проверка принадлежности точки параболическому цилиндру
    double result_point_cylinder = a_cylinder * x_point * x_point + b_cylinder * y_point * y_point - z_point;
    if (std::abs(result_point_cylinder) < 0.0001) {
        std::cout << "Точка принадлежит параболическому цилиндру." << std::endl;
    } else {
        std::cout << "Точка не принадлежит параболическому цилиндру." << std::endl;
    }

    return 0;
}
