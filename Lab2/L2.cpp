#include "Chess.h"
#include <vector>
#include <list>

using namespace std;

int main() {

    Chess king("King", "e1");//статическое 
    Chess queen("Queen", "d1");

    Chess* bishop = new Chess("Bishop", "c1");//динамическое создание
    delete bishop;

    vector<Chess> piecesVector;//вектор
    piecesVector.emplace_back("Rook", "a1");
    piecesVector.emplace_back("Knight", "b1");

    list<Chess> piecesList;//список
    piecesList.emplace_back("Pawn", "a2");
    piecesList.emplace_back("Pawn", "b2");

    Chess rook("Rook", "h1");//копирование
    Chess anotherRook = rook;
    Chess movedRook = move(rook);

    for (size_t i = 0; i < piecesVector.size(); i++) {
        piecesVector[i].printInfo();
    }
    for (const auto& piece : piecesList) {
        piece.printInfo();
    }

    return 0;
}
