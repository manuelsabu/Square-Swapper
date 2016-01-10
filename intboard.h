//**************------------------------- intBoard.h- START --------------------------***************
//Purpose: All functions and variables for Integer version of Board.

#ifndef __myMatches__intboard__
#define __myMatches__intboard__

#include <iostream>

class IntBoard {
	// Basic data type
	int score;
	
	// Functions
    int matchL();
    int matchL1();
    int matchL2();
    int matchL3();
    int matchL4();
    int matchT();
    int matchOther(int matchType, int firstTest);
    int matchOtherH(int matchType, int firstTest);
    int matchOtherV(int matchType, int firstTest);
	void clearCol(int c);
    void clearRow(int r);
    void colorExploder(int colour);
    void cave(int x, int y, int z);
    void clearSpecial();
    void initScoreBoard();
    void calcScore();
    void prepScoreBoard();
	
public:
	// Basic data type
    int chainFactor;
    int scoreSwitch;
	int scoreBoard[10][10];
	
	// Functions
    int getScore();
	int setScore();
    int table[10][10];
    int bigMatch();
	
	// Friend functions
    friend std::ostream& operator<<(std::ostream&, const IntBoard& ib);
};
#endif
//**************-------------------------- intBoard.h- END ---------------------------***************