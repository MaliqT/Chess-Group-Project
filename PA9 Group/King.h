#pragma once
#include "includes.h"
#include "Pieces.h"

class King : public Pieces
{
public:
	King();

	//member functions
	//getters
	Sprite getWhiteKingPiece() const;
	Sprite getBlackKingPiece() const;

	bool moveCheck(int oldX, int oldY, int newX, int newY, int board[8][8], int color);

private:
	Texture whiteKing;
	Texture blackKing;
};

