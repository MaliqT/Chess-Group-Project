#include "Queen.h"

Queen::Queen()
{
	if (!whiteQueen.loadFromFile("images/WQueen.png")) {
		cout << "Error Loading Queen texture" << endl;
	}
	else {
		cout << "Successfully loaded Queen texture" << endl;
	}
	blackQueen.loadFromFile("images/BQueen.png");
}

Sprite Queen::getWhiteQueenPiece() const
{
	Sprite queen(whiteQueen);
	queen.setScale(1.65f, 1.5f);
	return queen;
}

Sprite Queen::getBlackQueenPiece() const
{
	Sprite queen(blackQueen);
	queen.setScale(1.65f, 1.5f);
	return queen;
}

bool Queen::moveCheck(int oldX, int oldY, int newX, int newY, int board[8][8], int color)
{
	// Will be using code from both rook and bishop
	int j;

	// loop for moving queen to the right
	for (int i = oldX + 1; i <= 7; i++)
	{
		if (color == WHITE_QUEEN)
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
		if (color == BLACK_QUEEN)
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
	for (int i = oldX - 1; i >= 0; i--)
	{
		if (color == WHITE_QUEEN)
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
		if (color == BLACK_QUEEN)
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
	// QUEEN going up
	for (int i = oldY - 1; i >= 0; i--)
	{
		if (color == WHITE_QUEEN)
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
		if (color == BLACK_QUEEN)
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
	// QUEEN going down
	for (int i = oldY + 1; i <= 7; i++)
	{
		if (color == WHITE_QUEEN)
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
		if (color == BLACK_QUEEN)
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
	j = oldX + 1;

	for (int i = oldY + 1; i <= 7; i++)
	{
		if (color == WHITE_QUEEN)
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
		if (color == BLACK_QUEEN)
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
	// QUEEN diagonally down left
	j = oldX - 1;

	for (int i = oldY + 1; i <= 7; i++)
	{
		if (color == WHITE_QUEEN)
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
		if (color == BLACK_QUEEN)
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
	// QUEEN diagonally up right
	j = oldX + 1;

	for (int i = oldY - 1; i >= 0; i--)
	{
		if (color == WHITE_QUEEN)
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
		if (color == BLACK_QUEEN)
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
	// QUEEN diagonally up left
	j = oldX - 1;

	for (int i = oldY - 1; i >= 0; i--)
	{
		if (color == WHITE_QUEEN)
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
		if (color == BLACK_QUEEN)
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