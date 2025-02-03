#pragma once
#include "includes.h"
#include "Pieces.h"

class Bishop : public Pieces
{
public:
	Bishop();
	
	//member functions
	// getters
	Sprite getWhiteBishopPiece() const;
	Sprite getBlackBishopPiece() const;

	bool moveCheck(int oldX, int oldY, int newX, int newY, int board[8][8], int color);
private:
	Texture blackBishop;
	Texture whiteBishop;
};

