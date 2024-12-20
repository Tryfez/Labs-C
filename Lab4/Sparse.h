#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;


template<typename T>
class vec {
private:
    unordered_map<size_t, T> elements; 
    size_t size;

public:
    vec(size_t size) : size(size) {}

    T& operator[](size_t index) {
        if (index >= size) throw out_of_range("Индекс вне диапазона");
        return elements[index];
    }

    const T operator[](size_t index) const {
        if (index >= size) throw out_of_range("Индекс вне диапазона");
        if (elements.find(index) != elements.end()) {
            return elements.at(index);
        }
        return T();
    }

    vec operator+(const vec& other) const {
        if (size != other.size) throw invalid_argument("Размеры векторов должны совпадать");
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

    T dot(const vec& other) const {
        if (size != other.size) throw invalid_argument("Размеры векторов должны совпадать");
        T result = T();
        for (const auto& [index, value] : elements) {
            result += value * other[index];
        }
        return result;
    }

    void print(const string& label = "") const {
        if (!label.empty()) {
            cout << label << ": ";
        }
        for (size_t i = 0; i < size; ++i) {
            cout << this->operator[](i) << " ";
        }
        cout << endl;
    }
};

template<typename T>
class Matr {
private:
    unordered_map<size_t, unordered_map<size_t, T>> elements;
    size_t rows, cols;

public:
    Matr(size_t rows, size_t cols) : rows(rows), cols(cols) {}

    T& operator()(size_t row, size_t col) {
        if (row >= rows || col >= cols) throw out_of_range("Индекс вне диапазона");
        return elements[row][col];
    }

    const T operator()(size_t row, size_t col) const {
        if (row >= rows || col >= cols) throw out_of_range("Индекс вне диапазона");
        if (elements.find(row) != elements.end() && elements.at(row).find(col) != elements.at(row).end()) {
            return elements.at(row).at(col);
        }
        return T();
    }

    Matr operator+(const Matr& other) const {
        if (rows != other.rows || cols != other.cols) throw invalid_argument("Размеры матриц должны совпадать");
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

    Matr transpose() const {
        Matr result(cols, rows);
        for (const auto& [row, row_map] : elements) {
            for (const auto& [col, value] : row_map) {
                result(col, row) = value;
            }
        }
        return result;
    }

    void print(const string& label = "") const {
        if (!label.empty()) {
            cout << label << ":\n";
        }
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cout << this->operator()(i, j) << " ";
            }
            cout << endl;
        }
    }
};