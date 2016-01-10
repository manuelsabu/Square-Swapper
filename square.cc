#include <iostream>
#include "square.h"

using namespace std;

//**************------------------------- setColour()- START -------------------------***************
//Purpose: Sets the "colour" field of the Square.
//Arguments: NIL
//Returns: NIL

void Square::setColour(char colour){
	// '_' -> void, '0' -> white, '1' -> red, '2' -> green, '3' -> blue
	if(colour == '_' || colour == '0' || colour == '1' || colour == '2' || colour == '3'){
		this->colour = colour;
	}
	
	else {
		cerr << "Colour not properly set!" << endl;
	}
}
//**************-------------------------- setColour()- END --------------------------***************

//**************-------------------------- setType()- START --------------------------***************
//Purpose: Sets the "type" field of the Square.
//Arguments: NIL
//Returns: NIL

void Square::setType(char type){
	// '_' -> void, 'h' -> lateral, 'v' -> upright, 'b' -> unstable, 'p' -> psychadelic
	if(type == '_' || type == 'h' || type == 'v' || type == 'b' || type == 'p'){
		this->type = type;
	}
	
	else {
		cerr << "Type not properly set!" << endl;
	}
}
//**************--------------------------- setType()- END ---------------------------***************

//**************------------------------- setExtra()- START --------------------------***************
//Purpose: Sets the "extra" field of the Square.
//Arguments: NIL
//Returns: NIL

void Square::setExtra(char extra){
	this->extra = extra;
}
//**************-------------------------- setExtra()- END ---------------------------***************

//**************------------------------- getColour()- START -------------------------***************
//Purpose: Gets the "colour" field of the Square.
//Arguments: NIL
//Returns: Char(colour)

char Square::getColour() const{
	return(this->colour);
}
//**************-------------------------- getColour()- END --------------------------***************

//**************-------------------------- getType()- START --------------------------***************
//Purpose: Gets the "type" field of the Square.
//Arguments: NIL
//Returns: Char(type)

char Square::getType() const{
	return(this->type);
}
//**************--------------------------- getType()- END ---------------------------***************

//**************------------------------- getExtra()- START --------------------------***************
//Purpose: Gets the "extra" field of the Square.
//Arguments: NIL
//Returns: Char(extra)

char Square::getExtra() const{
	return(this->extra);
}
//**************-------------------------- getExtra()- END ---------------------------***************

//**************-------------------------- Square()- START ---------------------------***************
//Purpose: Constructors for Square class
//Arguments: NIL/ Char(Colour, Type, and Extra)
//Returns: NIL

Square::Square(){
	this->colour = '0';
	this->type = '_';
	this->extra = '_';
}

Square::Square(char colour, char type, char extra){
	setColour(colour);
	setType(type);
	setExtra(extra);
}
//**************--------------------------- Square()- END ----------------------------***************
