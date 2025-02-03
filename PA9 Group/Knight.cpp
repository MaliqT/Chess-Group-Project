#include "Knight.h"

Knight::Knight()
{
	if (!whiteKnight.loadFromFile("images/WKnight.png"))
	{
		cout << "Error Loading Knight file" << endl;
	}
	else {

		cout << "Successfully Loaded Knight texture" << endl;
	}
	blackKnight.loadFromFile("images/BKnight.png");
}

Sprite Knight::getWhiteKnightPiece() const
{
	Sprite knight(whiteKnight);
	knight.setScale(1.65f, 1.5f);
	return knight;
}

Sprite Knight::getBlackKnightPiece() const
{
	Sprite knight(blackKnight);
	knight.setScale(1.65f, 1.5f);
	return knight;
}

bool Knight::moveCheck(int oldX, int oldY, int newX, int newY, int board[8][8], int color)
{
	if (color == WHITE_KNIGHT)
	{
		// move knight down right
		if ((board[oldY + 1][oldX] >= 0 && board[oldY + 2][oldX] >= 0)
			|| (board[oldY + 1][oldX] <= 0 && board[oldY + 2][oldX] <= 0))
		{
			if (newY == oldY + 2 && newX == oldX + 1)
			{
				if (board[oldY + 2][oldX + 1] <= 0)
				{
					return true;
				}
			}
		}
		// move knight down left
		if ((board[oldY + 1][oldX] >= 0 && board[oldY + 2][oldX] >= 0)
			|| (board[oldY + 1][oldX] <= 0 && board[oldY + 2][oldX] <= 0))
		{
			if (newY == oldY + 2 && newX == oldX - 1)
			{
				if (board[oldY + 2][oldX - 1] <= 0)
				{
					return true;
				}
			}
			
		}
		// move knight up right
		if ((board[oldY - 1][oldX] >= 0 && board[oldY - 2][oldX] >= 0)
			|| (board[oldY - 1][oldX] <= 0 && board[oldY - 2][oldX] <= 0))
		{
			if (newY == oldY - 2 && newX == oldX + 1)
			{
				if (board[oldY - 2][oldX + 1] <= 0)
				{
					return true;
				}
			}
		}
		// move knight up left
		if ((board[oldY - 1][oldX] >= 0 && board[oldY - 2][oldX] >= 0)
			|| (board[oldY - 1][oldX] <= 0 && board[oldY - 2][oldX] <= 0))
		{
			if (newY == oldY - 2 && newX == oldX - 1)
			{
				if (board[oldY - 2][oldX - 1] <= 0)
				{
					return true;
				}
			}
		}
		// move knight right up
		if ((board[oldY][oldX + 1] >= 0 && board[oldY][oldX + 2] >= 0)
			|| (board[oldY][oldX + 1] <= 0 && board[oldY][oldX + 2] <= 0))
		{
			if (newY == oldY - 1 && newX == oldX + 2)
			{
				if (board[oldY - 1][oldX + 2] <= 0)
				{
					return true;
				}
			}
		}
		// move knight right down
		if ((board[oldY][oldX + 1] >= 0 && board[oldY][oldX + 2] >= 0)
			|| (board[oldY][oldX + 1] <= 0 && board[oldY][oldX + 2] <= 0))
		{
			if (newY == oldY + 1 && newX == oldX + 2)
			{
				if (board[oldY + 1][oldX + 2] <= 0)
				{
					return true;
				}
			}
		}
		// move knight left up
		if ((board[oldY][oldX - 1] >= 0 && board[oldY][oldX - 2] >= 0)
			|| (board[oldY][oldX - 1] <= 0 && board[oldY][oldX - 2] <= 0))
		{
			if (newY == oldY - 1 && newX == oldX - 2)
			{
				if (board[oldY - 1][oldX - 2] <= 0)
				{
					return true;
				}
			}
		}
		// move knight left down
		if ((board[oldY][oldX - 1] >= 0 && board[oldY][oldX - 2] >= 0)
			|| (board[oldY][oldX - 1] <= 0 && board[oldY][oldX - 2] <= 0))
		{
			if (newY == oldY + 1 && newX == oldX - 2)
			{
				if (board[oldY + 1][oldX - 2] <= 0)
				{
					return true;
				}
			}
		}
	}



	if (color == BLACK_KNIGHT)
	{
		// move knight down right
		if ((board[oldY + 1][oldX] >= 0 && board[oldY + 2][oldX] >= 0)
			|| (board[oldY + 1][oldX] <= 0 && board[oldY + 2][oldX] <= 0))
		{
			if (newY == oldY + 2 && newX == oldX + 1)
			{
				if (board[oldY + 2][oldX + 1] >= 0)
				{
					return true;
				}
			}
		}
		// move knight down left
		if ((board[oldY + 1][oldX] >= 0 && board[oldY + 2][oldX] >= 0)
			|| (board[oldY + 1][oldX] <= 0 && board[oldY + 2][oldX] <= 0))
		{
			if (newY == oldY + 2 && newX == oldX - 1)
			{
				if (board[oldY + 2][oldX - 1] >= 0)
				{
					return true;
				}
			}

		}
		// move knight up right
		if ((board[oldY - 1][oldX] >= 0 && board[oldY - 2][oldX] >= 0)
			|| (board[oldY - 1][oldX] <= 0 && board[oldY - 2][oldX] <= 0))
		{
			if (newY == oldY - 2 && newX == oldX + 1)
			{
				if (board[oldY - 2][oldX + 1] >= 0)
				{
					return true;
				}
			}
		}
		// move knight up left
		if ((board[oldY - 1][oldX] >= 0 && board[oldY - 2][oldX] >= 0)
			|| (board[oldY - 1][oldX] <= 0 && board[oldY - 2][oldX] <= 0))
		{
			if (newY == oldY - 2 && newX == oldX - 1)
			{
				if (board[oldY - 2][oldX - 1] >= 0)
				{
					return true;
				}
			}
		}
		// move knight right up
		if ((board[oldY][oldX + 1] >= 0 && board[oldY][oldX + 2] >= 0)
			|| (board[oldY][oldX + 1] <= 0 && board[oldY][oldX + 2] <= 0))
		{
			if (newY == oldY - 1 && newX == oldX + 2)
			{
				if (board[oldY - 1][oldX + 2] >= 0)
				{
					return true;
				}
			}
		}
		// move knight right down
		if ((board[oldY][oldX + 1] >= 0 && board[oldY][oldX + 2] >= 0)
			|| (board[oldY][oldX + 1] <= 0 && board[oldY][oldX + 2] <= 0))
		{
			if (newY == oldY + 1 && newX == oldX + 2)
			{
				if (board[oldY + 1][oldX + 2] >= 0)
				{
					return true;
				}
			}
		}
		// move knight left up
		if ((board[oldY][oldX - 1] >= 0 && board[oldY][oldX - 2] >= 0)
			|| (board[oldY][oldX - 1] <= 0 && board[oldY][oldX - 2] <= 0))
		{
			if (newY == oldY - 1 && newX == oldX - 2)
			{
				if (board[oldY - 1][oldX - 2] >= 0)
				{
					return true;
				}
			}
		}
		// move knight left down
		if ((board[oldY][oldX - 1] >= 0 && board[oldY][oldX - 2] >= 0)
			|| (board[oldY][oldX - 1] <= 0 && board[oldY][oldX - 2] <= 0))
		{
			if (newY == oldY + 1 && newX == oldX - 2)
			{
				if (board[oldY + 1][oldX - 2] >= 0)
				{
					return true;
				}
			}
		}
	}

	return false;
}