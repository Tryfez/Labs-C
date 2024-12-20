#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <stdexcept>



// Шаблонный класс разреженного вектора
template<typename T>
class vec {
private:
    std::unordered_map<size_t, T> elements; // индекс-значение
    size_t size;

public:
    // Конструктор
    vec(size_t size) : size(size) {}

    // Доступ к элементу по индексу
    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Индекс вне диапазона");
        return elements[index];
    }

    // Получить значение элемента (константный доступ)
    const T operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Индекс вне диапазона");
        if (elements.find(index) != elements.end()) {
            return elements.at(index);
        }
        return T(); // Значение по умолчанию
    }

    // Сложение векторов
    vec operator+(const vec& other) const {
        if (size != other.size) throw std::invalid_argument("Размеры векторов должны совпадать");
        vec result(size);
        for (const auto& [index, value] : elements) {
            result[index] = value + other[index];
        }
        for (const auto& [index, value] : other.elements) {
            if (elements.find(index) == elements.end()) {
                result[index] = value;
            }
        }
        return result;
    }

    // Скалярное произведение
    T dot(const vec& other) const {
        if (size != other.size) throw std::invalid_argument("Размеры векторов должны совпадать");
        T result = T();
        for (const auto& [index, value] : elements) {
            result += value * other[index];
        }
        return result;
    }

    // Печать вектора для отладки
    void print(const std::string& label = "") const {
        if (!label.empty()) {
            std::cout << label << ": ";
        }
        for (size_t i = 0; i < size; ++i) {
            std::cout << this->operator[](i) << " ";
        }
        std::cout << std::endl;
    }
};

// Шаблонный класс разреженной матрицы
template<typename T>
class Matr {
private:
    std::unordered_map<size_t, std::unordered_map<size_t, T>> elements; // строка-столбец-значение
    size_t rows, cols;

public:
    // Конструктор
    Matr(size_t rows, size_t cols) : rows(rows), cols(cols) {}

    // Доступ к элементу по индексу (строка, столбец)
    T& operator()(size_t row, size_t col) {
        if (row >= rows || col >= cols) throw std::out_of_range("Индекс вне диапазона");
        return elements[row][col];
    }

    // Получить значение элемента (константный доступ)
    const T operator()(size_t row, size_t col) const {
        if (row >= rows || col >= cols) throw std::out_of_range("Индекс вне диапазона");
        if (elements.find(row) != elements.end() && elements.at(row).find(col) != elements.at(row).end()) {
            return elements.at(row).at(col);
        }
        return T(); // Значение по умолчанию
    }

    // Сложение матриц
    Matr operator+(const Matr& other) const {
        if (rows != other.rows || cols != other.cols) throw std::invalid_argument("Размеры матриц должны совпадать");
        Matr result(rows, cols);
        for (const auto& [row, row_map] : elements) {
            for (const auto& [col, value] : row_map) {
                result(row, col) = value + other(row, col);
            }
        }
        for (const auto& [row, row_map] : other.elements) {
            for (const auto& [col, value] : row_map) {
                if (elements.find(row) == elements.end() || elements.at(row).find(col) == elements.at(row).end()) {
                    result(row, col) = value;
                }
            }
        }
        return result;
    }

    // Транспонирование матрицы
    Matr transpose() const {
        Matr result(cols, rows);
        for (const auto& [row, row_map] : elements) {
            for (const auto& [col, value] : row_map) {
                result(col, row) = value;
            }
        }
        return result;
    }

    // Печать матрицы для отладки
    void print(const std::string& label = "") const {
        if (!label.empty()) {
            std::cout << label << ":\n";
        }
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << this->operator()(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};