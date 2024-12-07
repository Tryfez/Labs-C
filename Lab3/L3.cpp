#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <algorithm>
#include <numeric>
#include "Chess.h"

vector<string> generatePositions();

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist_size(500, 1000);

    //1: Создать вектор v1 случайного размера и заполнить его объектами класса Chess
    cout << "1. ";
    int vector_size = dist_size(gen);
    vector<Chess> v1;
    vector<string> pieceTypes = { "Pawn", "Rook", "Knight", "Bishop", "Queen", "King" };
    vector<string> positions = generatePositions();

    for (int i = 0; i < vector_size; ++i) 
    {
        string type = pieceTypes[i % pieceTypes.size()];
        string position = positions[i % positions.size()];
        v1.emplace_back(type, position);
    }
    cout << "Создан вектор v1 размером " << vector_size << endl;

    //2: Создать вектор v2 из последних 200 элементов v1
    cout << "2. ";
    vector<Chess> v2(v1.end() - 200, v1.end());
    v1.erase(v1.end() - 200, v1.end());
    cout << "Создан вектор v2 из последних 200 элементов v1" << endl;

    //3: Сформировать list1 из n (от 20 до 50) наибольших элементов вектора v1
    cout << "3. ";
    uniform_int_distribution<int> dist_n1(20, 50);
    int n1 = dist_n1(gen);

    partial_sort(v1.begin(), v1.begin() + n1, v1.end(), [](const Chess& a, const Chess& b) {
        return a > b;
        });

    list<Chess> list1(v1.begin(), v1.begin() + n1);
    v1.erase(v1.begin(), v1.begin() + n1);
    cout << "Создан список list1 из " << n1 << " наибольших элементов вектора v1" << endl;

    //4: Сформировать list2 из n (от 20 до 50) наименьших элементов вектора v2
    cout << "4. ";
    uniform_int_distribution<int> dist_n2(20, 50);
    int n2 = dist_n2(gen);

    partial_sort(v2.begin(), v2.begin() + n2, v2.end(), [](const Chess& a, const Chess& b) 
    {
        return a < b;
    });

    list<Chess> list2(v2.begin(), v2.begin() + n2);
    v2.erase(v2.begin(), v2.begin() + n2);
    cout << "Создан список list2 из " << n2 << " наименьших элементов вектора v2" << endl;

    //5: Найти среднее значение для list1 и перегруппировать элементы
    cout << "5. ";
    double average_value = accumulate(list1.begin(), list1.end(), 0.0, [](double sum, const Chess& item)
    {
        return sum + item.getValue();  // getValue() — необходимо добавить в Chess
    }) / list1.size();

        cout << "Среднее значение параметра в list1: " << average_value << endl;

        list1.sort([average_value](const Chess& a, const Chess& b) 
        {
            return a.getValue() > b.getValue();
        });

        list<Chess> greater_than_average;
        for (auto it = list1.begin(); it != list1.end(); ) 
        {
            if (it->getValue() > average_value) 
            {
                greater_than_average.push_back(*it);
                it = list1.erase(it);
            }
            else 
                ++it;
            
        }

        list1.splice(list1.begin(), greater_than_average);
        cout << "Элементы list1 перегруппированы так, что сначала идут элементы больше среднего" << endl;

        //6: Удалить из list2 элементы по критерию 
        cout << "6. ";
        list2.remove_if([](const Chess& item)
        {
            int piece_value = 0;
            if (item.getPieceType() == "Pawn") piece_value = 1;
            else if (item.getPieceType() == "Knight") piece_value = 2;
            else if (item.getPieceType() == "Bishop") piece_value = 3;
            else if (item.getPieceType() == "Rook") piece_value = 5;
            else if (item.getPieceType() == "Queen") piece_value = 8;
            else if (item.getPieceType() == "King") piece_value = 0;
            return piece_value % 2 != 0;
        });

        cout << "Удалены элементы из list2, стоимость которых в пешечном эквиваленте нечетная" << endl;

        //7: Создать вектор v3 из элементов, которые есть и в v1, и в v2
        cout << "7. ";
        vector<Chess> v3;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
        cout << "Создан вектор v3 из элементов, которые есть и в v1, и в v2" << endl;

        //8: Привести размеры списков list1 и list2 к одинаковому размеру и создать list3
        cout << "8. ";
        int size_diff = abs((int)list1.size() - (int)list2.size()); //n 

        if (list1.size() > list2.size())
            list1.erase(list1.begin(), next(list1.begin(), size_diff));
        else if (list2.size() > list1.size())         
            list2.erase(list2.begin(), next(list2.begin(), size_diff));       

        list<pair<Chess, Chess>> list3;
        transform(list1.begin(), list1.end(), list2.begin(), back_inserter(list3), [](const Chess& a, const Chess& b)
        {
            return make_pair(a, b);
        });

        cout << "Создан список list3 из пар элементов list1 и list2:" << endl;
        int C = 1;
        for_each(list3.begin(), list3.end(), [&C](const pair<Chess, Chess>& pair) 
        {
            cout << '[' << C << "] Пара: " << endl;
            cout << ' ';
            pair.first.printInfo();
            cout << ' ';
            pair.second.printInfo();
            C++;
        });


        //9: Создать пары из элементов v1 и v2 без приведения к одинаковому размеру
        cout << "9. ";
        size_t min_size = min(v1.size(), v2.size());
        list<pair<Chess, Chess>> list4;
        transform(v1.begin(), v1.begin() + min_size, v2.begin(), back_inserter(list4), [](const Chess& a, const Chess& b)
        {
            return make_pair(a, b);
        });
        cout << "Создан список list4 из пар элементов v1 и v2 без приведения размеров" << endl;

        C = 1;
        for_each(list4.begin(), list4.end(), [&C](const pair<Chess, Chess>& pair) 
        {
            cout << '[' << C << "] Пара: " << endl;
            cout << ' ';
            pair.first.printInfo();
            cout << ' ';
            pair.second.printInfo();
            C++;
        });

         cout << endl;

        cout << "Все шаги выполнены успешно" << endl;
        return 0;
}

vector<string> generatePositions() {
    vector<string> positions;
    for (char column = 'A'; column <= 'H'; ++column) {
        for (char row = '1'; row <= '8'; ++row) {
            positions.emplace_back(string(1, column) + row);
        }
    }
    return positions;
}
