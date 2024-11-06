#include "Chess.h"

Chess::Chess(const std::string& type, const std::string& pos)
    : pieceType(type), position(pos) {
    std::cout << "Constructor: " << pieceType << " at " << position << std::endl;
}

Chess::Chess(const Chess& other)
    : pieceType(other.pieceType), position(other.position) {
    std::cout << "Copy constructor: " << pieceType << " at " << position << std::endl;
}

Chess::Chess(Chess&& other) noexcept
    : pieceType(std::move(other.pieceType)), position(std::move(other.position)) {
    std::cout << "Move constructor: " << pieceType << " at " << position << std::endl;
}

Chess& Chess::operator=(const Chess& other) {
    if (this == &other)
        return *this;
    pieceType = other.pieceType;
    position = other.position;
    std::cout << "Copy assignment: " << pieceType << " at " << position << std::endl;

    return *this;
}

Chess& Chess::operator=(Chess&& other) noexcept {
    if (this == &other)
        return *this; 
    pieceType = std::move(other.pieceType);
    position = std::move(other.position);
    std::cout << "Move assignment: " << pieceType << " at " << position << std::endl;

    return *this;
}

Chess::~Chess() {
    std::cout << "Destructor: " << pieceType << " at " << position << std::endl;
}

void Chess::printInfo() const {
    std::cout << pieceType << " at " << position << std::endl;
}
