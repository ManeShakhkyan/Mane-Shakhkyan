#ifndef PIECES_HPP
#define PIECES_HPP

#define MAX_SIDE 8

class Piece{
	protected:
		char* name;
		int column;
		int row;
		char color;

		bool isColor(char color);
		bool isSide(int side);
	
	public:
		Piece();
		Piece(char* name, char color, int column, int row);		
		virtual ~Piece();

		bool setPosition(int column, int row);

		const char* getName();
		char getColor();
		int getColumn();
		int getRow();
};

class Pawn : public Piece {
	public:
		Pawn();
		Pawn(char* name, char color, int coumn, int row);
		~Pawn();
};

class Bishop : public Piece {
	public:
		Bishop();
		Bishop(char* name, char color, int coumn, int row);
		~Bishop();
};	

class Knight : public Piece {
	public:
		Knight();
		Knight(char * name, char color, int coumn, int row);
		~Knight();
};

class Rook : public Piece {
	public:
		Rook();
		Rook(char* name, char color, int coumn, int row);
		~Rook();
};

class Queen : public Piece {
	public:
		Queen();
		Queen(char* name, char color, int coumn, int row);
		~Queen();
};

class King : public Piece {
	public:
		King();
		King(char* name, char color, int coumn, int row);
		~King();
};

class Board : public Piece {
	private:
		Piece* board[MAX_SIDE][MAX_SIDE];

	public:
		Board();
		~Board();

		void printBoard();
		void placePiece(Piece* piece, int column, int row);
};

#endif
