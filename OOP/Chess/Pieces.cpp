#include <iostream>
#include <cstring>
#include "Pieces.hpp"

Piece::Piece() : name(nullptr), column(0), row(0), color(' ') {}

Piece::Piece(char* name, char color, int column, int row){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->color = isColor(color) ? color : ' ';
    this->column = isSide(column) ? column : 0;
    this->row = isSide(row) ? row : 0;
}

Piece::~Piece(){
    if(name != nullptr){
        delete[] name;
        name = nullptr;
    }
}

bool Piece::isColor(char color) {
    return color == 'W' || color == 'B' || color == 'w' || color == 'b';
}

bool Piece::isSide(int side){
    return side > 0 && side <= MAX_SIDE;
}

bool Piece::setPosition(int column, int row) {
    if (isSide(column) && isSide(row)) {
        this->column = column;
        this->row = row;
        return true;
    }
    return false;
}

const char* Piece::getName() {
    return name ? name : "No name";
}

char Piece::getColor() {
    return color;
}

int Piece::getColumn() {
    return column;
}

int Piece::getRow() {
    return row;
}

Pawn::Pawn() : Piece() {}
Pawn::Pawn(char* name, char color, int column, int row) 
    : Piece("Pawn", color, column, row) {}
Pawn::~Pawn(){
    if(name != nullptr){
        delete[] name;
    }
}

Bishop::Bishop() : Piece() {}
Bishop::Bishop(char* name, char color, int column, int row) 
    : Piece("Bishop", color, column, row) {}
Bishop::~Bishop(){};

Knight::Knight() : Piece() {}
Knight::Knight(char* name, char color, int column, int row) 
    : Piece("Knight", color, column, row) {}
Knight::~Knight(){};

Rook::Rook() : Piece() {}
Rook::Rook(char* name, char color, int column, int row) 
    : Piece("Rook", color, column, row) {}
Rook::~Rook(){}

Queen::Queen() : Piece() {}
Queen::Queen(char* name, char color, int column, int row) 
    : Piece("Queen", color, column, row) {}
Queen::~Queen(){}

King::King() : Piece() {}
King::King(char* name, char color, int column, int row) 
    : Piece("King", color, column, row) {}
King::~King(){}

Board::Board() {
    for (int i = 0; i < MAX_SIDE; ++i) {
        for (int j = 0; j < MAX_SIDE; ++j) {
            board[i][j] = nullptr;
        }
    }
}

Board::~Board() {
    for (int i = 0; i < MAX_SIDE; ++i) {
        for (int j = 0; j < MAX_SIDE; ++j) {
            if (board[i][j] != nullptr) {
                delete board[i][j];
                board[i][j] = nullptr;  // Set to nullptr after deletion to avoid double deletion
            }
        }
    }
}

void Board::printBoard() {
    for (int i = 0; i < MAX_SIDE; ++i) {
        for (int j = 0; j < MAX_SIDE; ++j) {
            if (board[i][j] != nullptr) {
                std::cout << board[i][j] << " ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
}

void Board::placePiece(Piece* piece, int column, int row) {
    if (isSide(column) && isSide(row)) {
        //std::cout << "Placing piece at column: " << column << ", row: " << row << std::endl; // Debug output
        if (board[column][row] != nullptr) {
            delete board[column][row];
            board[column][row] = nullptr;
        }
        board[column][row] = piece;
        piece->setPosition(column, row);
    }
}


