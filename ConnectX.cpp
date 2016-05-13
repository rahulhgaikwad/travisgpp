#include "ConnectX.h"
#include <iostream>

// constructor provides customized dimensions and number of
// sequential pieces (x) it takes to win the game
ConnectX::ConnectX(int wide, int high, int x)
{   
	//invalid input resets everything to default settings
	if( wide <= 0 || high <= 0 || x <= 0)
	{
		wide=DEFAULT_WIDTH;
		high=DEFAULT_HEIGHT;
		x=DEFAULT_TO_WIN;
	}

	board.resize(high);
	for(int i=0; i<high; i++)
	{
		board[i].resize(wide);
		for(int j=0; j<wide; j++)
		{
			board[i][j] = EMPTY;
		}
	}	
	width = wide;
	height = high;
	toWin = x;
	turn = BLACK;
}

// changes turn to reflect whose turn it is
void ConnectX::toggleTurn()
{
	if(turn == WHITE)
	{
		turn = BLACK;
	}
	else
		turn = WHITE;
}

// returns whether or not the provided location is a valid
// space in the board
bool ConnectX::inBounds(int w, int h)
{
	bool inside;
	if( w>=width || w<0 )
		inside = false;
	else
		inside = true;

	if( h<0 || h>=height )
		inside = false;
	else
		inside = true;

	return inside;
}

// Prints out the board to the command line, showing both
// empty places and where each player has placed pieces
void ConnectX::showBoard()
{
	std::cout<<"   ";
	for(int w = 0; w < width; w++)
	{
		std::cout<<"["<<w<<"]";
	}
	std::cout<<std::endl;
	for(int h = 0; h < height; h++)
	{
		std::cout<<"["<<h<<"]";
		for(int w = 0; w < width; w++)
		{
			char place;
			Piece val = at(w,h);
			if(val == BLACK)
				place = 'B';
			else if( val == WHITE )
				place = 'W';
			else
				place = ' ';
			std::cout<<"["<<place<<"]";
		}
		std::cout<<std::endl;
	}
}

// Returns whose turn it is (BLACK or WHITE)
Piece ConnectX::whoseTurn()
{
	return turn;
}

// Retrieves the value at a provided (w,h) location in the board or returns
// INVALID if the provided location is not within the board
Piece ConnectX::at(int w, int h)
{
	if( inBounds(w,h) )
	{
		return board[h][w];
	}
	else
		return INVALID;
}

// Puts the current player's piece in a vertical column, where the piece falls
// to the lowest empty position available in the board. Placing a piece in a 
// "bad" column (such as a column that doesn't exist or is already full of 
// pieces) results in the player just losing their turn
void ConnectX::placePiece(int column)
{
	for(int i=height-1; i>=0; i--)
	{
		if( at(column,i) == EMPTY && inBounds(column,i) )
		{
			board[i][column] = turn;
			break;
		}
	}

	toggleTurn();
}
