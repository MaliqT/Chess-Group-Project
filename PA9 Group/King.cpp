#include "King.h"

King::King()
		{
if (!whiteKing.loadFromFile("images/WKing.png")) {
		cout << "Error Loading king txture" << endl;
	}
	else {
		cout << "Successfully Loaded king texture" << endl;
	}
	blackKing.loadFromFile("images/BKing.png");
}

Sprite King::getWhiteKingPiece() const
{
	Sprite king(whiteKing);
	king.setScale(1.65f, 1.5f);
	return king;
}

Sprite King::getBlackKingPiece() const
{
	Sprite king(blackKing);
	king.setScale(1.65f, 1.5f);
	return king;
}

bool King::moveCheck(int oldX, int oldY, int newX, int newY, int board[8][8], int color)
{
	if (color == WHITE_KING)
	{
		// move king one space left
		if (board[oldY][oldX - 1] <= 0 && (newY == oldY && newX == oldX - 1))
		{
			return true;
		}
		// move king one space right
		else if (board[oldY][oldX + 1] <= 0 && (newY == oldY && newX == oldX + 1))
		{
			return true;
		}
		// move king one space down
		else if (board[oldY + 1][oldX] <= 0 && (newY == oldY + 1 && newX == oldX))
		{
			return true;
		}
		// move king one space up
		else if (board[oldY - 1][oldX] <= 0 && (newY == oldY - 1 && newX == oldX))
		{
			return true;
		}
		// move king one space top left
		if (board[oldY - 1][oldX - 1] <= 0 && (newY == oldY - 1 && newX == oldX - 1))
		{
			return true;
		}
		// move king one space top right
		if (board[oldY - 1][oldX + 1] <= 0 && (newY == oldY - 1 && newX == oldX + 1))
		{
			return true;
		}
		// move king one space bottom right
		if (board[oldY + 1][oldX + 1] <= 0 && (newY == oldY + 1 && newX == oldX + 1))
		{
			return true;
		}
		// move king one space bottom left
		if (board[oldY + 1][oldX - 1] <= 0 && (newY == oldY + 1 && newX == oldX - 1))
		{
			return true;
		}
	}
	if (color == BLACK_KING)
	{
		// move king one space left
		if (board[oldY][oldX - 1] >= 0 && (newY == oldY && newX == oldX - 1))
		{
			return true;
		}
		// move king one space right
		else if (board[oldY][oldX + 1] >= 0 && (newY == oldY && newX == oldX + 1))
		{
			return true;
		}
		// move king one space down
		else if (board[oldY + 1][oldX] >= 0 && (newY == oldY + 1 && newX == oldX))
		{
			return true;
		}
		// move king one space up
		else if (board[oldY - 1][oldX] >= 0 && (newY == oldY - 1 && newX == oldX))
		{
			return true;
		}
		// move king one space top left
		if (board[oldY - 1][oldX - 1] >= 0 && (newY == oldY - 1 && newX == oldX - 1))
		{
			return true;
		}
		// move king one space top right
		if (board[oldY - 1][oldX + 1] >= 0 && (newY == oldY - 1 && newX == oldX + 1))
		{
			return true;
		}
		// move king one space bottom right
		if (board[oldY + 1][oldX + 1] >= 0 && (newY == oldY + 1 && newX == oldX + 1))
		{
			return true;
		}
		// move king one space bottom left
		if (board[oldY + 1][oldX - 1] >= 0 && (newY == oldY + 1 && newX == oldX - 1))
		{
			return true;
		}
	}
	return false;
}