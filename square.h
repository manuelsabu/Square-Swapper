//**************-------------------------- square.h- START ---------------------------***************
//Purpose: All functions and variables for each Square of the game Board.

#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <iostream>

class Square{
	// Basic data types
	char colour;
	char type;
	char extra;
	
public:
	// Functions
	char getColour() const;
	char getType() const;
	char getExtra() const;
	void setColour(char colour);
	void setType(char type);
	void setExtra(char extra);
	
	// Constructors
	Square();
	Square(char colour, char type, char extra = '_');
};
#endif
//**************--------------------------- square.h- END ----------------------------***************