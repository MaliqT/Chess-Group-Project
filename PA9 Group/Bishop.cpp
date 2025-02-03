#include "Bishop.h"

Bishop::Bishop()
{
	if (!whiteBishop.loadFromFile("images/WBishop.png")) {
		cout << "Error loading Bishop texture" << endl;
	}
	else {
		cout << "Successfuly loaded Bishop texture" << endl;
	}
	blackBishop.loadFromFile("images/BBishop.png");
}

Sprite Bishop::getWhiteBishopPiece() const
{
	Sprite bishop(whiteBishop);
	bishop.setScale(1.65f, 1.5f);
	return bishop;
}

Sprite Bishop::getBlackBishopPiece() const
{
	Sprite bishop(blackBishop);
	bishop.setScale(1.65f, 1.5f);
	return bishop;
}

bool Bishop::moveCheck(int oldX, int oldY, int newX, int newY, int board[8][8], int color)
{

	int j;
	// nearly the same code as the rook but diagonally

	// Bishop diagonal down right
	// need to initialize an x variable (j) to increment condition
	j = oldX + 1;

	for (int i = oldY + 1; i <= 7; i++)
	{
		if (color == WHITE_BISHOP)
		{
			if (board[i][j] <= 0 && (newY == i && newX == j))
			{
				return true;
			}
			else if (board[i][j] != 0)
			{
				break;
			}
		}
		if (color == BLACK_BISHOP)
		{
			if (board[i][j] >= 0 && (newY == i && newX == j))
			{
				return true;
			}
			else if (board[i][j] != 0)
			{
				break;
			}
		}
		j++;
	}
	// Bishop diagonally down left
	j = oldX - 1;

	for (int i = oldY + 1; i <= 7; i++)
	{
		if (color == WHITE_BISHOP)
		{
			if (board[i][j] <= 0 && (newY == i && newX == j))
			{
				return true;
			}
			else if (board[i][j] != 0)
			{
				break;
			}
		}
		if (color == BLACK_BISHOP)
		{
			if (board[i][j] >= 0 && (newY == i && newX == j))
			{
				return true;
			}
			else if (board[i][j] != 0)
			{
				break;
			}
		}
		j--;
	}
	// Bishop diagonally up right
	j = oldX + 1;

	for (int i = oldY - 1; i >= 0; i--)
	{
		if (color == WHITE_BISHOP)
		{
			if (board[i][j] <= 0 && (newY == i && newX == j))
			{
				return true;
			}
			else if (board[i][j] != 0)
			{
				break;
			}
		}
		if (color == BLACK_BISHOP)
		{
			if (board[i][j] >= 0 && (newY == i && newX == j))
			{
				return true;
			}
			else if (board[i][j] != 0)
			{
				break;
			}
		}
		j++;
	}
	// Bishop diagonally up left
	j = oldX - 1;

	for (int i = oldY - 1; i >= 0; i--)
	{
		if (color == WHITE_BISHOP)
		{
			if (board[i][j] <= 0 && (newY == i && newX == j))
			{
				return true;
			}
			else if (board[i][j] != 0)
			{
				break;
			}
		}
		if (color == BLACK_BISHOP)
		{
			if (board[i][j] >= 0 && (newY == i && newX == j))
			{
				return true;
			}
			else if (board[i][j] != 0)
			{
				break;
			}
		}
		j--;
	}

	return false;
}