#include "Pawn.h"

Pawn::Pawn()
{
	if (!whitePawn.loadFromFile("images/WPawn.png")) {
		cout << "Error loading Pawn texture" << endl;
	}
	else {
		cout << "Succesfully Loaded Pawn Texture" << endl;
	}
	blackPawn.loadFromFile("images/BPawn.png");

}

Sprite Pawn::getWhitePawnPiece() const
{
	Sprite pawn(whitePawn);
	pawn.setScale(1.65f, 1.5f);
	return pawn;
}

Sprite Pawn::getBlackPawnPiece() const
{
	Sprite pawn(blackPawn);
	pawn.setScale(1.65f, 1.5f);
	return pawn;
}

bool Pawn::moveCheck(int oldX, int oldY, int newX, int newY, int board[8][8], int color)
{
	int oneSpace = board[oldY + 1][oldX], twoSpace = board[oldY + 2][oldX];
	int killLeft = board[oldY + 1][oldX - 1], killRight = board[oldY + 1][oldX + 1];
	// Check first move of pawn

	// White pawn's first move
	if (color == WHITE_PAWN)
	{
		if (oldY == 1)
		{
			// Check to see if the space ahead is free and only the first two spaces
			if ((newY == oldY + 1 && newX == oldX && oneSpace == 0) || (newY == oldY + 2 && newX == oldX && oneSpace == 0 && twoSpace == 0))
			{
				// this move is valid on the board
				return true;
			}
		}
		else if (newY == oldY + 1 && newX == oldX && oneSpace == 0)
		{
			return true;
		}
		// check for kill for White
		if (newY == oldY + 1 && newX == oldX - 1 && killLeft < 0)
		{
			return true;
		}
		if (newY == oldY + 1 && newX == oldX + 1 && killRight < 0)
		{
			return true;
		}

	}

	if (color == BLACK_PAWN)
	{
		oneSpace = board[oldY - 1][oldX];
		twoSpace = board[oldY - 2][oldX];

		// Black pawn's first move
		if (oldY == 6) // ------ refer to the grid @ includes.h
		{
			if ((newY == oldY - 1 && newX == oldX && oneSpace == 0) || (newY == oldY - 2 && newX == oldX && oneSpace == 0 && twoSpace == 0))
			{
				return true;
			}
		}
		else if (newY == oldY - 1 && newX == oldX && oneSpace == 0)
		{
			return true;
		}

		killLeft = board[oldY - 1][oldX - 1];
		killRight = board[oldY - 1][oldX + 1];
		// Check for kill for Black

		if (newY == oldY - 1 && newX == oldX - 1 && killLeft > 0)
		{
			return true;
		}
		if (newY == oldY - 1 && newX == oldX + 1 && killRight > 0)
		{
			return true;
		}
	}

	return false;
}