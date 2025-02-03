#pragma once
#include "includes.h"


class Pieces
{
public:

	// member functions
	// setters
	void setPosX(int x);
	void setPosY(int y);

	// getters
	int getX() const;
	int getY() const;

private:
	int xPos;
	int yPos;
};