#include "includes.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pieces.h"

/*
*	Assignment: PA 9
*	Due: 12/10/2021
*
*	Description: Our group decided to code a game of chess. Currently what is working in our game is displaying the board and the pieces in
*				 their corresponding places on the board. The board is made up as a 2-dimensional array to determine the coordinates of each piece.
*				 We use the position of the mouse on the window and when left mouse button is pressed, the program determine which piece is being
*				 moved along the board. 
*
*				*What is currently working with our game are the mechanics of the pieces. The Pawns can move either 1 or 2
*				 spaces on their first turn and only 1 space after that. The Rooks can move however many spaces vertically and horizontally unless
*				 there is a piece obstructing its path. The Knight can move in a L-shape along the board and is able to move over pieces and can
*				 take the piece it lands on. The Bishop is able to move diagonally in any direction as long as nothing obstructs its path. The Queen
*				 uses the same mechanics from the Rook and the Bishop and can move either horizontally or diagonally for any amount of spaces as long
*				 as nothing obstructs its path. And finally the King can move only one space in any direction.
*
*				*What is currently not working in our game is castling the King and the Rook. We wanted to implement this feature but could not get to
*				 it in time. We also didn't implement a check King function so to kill the King you just... kill him and no win screen or menu screen.
*/

int size = 100;

std::string MoveNote(Vector2f p)
{
	std::string s = "";
	s += char(p.x/size+97); // what file (Column)
	s += char(p.y/size+49); // what rank (row)
	return s;
}


int main ()
{
	int noMovedPiece = 0, isMoving = 0, transformationWhite = 0, transformationBlack = 0, rules_open = 1;

	float dx = 0, dy = 0;
	Vector2f oldPos, newPos;
	std::string moveNote;

	int chessBoard[8][8] =
	 // x-coords
	{//  0, 1, 2, 3, 4, 5, 6, 7  
		 2, 3, 4, 6, 5, 4, 3, 2, // 0 // y-coords
		 1, 1, 1, 1, 1, 1, 1, 1, // 1
		 0, 0, 0, 0, 0, 0, 0, 0, // 2
		 0, 0, 0, 0, 0, 0, 0, 0, // 3
	 	 0, 0, 0, 0, 0, 0, 0, 0, // 4
	 	 0, 0, 0, 0, 0, 0, 0, 0, // 5
		-1,-1,-1,-1,-1,-1,-1,-1, // 6
		-2,-3,-4,-6,-5,-4,-3,-2, // 7
	};

	RenderWindow Window(VideoMode(800, 800), "Chess");
	Texture tBoard, tWhite, tBlack,tRules;
	Pieces oldPoz, newPoz, whiteKing, blackKing, transformWhite, transformBlack;

	if(!tRules.loadFromFile("images/ruledisplay.jpg"))
	{
		cout<<"error w/ rule display"<<endl;
	}
	else
	{
		cout << "load rules successfull" << endl;
	}

	if (!tBoard.loadFromFile("images/Board.jpg")) //This checks If the texture loaded correctly
	{
		cout << "Error Loading Board Texture" << endl;
	}
	else 
	{
		cout << "Board texture loaded correctly" << endl;
	}
	tWhite.loadFromFile("images/TransformationWhite.png");
	tBlack.loadFromFile("images/TransformationBlack.png");
	Sprite Board(tBoard);
	Sprite Rules(tRules);
	Sprite whiteTransformation(tWhite);
	Sprite blackTransformation(tBlack);
	Sprite movePieces;
	Board.setScale(1.57f, 1.57f);

	Pawn pawnBlack, pawnWhite;
	Rook rookBlack, rookWhite;
	Knight knightBlack, knightWhite;
	Bishop bishopBlack, bishopWhite;
	Queen queenBlack, queenWhite;
	King kingBlack, kingWhite;

	int checkPiece = 0;//this variable checks of we want to allow a piece to be placed in a new position after it was picked up
	int move = 0, move_counter = 0;


	while (Window.isOpen())
	{
		Vector2i mousePos = Mouse::getPosition(Window); // Get Mouse Position
		int x = mousePos.x / size, y = mousePos.y / size;

		Event evnt;
		while (Window.pollEvent(evnt))		// This line here allows you to interact with the window
		{
			if (evnt.type == Event::Closed) // close window
			{
				Window.close();
			}
			Window.clear();

			//if (rules_open == 1)
			//{
			//	Window.draw(Rules);
			//	getch(); // Wait until get any character from user
			//	rules_open = 0;
			//	Window.clear();
			//}

			if (evnt.type == Event::MouseButtonPressed)
			{
				if (evnt.key.code == Mouse::Left)
				{										// Pick up chess piece

					if (chessBoard[y][x] != 0)
					{
						dx = mousePos.x - movePieces.getPosition().x;
						dy = mousePos.y - movePieces.getPosition().y;

						if (chessBoard[y][x] == BLACK_PAWN && move == 1)
						{
							noMovedPiece = BLACK_PAWN;
							movePieces = pawnBlack.getBlackPawnPiece();
							chessBoard[y][x] = 0;
							move = 0;
							checkPiece = 1;
							oldPos.x = mousePos.x;
							oldPos.y = mousePos.y;
						}
						if (chessBoard[y][x] == WHITE_PAWN && move == 0)
						{
							noMovedPiece = WHITE_PAWN;
							movePieces = pawnWhite.getWhitePawnPiece();
							chessBoard[y][x] = 0;
							move = 1;
							checkPiece = 1;
							oldPos.x = mousePos.x;
							oldPos.y = mousePos.y;
						}
						if (chessBoard[y][x] == BLACK_ROOK && move == 1)
						{
							noMovedPiece = BLACK_ROOK;
							movePieces = rookBlack.getBlackRookPiece();
							chessBoard[y][x] = 0;
							move = 0;
							checkPiece = 1;
							oldPos.x = mousePos.x;
							oldPos.y = mousePos.y;
						}
						if (chessBoard[y][x] == WHITE_ROOK && move == 0)
						{
							noMovedPiece = WHITE_ROOK;
							movePieces = rookWhite.getWhiteRookPiece();
							chessBoard[y][x] = 0;
							move = 1;
							checkPiece = 1;
							oldPos.x = mousePos.x;
							oldPos.y = mousePos.y;
						}
						if (chessBoard[y][x] == BLACK_KNIGHT && move == 1)
						{
							noMovedPiece = BLACK_KNIGHT;
							movePieces = knightBlack.getBlackKnightPiece();
							chessBoard[y][x] = 0;
							move = 0;
							checkPiece = 1;
							oldPos.x = mousePos.x;
							oldPos.y = mousePos.y;
						}
						if (chessBoard[y][x] == WHITE_KNIGHT && move == 0)
						{
							noMovedPiece = WHITE_KNIGHT;
							movePieces = knightWhite.getWhiteKnightPiece();
							chessBoard[y][x] = 0;
							move = 1;
							checkPiece = 1;
							oldPos.x = mousePos.x;
							oldPos.y = mousePos.y;
						}
						if (chessBoard[y][x] == BLACK_BISHOP && move == 1)
						{
							noMovedPiece = BLACK_BISHOP;
							movePieces = bishopBlack.getBlackBishopPiece();
							chessBoard[y][x] = 0;
							move = 0;
							checkPiece = 1;
							oldPos.x = mousePos.x;
							oldPos.y = mousePos.y;
						}
						if (chessBoard[y][x] == WHITE_BISHOP && move == 0)
						{
							noMovedPiece = WHITE_BISHOP;
							movePieces = bishopWhite.getWhiteBishopPiece();
							chessBoard[y][x] = 0;
							move = 1;
							checkPiece = 1;
							oldPos.x = mousePos.x;
							oldPos.y = mousePos.y;
						}
						if (chessBoard[y][x] == BLACK_QUEEN && move == 1)
						{
							noMovedPiece = BLACK_QUEEN;
							movePieces = queenBlack.getBlackQueenPiece();
							chessBoard[y][x] = 0;
							move = 0;
							checkPiece = 1;
							oldPos.x = mousePos.x;
							oldPos.y = mousePos.y;
						}
						if (chessBoard[y][x] == WHITE_QUEEN && move == 0)
						{
							noMovedPiece = WHITE_QUEEN;
							movePieces = queenWhite.getWhiteQueenPiece();
							chessBoard[y][x] = 0;
							move = 1;
							checkPiece = 1;
							oldPos.x = mousePos.x;
							oldPos.y = mousePos.y;
						}
						if (chessBoard[y][x] == BLACK_KING && move == 1)
						{
							noMovedPiece = BLACK_KING;
							movePieces = kingBlack.getBlackKingPiece();
							chessBoard[y][x] = 0;
							move = 0;
							checkPiece = 1;
							oldPos.x = mousePos.x;
							oldPos.y = mousePos.y;
						}
						if (chessBoard[y][x] == WHITE_KING && move == 0)
						{
							noMovedPiece = WHITE_KING;
							movePieces = kingWhite.getWhiteKingPiece();
							chessBoard[y][x] = 0;
							move = 1;
							checkPiece = 1;
							oldPos.x = mousePos.x;
							oldPos.y = mousePos.y;
						}
						if (chessBoard[y][x] == PROMOTION_BLACK)//PROMOTION BLACK ATTEMPT
						{
							int co_x = x * size;
							int co_y = y * size;
							cout << co_x;

							if (mousePos.x <= co_x + 50 && mousePos.y < co_y + 50) {
								chessBoard[y][x] = BLACK_ROOK;
							}
							else if (mousePos.x >= co_x + 50 && mousePos.y <= co_y + 50) {
								chessBoard[y][x] = BLACK_QUEEN;
							}
							else if (mousePos.x <= co_x + 50 && mousePos.y >= co_y + 50) {
								chessBoard[y][x] = BLACK_BISHOP;
							}
							else if (mousePos.x >= co_x + 50 && mousePos.y >= co_y + 50) {
								chessBoard[y][x] = BLACK_KNIGHT;
							}


						}//END OF PROMOTION

						if (chessBoard[y][x] == PROMOTION_WHITE)//PROMOTION WHITE ATTEMPT
						{
							int co_x = x * size;
							int co_y = y * size;
							cout << co_x;

							if (mousePos.x <= co_x + 50 && mousePos.y < co_y + 50) {
								chessBoard[y][x] = WHITE_ROOK;
							}
							else if (mousePos.x >= co_x + 50 && mousePos.y <= co_y + 50) {
								chessBoard[y][x] = WHITE_QUEEN;
							}
							else if (mousePos.x <= co_x + 50 && mousePos.y >= co_y + 50) {
								chessBoard[y][x] = WHITE_BISHOP;
							}
							else if (mousePos.x >= co_x + 50 && mousePos.y >= co_y + 50) {
								chessBoard[y][x] = WHITE_KNIGHT;
							}


						}//END OF PROMOTION
						if (chessBoard[y][x] == 0)
						{
							isMoving = 1;
							oldPoz.setPosX(x);
							oldPoz.setPosY(y);
							move_counter++;
						}
					}
				}
			}

			if (evnt.type == Event::MouseButtonReleased)
			{
				if (evnt.key.code == Mouse::Left)
				{
					//  No longer Moving
					int ok;
					bool isValid = false;

					if (noMovedPiece == WHITE_PAWN && isMoving == 1)
					{
						isValid = pawnWhite.moveCheck(oldPoz.getX(), oldPoz.getY(), x, y, chessBoard, WHITE_PAWN);

						if (isValid == false)
						{
							chessBoard[oldPoz.getY()][oldPoz.getX()] = WHITE_PAWN;
							checkPiece = 0;
							move = 0;
							move_counter--;
						}
					}
					if (noMovedPiece == BLACK_PAWN && isMoving == 1)
					{
						isValid = pawnBlack.moveCheck(oldPoz.getX(), oldPoz.getY(), x, y, chessBoard, BLACK_PAWN);

						if (isValid == false)
						{
							chessBoard[oldPoz.getY()][oldPoz.getX()] = BLACK_PAWN;
							checkPiece = 0;
							move = 1;
							move_counter--;
						}
					}
					if (noMovedPiece == WHITE_ROOK && isMoving == 1)
					{
						isValid = rookWhite.moveCheck(oldPoz.getX(), oldPoz.getY(), x, y, chessBoard, WHITE_ROOK);

						if (isValid == false)
						{
							chessBoard[oldPoz.getY()][oldPoz.getX()] = WHITE_ROOK;
							checkPiece = 0;
							move = 0;
							move_counter--;
						}
					}
					if (noMovedPiece == BLACK_ROOK && isMoving == 1)
					{
						isValid = rookBlack.moveCheck(oldPoz.getX(), oldPoz.getY(), x, y, chessBoard, BLACK_ROOK);

						if (isValid == false)
						{
							chessBoard[oldPoz.getY()][oldPoz.getX()] = BLACK_ROOK;
							checkPiece = 0;
							move = 1;
							move_counter--;
						}
					}
					if (noMovedPiece == WHITE_BISHOP && isMoving == 1)
					{
						isValid = bishopWhite.moveCheck(oldPoz.getX(), oldPoz.getY(), x, y, chessBoard, WHITE_BISHOP);

						if (isValid == false)
						{
							chessBoard[oldPoz.getY()][oldPoz.getX()] = WHITE_BISHOP;
							checkPiece = 0;
							move = 0;
							move_counter--;
						}
					}
					if (noMovedPiece == BLACK_BISHOP && isMoving == 1)
					{
						isValid = bishopBlack.moveCheck(oldPoz.getX(), oldPoz.getY(), x, y, chessBoard, BLACK_BISHOP);

						if (isValid == false)
						{
							chessBoard[oldPoz.getY()][oldPoz.getX()] = BLACK_BISHOP;
							checkPiece = 0;
							move = 1;
							move_counter--;
						}
					}
					if (noMovedPiece == WHITE_KNIGHT && isMoving == 1)
					{
						isValid = knightWhite.moveCheck(oldPoz.getX(), oldPoz.getY(), x, y, chessBoard, WHITE_KNIGHT);

						if (isValid == false)
						{
							chessBoard[oldPoz.getY()][oldPoz.getX()] = WHITE_KNIGHT;
							checkPiece = 0;
							move = 0;
							move_counter--;
						}
					}
					if (noMovedPiece == BLACK_KNIGHT && isMoving == 1)
					{
						isValid = knightBlack.moveCheck(oldPoz.getX(), oldPoz.getY(), x, y, chessBoard, BLACK_KNIGHT);

						if (isValid == false)
						{
							chessBoard[oldPoz.getY()][oldPoz.getX()] = BLACK_KNIGHT;
							checkPiece = 0;
							move = 1;
							move_counter--;
						}
					}
					if (noMovedPiece == WHITE_KING && isMoving == 1)
					{
						isValid = kingWhite.moveCheck(oldPoz.getX(), oldPoz.getY(), x, y, chessBoard, WHITE_KING);

						if (isValid == false)
						{
							chessBoard[oldPoz.getY()][oldPoz.getX()] = WHITE_KING;
							checkPiece = 0;
							move = 0;
							move_counter--;
						}
					}
					if (noMovedPiece == BLACK_KING && isMoving == 1)
					{
						isValid = kingBlack.moveCheck(oldPoz.getX(), oldPoz.getY(), x, y, chessBoard, BLACK_KING);

						if (isValid == false)
						{
							chessBoard[oldPoz.getY()][oldPoz.getX()] = BLACK_KING;
							checkPiece = 0;
							move = 1;
							move_counter--;
						}
					}
					if (noMovedPiece == WHITE_QUEEN && isMoving == 1)
					{
						isValid = queenWhite.moveCheck(oldPoz.getX(), oldPoz.getY(), x, y, chessBoard, WHITE_QUEEN);

						if (isValid == false)
						{
							chessBoard[oldPoz.getY()][oldPoz.getX()] = WHITE_QUEEN;
							checkPiece = 0;
							move = 0;
							move_counter--;
						}
					}
					if (noMovedPiece == BLACK_QUEEN && isMoving == 1)
					{
						isValid = queenBlack.moveCheck(oldPoz.getX(), oldPoz.getY(), x, y, chessBoard, BLACK_QUEEN);

						if (isValid == false)
						{
							chessBoard[oldPoz.getY()][oldPoz.getX()] = BLACK_QUEEN;
							checkPiece = 0;
							move = 1;
							move_counter--;
						}
					}

					if (checkPiece == 1)
					{
						chessBoard[y][x] = noMovedPiece; // Set current place the mouse is in the array to the piece that was moved

						checkPiece = 0;
						moveNote = MoveNote(Vector2f(oldPos.x, oldPos.y)) + MoveNote(Vector2f(mousePos.x, mousePos.y));

						cout << "Move:" << moveNote << " Moves taken " << move_counter << endl;
					}


					//chessBoard[y][x] = noMovedPiece; // Set current place the mouse is to the piece that was moved
					//noMovedPiece = 0;

					isMoving = 0;
				}
			}
		}

		Window.clear();
		Window.draw(Board);

		if (transformationWhite == 1)
		{
			whiteTransformation.setPosition(transformWhite.getX() * size, transformWhite.getY() * size);
			Window.draw(whiteTransformation);
		}
		if (transformationBlack == 1)
		{
			blackTransformation.setPosition(transformBlack.getX() * size, transformBlack.getY() * size);
			Window.draw(blackTransformation);
		}
		if (isMoving == 1)
		{
			movePieces.setPosition(mousePos.x - 50, mousePos.y - 50);
			Window.draw(movePieces);
		}
		//This draws all the pieces in their correct places
		for (int i = 0; i <= LENGTH; i++)
		{
			for (int j = 0; j <= LENGTH; j++)
			{
				if (chessBoard[i][j] != 0)
				{

					if (i == 0) //code that checks for promotion for black pieces
					{

						if (chessBoard[i][j] == BLACK_PAWN)
						{

							chessBoard[i][j] = PROMOTION_BLACK;

						}

					}

					if (i == 7) //code that checks for promotion for black pieces
					{

						if (chessBoard[i][j] == WHITE_PAWN)
						{

							chessBoard[i][j] = PROMOTION_WHITE;

						}

					}

					if (chessBoard[i][j] == PROMOTION_BLACK)
					{

						blackTransformation.setPosition(j * size, i * size);
						Window.draw(blackTransformation);

					}
					if (chessBoard[i][j] == PROMOTION_WHITE)
					{

						whiteTransformation.setPosition(j * size, i * size);
						Window.draw(whiteTransformation);

					}
					if (chessBoard[i][j] == BLACK_PAWN)
					{
						Sprite sBlackPawn = pawnBlack.getBlackPawnPiece();
						sBlackPawn.setPosition(j * size, i * size);
						Window.draw(sBlackPawn);
					}
					if (chessBoard[i][j] == WHITE_PAWN)
					{
						Sprite sWhitePawn = pawnWhite.getWhitePawnPiece();
						sWhitePawn.setPosition(j * size, i * size);
						Window.draw(sWhitePawn);
					}
					if (chessBoard[i][j] == BLACK_ROOK)
					{
						Sprite sBlackRook = rookBlack.getBlackRookPiece();
						sBlackRook.setPosition(j * size, i * size);
						Window.draw(sBlackRook);
					}
					if (chessBoard[i][j] == WHITE_ROOK)
					{
						Sprite sWhiteRook = rookWhite.getWhiteRookPiece();
						sWhiteRook.setPosition(j * size, i * size);
						Window.draw(sWhiteRook);
					}
					if (chessBoard[i][j] == BLACK_KNIGHT)
					{
						Sprite sBlackKnight = knightBlack.getBlackKnightPiece();
						sBlackKnight.setPosition(j * size, i * size);
						Window.draw(sBlackKnight);
					}
					if (chessBoard[i][j] == WHITE_KNIGHT)
					{
						Sprite sWhiteKnight = knightWhite.getWhiteKnightPiece();
						sWhiteKnight.setPosition(j * size, i * size);
						Window.draw(sWhiteKnight);
					}
					if (chessBoard[i][j] == BLACK_BISHOP)
					{
						Sprite sBlackBishop = bishopBlack.getBlackBishopPiece();
						sBlackBishop.setPosition(j * size, i * size);
						Window.draw(sBlackBishop);
					}
					if (chessBoard[i][j] == WHITE_BISHOP)
					{
						Sprite sWhiteBishop = bishopWhite.getWhiteBishopPiece();
						sWhiteBishop.setPosition(j * size, i * size);
						Window.draw(sWhiteBishop);
					}
					if (chessBoard[i][j] == BLACK_QUEEN)
					{
						Sprite sBlackQueen = queenBlack.getBlackQueenPiece();
						sBlackQueen.setPosition(j * size, i * size);
						Window.draw(sBlackQueen);
					}
					if (chessBoard[i][j] == WHITE_QUEEN)
					{
						Sprite sWhiteQueen = queenWhite.getWhiteQueenPiece();
						sWhiteQueen.setPosition(j * size, i * size);
						Window.draw(sWhiteQueen);
					}
					if (chessBoard[i][j] == BLACK_KING)
					{
						Sprite sBlackKing = kingBlack.getBlackKingPiece();
						sBlackKing.setPosition(j * size, i * size);
						Window.draw(sBlackKing);
					}
					if (chessBoard[i][j] == WHITE_KING)
					{
						Sprite sWhiteKing = kingWhite.getWhiteKingPiece();
						sWhiteKing.setPosition(j * size, i * size);
						Window.draw(sWhiteKing);
					}
				}
			}
		}

		Window.display();
	}
		return 0;
}