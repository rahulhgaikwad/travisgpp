#ifndef _CONNECTX_H_
#define _CONNECTX_H_
#include <vector>

#define DEFAULT_WIDTH 7
#define DEFAULT_HEIGHT 6
#define DEFAULT_TO_WIN 4
typedef int Piece;

class ConnectX
{
private:
	int width;
	int height;
	Piece turn;
	int toWin;
	std::vector< std::vector<int> > board;
	void toggleTurn();
	bool inBounds(int,int);
	
public:
	static const Piece INVALID = -1;
	static const Piece EMPTY = 0;
	static const Piece WHITE = 1;
	static const Piece BLACK = 2;
	ConnectX(int,int,int);
	ConnectX() : ConnectX(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_TO_WIN) {}
	Piece at(int,int);
	void showBoard();
	Piece whoseTurn();
	void placePiece(int);
};

#endif //end of class definition _CONNECTX_H