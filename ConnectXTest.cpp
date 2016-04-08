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

TEST(ConnectXTest, checkSizesInitial)
{
  // default sizes
  ConnectX cx;
  ASSERT_TRUE(cx.at(DEFAULT_WIDTH - 1, DEFAULT_HEIGHT - 1) == ConnectX::EMPTY);
  ASSERT_TRUE(cx.at(DEFAULT_WIDTH, DEFAULT_HEIGHT) == ConnectX::INVALID);
  ASSERT_TRUE(cx.whoseTurn() == ConnectX::BLACK);

  for(int w = 0; w < DEFAULT_WIDTH; ++w)
    for(int h = 0; h < DEFAULT_HEIGHT; ++h)
      ASSERT_TRUE(cx.at(w, h) == ConnectX::EMPTY);

  ConnectX cx_small(DEFAULT_WIDTH - 2, DEFAULT_HEIGHT - 2, 2);
  ASSERT_TRUE(cx_small.whoseTurn() == ConnectX::BLACK);
}

TEST(ConnectXTest, boundsTest)
{
  ConnectX cx;
  ASSERT_TRUE(cx.at(DEFAULT_WIDTH - 1, DEFAULT_HEIGHT - 1) == ConnectX::EMPTY);
  ASSERT_TRUE(cx.at(DEFAULT_WIDTH, DEFAULT_HEIGHT - 1) == ConnectX::INVALID);
  ASSERT_TRUE(cx.at(DEFAULT_WIDTH - 1, DEFAULT_HEIGHT) == ConnectX::INVALID);
  ASSERT_TRUE(cx.at(-1, -1) == ConnectX::INVALID);
  ASSERT_TRUE(cx.at(-1, 0) == ConnectX::INVALID);
  ASSERT_TRUE(cx.at(0, -1) == ConnectX::INVALID);
}

TEST(ConnectXTest, showTest)
{
  ConnectX cx;
  cx.showBoard();
}

TEST(ConnectXTest, fillAll) {
  const int w = 10;
  const int h = 3;
  ConnectX cx(w, h, 4);
  Piece p = cx.whoseTurn();
  ASSERT_TRUE(p == ConnectX::BLACK);
  for(int i = 0; i < w; ++i) {
    for(int j = 0; j < h; ++j) {
      if (p == ConnectX::BLACK) p = ConnectX::WHITE; else p = ConnectX::BLACK;
      cx.placePiece(i);
      ASSERT_TRUE(p == cx.whoseTurn());
    }
  }

  cx.showBoard();

  for(int i = 0; i < w; ++i) {
    for(int j = 0; j < h; ++j) {
      ASSERT_TRUE(cx.at(i, j) != ConnectX::INVALID);
      ASSERT_TRUE(cx.at(i, j) != ConnectX::EMPTY);
    }
  }
}

TEST(ConnectXTest, pointTest)
{
  ConnectX cx(1,1,1);
  cx.placePiece(0);

  ASSERT_TRUE(cx.whoseTurn() == ConnectX::WHITE);
  cx.placePiece(0);
  ASSERT_TRUE(cx.whoseTurn() == ConnectX::BLACK);
  cx.placePiece(1);
  ASSERT_TRUE(cx.whoseTurn() == ConnectX::WHITE);
  ASSERT_TRUE(cx.at(0, 0) == ConnectX::BLACK);
  cx.showBoard();
}

TEST(ConnectXText, placeTest)
{
  // this test crashes since bug in inBounds function
  ConnectX cx;
  ASSERT_TRUE(cx.whoseTurn() == ConnectX::BLACK);
  cx.placePiece(0);
  ASSERT_TRUE(cx.whoseTurn() == ConnectX::WHITE);
  cx.placePiece(1);
  ASSERT_TRUE(cx.whoseTurn() == ConnectX::BLACK);
  //cx.placePiece(-1);
  //ASSERT_TRUE(cx.whoseTurn() == ConnectX::WHITE);
  //cx.placePiece(-1);
  //ASSERT_TRUE(cx.whoseTurn() == ConnectX::BLACK);
}
/*
Bugs: 	toWin = x; // we need to check toWin < height.
   
For Inbound fucntion 
simply check h/w separately
if( w>=width || w<0 ) return false;
if( h<0 || h>=height ) return false;
return true;

*/
