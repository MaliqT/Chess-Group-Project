#pragma once
#include "includes.h"
#include"Pieces.h"

class Pawn : public Pieces
{
public:
	Pawn();

	// member functions
	// getters
	Sprite getWhitePawnPiece() const;
	Sprite getBlackPawnPiece() const;

	bool moveCheck(int oldX, int oldY, int newX, int newY, int board[8][8], int color);

private:
	Texture whitePawn;
	Texture blackPawn;
};

