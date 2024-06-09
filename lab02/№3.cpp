#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Структура для хранения точки на плоскости
struct Point {
    double x, y;
};

int main() {
    srand(time(NULL));

    // Случайно определяем параметры параболы
    double a = rand() % 10 + 1; // коэффициент "a" в уравнении параболы y = ax^2
    double h = rand() % 10 - 5; // "h" координата вершины параболы
    double k = rand() % 10 - 5; // "k" координата вершины параболы

    // Случайно определяем координаты точки
    Point p;
    p.x = rand() % 10 - 5;
    p.y = rand() % 10 - 5;

    // Проверяем принадлежность точки параболе
    bool belongs = false;
    if (p.y == a * pow((p.x - h), 2) + k) {
        belongs = true;
    }

    // Находим координаты фокуса параболы
    double focus_x = h;
    double focus_y = k + 1/(4*a);

    // Находим расстояние от директрисы до фокуса
    double distance = abs(1/(4*a));

    // Выводим результаты
    cout << "Уравнение параболы: y = " << a << "x^2 + " << h << endl;
    cout << "Координаты точки: (" << p.x << ", " << p.y << ")" << endl;

    if (belongs) {
        cout << "Точка принадлежит параболе." << endl;
    } else {
        cout << "Точка НЕ принадлежит параболе." << endl;
    }

    cout << "Координаты фокуса: (" << focus_x << ", " << focus_y << ")" << endl;
    cout << "Расстояние от директрисы до фокуса: " << distance << endl;

    return 0;
}
