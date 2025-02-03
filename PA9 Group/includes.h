#pragma once
#include <iostream>
#include <conio.h>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;
using std::cout;
using std::cin;
using std::endl;


#define BLACK_PAWN -1
#define WHITE_PAWN 1
#define BLACK_ROOK -2
#define WHITE_ROOK 2
#define BLACK_KNIGHT -3
#define WHITE_KNIGHT 3
#define BLACK_BISHOP -4
#define WHITE_BISHOP 4
#define BLACK_QUEEN -5
#define WHITE_QUEEN 5
#define BLACK_KING -6
#define WHITE_KING 6
#define LENGTH 7
#define PROMOTION_WHITE 8
#define PROMOTION_BLACK -8



/* TODO
	Check if valid move for each piece
		- Pawn rules
		- Knight Rules
		- Bishop Rules
		- Rook Rules
		- King Rules
		- Queen Rules
		- implement Castling the King
	Finish Promotion
	Finish rules/menu
	






*/
/*


						y-coords
						   |
						   |
						   |
0, 1, 2, 3, 4, 5, 6, 7 -------- x-coords
						   |
2, 3, 4, 5, 6, 4, 3, 2,   // 0
1, 1, 1, 1, 1, 1, 1, 1,   // 1
0, 0, 0, 0, 0, 0, 0, 0,   // 2
0, 0, 0, 0, 0, 0, 0, 0,   // 3
0, 0, 0, 0, 0, 0, 0, 0,   // 4
0, 0, 0, 0, 0, 0, 0, 0,   // 5
-1,-1,-1,-1,-1,-1,-1,-1,  // 6
-2,-3,-4,-5,-6,-4,-3,-2,  // 7

*/