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
    Chess();//�� ���������

    Chess(const string& type, const string& pos);//����������� � �����������

    Chess(const Chess& other);//����������� �����������

    Chess(Chess&& other) noexcept; //����������� ��� �����������

    Chess& operator=(const Chess& other);//�������� ������������ (�����������), ��� �������������, p1 = p2, ������ p1 ��������� ��������������

    Chess& operator=(Chess&& other) noexcept;//�����������, ��� ������������� p1 = p2, ������ p1 ������� �������� p2, p2 ����� ������ 

    void printInfo() const;//����� ���������� � ������

    ~Chess();//���������� 

    void moveTo(const string& newPosition);

    double getValue() const; // �������� �������� �������� ��� ����������
    string getPieceType() const; // �������� ��� ������
    bool operator<(const Chess& other) const;
    bool operator>(const Chess& other) const;
    bool operator==(const Chess& other) const;
};

#endif
