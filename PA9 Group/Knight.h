#pragma once
#include "includes.h"
#include "Pieces.h"

class Knight : public Pieces
{
public:
	Knight();

	// member functions
	// getters
	Sprite getWhiteKnightPiece() const;
	Sprite getBlackKnightPiece() const;

	bool moveCheck(int oldX, int oldY, int newX, int newY, int board[8][8], int color);
private:
	Texture whiteKnight;
	Texture blackKnight;
};

