#pragma once
#include "includes.h"
#include "Pieces.h"

class Queen : public Pieces
{
public:
	Queen();

	//member functions
	//getters
	Sprite getWhiteQueenPiece() const;
	Sprite getBlackQueenPiece() const;

	bool moveCheck(int oldX, int oldY, int newX, int newY, int board[8][8], int color);
private:
	Texture whiteQueen;
	Texture blackQueen;
};

