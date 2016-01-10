//**************--------------------------- Board()- START ---------------------------***************
//Purpose: All functions and variables for Board class.

#ifndef __myMatches__Board__
#define __myMatches__Board__

#include <iostream>
#include "window.h"
#include "square.h"
#include "intboard.h"
#include "textboard.h"
#include "level.h"

class Board {
	// Basic data types
	int len;
	
	// Functions
    void addLocks();
	void graphicLocks();
	
public:
	// Non-basic data types
    Square mySquares[10][10];
    IntBoard intBoard;
    TextBoard* myTextBoard;
    Level *curLevel;
    Xwindow *myGraphic;
	static Board *instance;
	static Board* getInstance();
	
	// Basic data types
	int numCurLevel;
	bool onlyText;
	
	// Functions
	static void cleanup();
	void graphicSetter();
    void initialRandomSquare();
    void initializer();
	void scramble();
    void moveDown();
    void userOutput();
	void freeLocks();
    void notify();
    void randomSquare();
    void update();
	void transform(std::string direction);
	void boardFromFile(std::string fileName);
	void lockFromFile(std::string fileName);
	void squareInit(int r, int c, std::string initValue);
	int hint(int silent = false);
    int swap(int, int, int);
    int checker(int x, int y);
	bool lockChecker();
	bool squareGen();
    bool readNewSquares();
	
	// Friend Function
    friend std::ostream& operator<<(std::ostream& out, const Board& b);
	
	// Constructor
	Board();
};
#endif
//**************---------------------------- Board()- END ----------------------------***************
