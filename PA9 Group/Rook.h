#pragma once
#include "includes.h"
#include "Pieces.h"

class Rook : public Pieces
{
public:
	Rook();

	//member functions
	//getters
	Sprite getWhiteRookPiece() const;
	Sprite getBlackRookPiece() const;

	bool moveCheck(int oldX, int oldY, int newX, int newY, int board[8][8], int color);
private:
	Texture whiteRook;
	Texture blackRook;
};

