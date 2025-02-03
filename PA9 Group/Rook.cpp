#include "Rook.h"

Rook::Rook()
{
	if (!whiteRook.loadFromFile("images/WRook.png"))
	{
		cout << "Error loading Rook Texture" << endl;
	}
	else
	{
		cout << "Successfully loaded Rook texture" << endl;
	}
	blackRook.loadFromFile("images/BRook.png");
}

Sprite Rook::getWhiteRookPiece() const
{
	Sprite rook(whiteRook);
	rook.setScale(1.65f, 1.5f);
	return rook;
}

Sprite Rook::getBlackRookPiece() const
{
	Sprite rook(blackRook);
	rook.setScale(1.65f, 1.5f);
	return rook;
}

bool Rook::moveCheck(int oldX, int oldY, int newX, int newY, int board[8][8], int color)
{
	// Rook can move to any space horizontally and vertically as long as the space is free or 0
	// use for loop to determine if space is free

	// Rook going to the right
	for (int i = oldX + 1; i <= 7; i++)
	{
		if (color == WHITE_ROOK) // check for color
		{
			if (board[oldY][i] <= 0 && (newY == oldY && newX == i))
			{
				return true;
			}
			else if (board[oldY][i] != 0) // otherwise, break loop and return false
			{
				break;
			}
		}
		if (color == BLACK_ROOK)
		{
			if (board[oldY][i] >= 0 && (newY == oldY && newX == i))
			{
				return true;
			}
			else if (board[oldY][i] != 0)
			{
				break;
			}
		}
	}
	// Rook going to the left
	for (int i = oldX - 1; i >= 0; i--)
	{
		if (color == WHITE_ROOK)
		{
			if (board[oldY][i] <= 0 && (newY == oldY && newX == i))
			{
				return true;
			}
			else if (board[oldY][i] != 0)
			{
				break;
			}
		}
		if (color == BLACK_ROOK)
		{
			if (board[oldY][i] >= 0 && (newY == oldY && newX == i))
			{
				return true;
			}
			else if (board[oldY][i] != 0)
			{
				break;
			}
		}
	}
	// Rook going up
	for (int i = oldY - 1; i >= 0; i--)
	{
		if (color == WHITE_ROOK)
		{
			if (board[i][oldX] <= 0 && (newY == i && newX == oldX))
			{
				return true;
			}
			else if (board[i][oldX] != 0)
			{
				break;
			}
		}
		if (color == BLACK_ROOK)
		{
			if (board[i][oldX] >= 0 && (newY == i && newX == oldX))
			{
				return true;
			}
			else if (board[i][oldX] != 0)
			{
				break;
			}
		}
	}
	// Rook going down
	for (int i = oldY + 1; i <= 7; i++)
	{
		if (color == WHITE_ROOK)
		{
			if (board[i][oldX] <= 0 && (newY == i && newX == oldX))
			{
				return true;
			}
			else if (board[i][oldX] != 0)
			{
				break;
			}
		}
		if (color == BLACK_ROOK)
		{
			if (board[i][oldX] >= 0 && (newY == i && newX == oldX))
			{
				return true;
			}
			else if (board[i][oldX] != 0)
			{
				break;
			}
		}
	}
	return false;
}