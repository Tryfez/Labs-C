#pragma once
#ifndef CHESS_H
#define CHESS_H
#include <iostream>
#include <string>

using namespace std;

class Chess {
private:
    string pieceType;
    string position;

public:
    Chess();//по умолчанию

    Chess(const string& type, const string& pos);//конструктор с параметрами

    Chess(const Chess& other);//конструктор копирования

    Chess(Chess&& other) noexcept; //конструктор для перемещения

    Chess& operator=(const Chess& other);//оператор присваивания (копирования), при использовании, p1 = p2, фигура p1 скопирует характеристики

    Chess& operator=(Chess&& other) noexcept;//перемещения, при использовании p1 = p2, фигура p1 получит значения p2, p2 будет пустым 

    void printInfo() const;//вывод информации о фигуре

    ~Chess();//деструктор 

    void moveTo(const string& newPosition);

    double getValue() const; // Получить числовое значение для сортировки
    string getPieceType() const; // Получить тип фигуры
    bool operator<(const Chess& other) const;
    bool operator>(const Chess& other) const;
    bool operator==(const Chess& other) const;
};

#endif
