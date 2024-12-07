#include "Chess.h"

using namespace std;


Chess::Chess() :
    pieceType("Piece"), position("the board") {
   // cout << "Default constructor: " << pieceType << " on " << position << std::endl;
}

Chess::Chess(const string& type, const string& pos)
    : pieceType(type), position(pos) {
  //  cout << "Constructor: " << pieceType << " at " << position << endl;
}

Chess::Chess(const Chess& other)
    : pieceType(other.pieceType), position(other.position) {
   // cout << "Copy constructor: " << pieceType << " at " << position << endl;
}

Chess::Chess(Chess&& other) noexcept
    : pieceType(move(other.pieceType)), position(move(other.position)) {
   // cout << "Move constructor: " << pieceType << " at " << position << endl;
}

Chess& Chess::operator=(const Chess& other) {
    if (this == &other)
        return *this;       
    pieceType = other.pieceType;
    position = other.position;
  //  cout << "Copy assignment: " << pieceType << " at " << position << endl;

    return *this;
}

Chess& Chess::operator=(Chess&& other) noexcept{
    if (this == &other)
        return *this; 
    pieceType = move(other.pieceType);
    position = move(other.position);
   // cout << "Move assignment: " << pieceType << " at " << position << endl;

    return *this;
}

Chess::~Chess() {
   // cout << "Destructor: " << pieceType << " at " << position << endl;
}

void Chess::printInfo() const {
    cout << pieceType << " at " << position << endl;
}


void Chess::moveTo(const std::string& newPosition) {
    position = newPosition;
   // std::cout << pieceType << " moved to " << position << std::endl;
}

//Лаба 3 
double Chess::getValue() const {
    return static_cast<double>(position[1] - '0'); // Например, номер строки на шахматной доске (A1 -> 1)
}

string Chess::getPieceType() const {
    return pieceType;
}

bool Chess::operator<(const Chess& other) const {
    return this->getValue() < other.getValue();
}

bool Chess::operator>(const Chess& other) const {
    return this->getValue() > other.getValue();
}

bool Chess::operator==(const Chess& other) const {
    return this->pieceType == other.pieceType && this->position == other.position;
}


