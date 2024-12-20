#include <iostream>
#include "Sparse.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vec<int> vec1(5);
    vec1[0] = 1;
    vec1[3] = 4;
    vec1.print("Вектор 1");

    vec<int> vec2(5);
    vec2[2] = 3;
    vec2[3] = 5;
    vec2.print("Вектор 2");

    vec<int> vec3 = vec1 + vec2;
    vec3.print("Сумма векторов");

    int dot_product = vec1.dot(vec2);
    std::cout << "Скалярное произведение: " << dot_product << std::endl;

    Matr<int> mat1(3, 3);
    mat1(0, 0) = 1;
    mat1(1, 1) = 2;
    mat1(2, 2) = 3;
    mat1.print("Матрица 1");

    Matr<int> mat2(3, 3);
    mat2(0, 2) = 4;
    mat2(1, 0) = 5;
    mat2(2, 1) = 6;
    mat2.print("Матрица 2");

    Matr<int> mat3 = mat1 + mat2;
    mat3.print("Сумма матриц");

    Matr<int> transposed = mat1.transpose();
    transposed.print("Транспонированная матрица 1");

    return 0;
}