#include <iostream>
#include "Pieces.hpp"

int main() {
    Board chessBoard;

    // Create a few pieces
    Rook* whiteRook = new Rook("Rook", 'W', 1, 1);
    Knight* whiteKnight = new Knight("Knight", 'W', 2, 1);
    Bishop* whiteBishop = new Bishop("Bishop", 'W', 3, 1);
    Queen* whiteQueen = new Queen("Queen", 'W', 4, 1);
    King* whiteKing = new King("King", 'W', 5, 1);
    Pawn* whitePawn = new Pawn("Pawn", 'W', 1, 2);

    // Place the pieces on the board
    chessBoard.placePiece(whiteRook, 1, 1);
    chessBoard.placePiece(whiteKnight, 2, 1);
    chessBoard.placePiece(whiteBishop, 3, 1);
    chessBoard.placePiece(whiteQueen, 4, 1);
    chessBoard.placePiece(whiteKing, 5, 1);
    chessBoard.placePiece(whitePawn, 1, 2);

    // Print the board
    chessBoard.printBoard();

    // Clean up
    delete whiteRook;
    delete whiteKnight;
    delete whiteBishop;
    delete whiteQueen;
    delete whiteKing;
    delete whitePawn;

    return 0;
}
