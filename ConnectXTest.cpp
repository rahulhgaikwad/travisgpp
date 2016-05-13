/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
 
class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(ConnectXTest, checkBlackTurn)
{
	ConnectX obj;
	obj.showBoard();
	ASSERT_EQ(obj.whoseTurn(),2);
}

TEST(ConnectXTest, checkWhiteTurn)
{
	ConnectX obj;
	obj.showBoard();
	obj.placePiece(0);
	obj.showBoard();
	ASSERT_EQ(obj.whoseTurn(),1);
}

TEST(ConnectXTest, checkNotWhiteTurn)
{
	ConnectX obj;
	obj.showBoard();
	obj.placePiece(0);
	obj.showBoard();
	obj.placePiece(0);
	obj.showBoard();
	ASSERT_EQ(obj.whoseTurn(),2);
}

TEST(ConnectXTest, checkPlacePieceBelowZero)
{
	ConnectX obj;
	obj.placePiece(-1);
	obj.showBoard();
	ASSERT_EQ(obj.whoseTurn(),1);
}

TEST(ConnectXTest, checkPlacePieceAboveWidth)
{
	ConnectX obj(3,3,4);
	obj.placePiece(3);
	obj.placePiece(3);
	obj.placePiece(3);
	obj.placePiece(3);
	obj.showBoard();
	ASSERT_EQ(obj.whoseTurn(),2);
}

TEST(ConnectXTest, checkHeight)
{
	ConnectX obj;
	obj.showBoard();
	obj.showBoard();
	obj.placePiece(0);
	obj.showBoard();
	obj.placePiece(0);
	obj.showBoard();
	obj.placePiece(0);
	obj.showBoard();
	obj.placePiece(0);
	obj.showBoard();
	obj.placePiece(0);
	obj.showBoard();
	obj.placePiece(0);
	obj.showBoard();
	obj.placePiece(0);
	obj.showBoard();
	obj.placePiece(9);
	obj.placePiece(-5);
	obj.placePiece(0);
	obj.showBoard();
	ASSERT_EQ(obj.whoseTurn(),2);
}

TEST(ConnectXTest, checkConstructorAllParamsPositive)
{
	ConnectX obj(10,10,4);
	obj.showBoard();
	ASSERT_FALSE(obj.at(0,0));
}

TEST(ConnectXTest, checkConstructorWinNegative)
{
	ConnectX obj(10,10,-4);
	obj.showBoard();
	ASSERT_FALSE(obj.at(0,0));
}

TEST(ConnectXTest, checkConstructorHeightWinNegative)
{
	ConnectX obj(10,-10,-4);
	obj.showBoard();
	ASSERT_FALSE(obj.at(0,0));
}

TEST(ConnectXTest, checkConstructorAllParamsNegative)
{
	ConnectX obj(-10,-10,-20);
	obj.showBoard();
	ASSERT_FALSE(obj.at(0,0));
}

TEST(ConnectXTest, checkConstructorWidthHeightNegative)
{
	ConnectX obj(-10,-10,4);
	obj.showBoard();
	ASSERT_FALSE(obj.at(0,1));
}

TEST(ConnectXTest, checkConstructorWidthNegative)
{
	ConnectX obj(-10,10,4);
	obj.showBoard();
	ASSERT_FALSE(obj.at(0,0));
}

TEST(ConnectXTest, checkConstructorHeightNegative)
{
	ConnectX obj(10,-10,20);
	obj.showBoard();
	ASSERT_FALSE(obj.at(0,0));
}

TEST(ConnectXTest, checkConstructorWidthWinNegative)
{
	ConnectX obj(-10,10,-20);
	obj.showBoard();
	ASSERT_FALSE(obj.at(0,0));
}

TEST(ConnectXTest, checkConstructorWinOutBounds)
{
	ConnectX obj(-10,-10,20);
	obj.showBoard();
	ASSERT_FALSE(obj.at(0,0));
}

TEST(ConnectXTest, testNegativeWidthHeightInvalid)
{
	ConnectX obj;
	ASSERT_EQ(obj.at(-100,-1),-1);
}

//Below test cases are written to prove bug in inBounds() and 
//at() functions. Below test case fails because at() function
//returns different value than it suppose to return.
//It proves that there is bug in iBounds() due to which 
//at() function misbehaves.

TEST(ConnectXTest, testDefaultWidthOutBoundsFalse)
{
	ConnectX obj; //default width=7,height=6, win=4
	ASSERT_EQ(obj.at(10,1),-1);
}

TEST(ConnectXTest, testWidthOutBoundsFalse)
{
	ConnectX obj(10,10,4);
	ASSERT_EQ(obj.at(50,1),-1);
}

TEST(ConnectXTest, testWidthBelowBoundsFalse)
{
	ConnectX obj(10,10,4);
	ASSERT_EQ(obj.at(-1,1),-1);
}

//Below test cases are false positive. Eventhough below test did  
//pass, It should fail while asserting true. It proves that there
//is bug in iBounds() due to which at() function misbehaves.

TEST(ConnectXTest, checkAtAllBounds)
{
	ConnectX obj;
	bool n1,n2,n3,n4;
	n1 = obj.at(0,-1);
	n2 = obj.at(0,10);
	n3 = obj.at(20,30);
	n4 = obj.at(-3,40);
	ASSERT_TRUE(n1);
	ASSERT_TRUE(n2);
	ASSERT_TRUE(n3);
	ASSERT_TRUE(n4);
}

TEST(ConnectXTest, testWidthOutBoundsTrue)
{
	ConnectX obj(10,10,4);
	ASSERT_EQ(obj.at(50,1),0);
}