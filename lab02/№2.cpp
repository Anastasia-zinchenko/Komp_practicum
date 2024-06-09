#include <iostream>
#include <cmath>
#include <vector>

struct Vector3D {
    double x, y, z;
};

double dotProduct(const Vector3D& v1, const Vector3D& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

double vectorLength(const Vector3D& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double angleBetweenVectors(const Vector3D& v1, const Vector3D& v2) {
    double dot = dotProduct(v1, v2);
    double v1Length = vectorLength(v1);
    double v2Length = vectorLength(v2);

    return acos(dot / (v1Length * v2Length));
}

int main() {
    std::vector<Vector3D> vectors(3);

    for (int i = 0; i < 3; ++i) {
        vectors[i].x = rand() % 10;
        vectors[i].y = rand() % 10;
        vectors[i].z = rand() % 10;

        std::cout << "Vector " << i + 1 << ": (" << vectors[i].x << ", " << vectors[i].y << ", " << vectors[i].z << ")" << std::endl;
    }

    // Find lengths of vectors
    for (int i = 0; i < 3; ++i) {
        double length = vectorLength(vectors[i]);
        std::cout << "Length of Vector " << i + 1 << ": " << length << std::endl;
    }

    // Find angles between vectors
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            double angle = angleBetweenVectors(vectors[i], vectors[j]);
            std::cout << "Angle between Vector " << i + 1 << " and Vector " << j + 1 << ": " << angle << " radians" << std::endl;
        }
    }

    // Find sum and difference of vectors
    Vector3D sum = {vectors[0].x + vectors[1].x + vectors[2].x, vectors[0].y + vectors[1].y + vectors[2].y, vectors[0].z + vectors[1].z + vectors[2].z};
    Vector3D difference = {vectors[0].x - vectors[1].x - vectors[2].x, vectors[0].y - vectors[1].y - vectors[2].y, vectors[0].z - vectors[1].z - vectors[2].z};
    std::cout << "Sum of vectors: (" << sum.x << ", " << sum.y << ", " << sum.z << ")" << std::endl;
    std::cout << "Difference of vectors: (" << difference.x << ", " << difference.y << ", " << difference.z << ")" << std::endl;

    // Check if vectors are coplanar
    double vol = vectors[0].x * (vectors[1].y * vectors[2].z - vectors[1].z * vectors[2].y) - vectors[0].y * (vectors[1].x * vectors[2].z - vectors[1].z * vectors[2].x) + vectors[0].z * (vectors[1].x * vectors[2].y - vectors[1].y * vectors[2].x);
    if (vol == 0) {
        std::cout << "The vectors are coplanar." << std::endl;
    } else {
        std::cout << "The vectors are not coplanar." << std::endl;
    }

    // Check for parallel vectors
    if (angleBetweenVectors(vectors[0], vectors[1]) == 0 || angleBetweenVectors(vectors[1], vectors[2]) == 0 || angleBetweenVectors(vectors[0], vectors[2]) == 0) {
        std::cout << "There are parallel vectors among the given vectors." << std::endl;
    } else {
        std::cout << "There are no parallel vectors among the given vectors." << std::endl;
    }

    return 0;
}
