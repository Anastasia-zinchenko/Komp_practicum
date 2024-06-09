#include <iostream>
#include <cmath>
#include <vector>

struct Vector {
    double x, y;
};

double calculateMagnitude(Vector v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

double calculateDotProduct(Vector v1, Vector v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

double calculateAngle(Vector v1, Vector v2) {
    double dotProduct = calculateDotProduct(v1, v2);
    double magnitudeProduct = calculateMagnitude(v1) * calculateMagnitude(v2);
    return acos(dotProduct / magnitudeProduct);
}

Vector calculateSum(Vector v1, Vector v2) {
    return {v1.x + v2.x, v1.y + v2.y};
}

Vector calculateDifference(Vector v1, Vector v2) {
    return {v1.x - v2.x, v1.y - v2.y};
}

int main() {
    std::vector<Vector> vectors(3);

    for (int i = 0; i < 3; ++i) {
        vectors[i].x = rand() % 10 + 1; // случайные координаты
        vectors[i].y = rand() % 10 + 1;
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << "Длина вектора " << i + 1 << ": " << calculateMagnitude(vectors[i]) << std::endl;
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            double angle = calculateAngle(vectors[i], vectors[j]) * 180.0 / M_PI;
            std::cout << "Угол между векторами " << i + 1 << " и " << j + 1 << " : " << angle << std::endl;
        }
    }

    for (int i = 0; i < 2; ++i) {
        Vector sum = calculateSum(vectors[i], vectors[i+1]);
        std::cout << "Сумма векторов " << i + 1 << " и " << i + 2 << ": (" << sum.x << ", " << sum.y << ")" << std::endl;
    }

    for (int i = 0; i < 2; ++i) {
        Vector diff = calculateDifference(vectors[i], vectors[i+1]);
        std::cout << "Разность векторов " << i + 1 << " и " << i + 2 << ": (" << diff.x << ", " << diff.y << ")" << std::endl;
    }

    // Проверка параллельности векторов (на плоскости векторы параллельны, если их координаты пропорциональны)
    bool parallel = (vectors[0].x / vectors[1].x == vectors[0].y / vectors[1].y) &&
                    (vectors[1].x / vectors[2].x == vectors[1].y / vectors[2].y) &&
                    (vectors[0].x / vectors[2].x == vectors[0].y / vectors[2].y);

    if (parallel) {
        std::cout << "Векторы параллельны." << std::endl;
    } else {
        std::cout << "Векторы не параллельны." << std::endl;
    }

    return 0;
}
