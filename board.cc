#include "board.h"
#include "Square.h"
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>

// Definitions:
#define WHITE Xwindow::White
#define RED Xwindow::Red
#define GREEN Xwindow::Green
#define BLUE Xwindow::Blue
#define BLACK Xwindow::Black
#define BROWN Xwindow::Brown

using namespace std;

// Class Variables:
Board *Board::instance = 0;

//**************------------------------ getInstance()- START ------------------------***************
//Purpose: Creates a singleton of the gameBoard from main.
//Arguments: NIL
//Returns: New Board Instance

Board *Board::getInstance(){
    if (!instance){
        instance = new Board;
        atexit(cleanup);
    }
    return instance;
}
//**************------------------------- getInstance()- END -------------------------***************

//**************-------------------------- cleanup()- START --------------------------***************
//Purpose: Deletes the board at exit.
//Arguments: NIL
//Returns: NIL

void Board::cleanup(){
    cout<<"Cleaning Up...";
    delete instance;
}
//**************--------------------------- cleanup()- END ---------------------------***************

//**************--------------------------- Board()- START ---------------------------***************
//Purpose: Constructor for Board class
//Arguments: NIL
//Returns: NIL

Board::Board(){
    len = 10;
}
//**************---------------------------- Board()- END ----------------------------***************

//**************------------------------ squareInit()- START -------------------------***************
//Purpose: Initialize the Square at potition (r,c) to string value "initValue".
//Arguments: int Row number, int Column number, string Initial value.
//Returns: NIL

void Board::squareInit(int r, int c, string initValue){
    mySquares[r][c].setColour(initValue[2]);
    mySquares[r][c].setType(initValue[1]);
    mySquares[r][c].setExtra(initValue[0]);
}
//**************------------------------- squareInit()- END --------------------------***************

//**************------------------------- transform()- START -------------------------***************
//Purpose: Functions to transform between (Integer Board<->Board<->Text Board).
//Arguments: string function name.
//Returns: NIL

void Board::transform(string conversion){
    if(conversion == "S2T")
	{
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				myTextBoard->tb[i][j] = mySquares[i][j].getExtra();
				myTextBoard->tb[i][j] += mySquares[i][j].getType();
				myTextBoard->tb[i][j] += mySquares[i][j].getColour();
			}
		}
	}
	
	else if(conversion == "S2I"){
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				if(mySquares[i][j].getExtra() == '_'){
					intBoard.table[i][j] = 100;
				}
				else if(mySquares[i][j].getExtra() == 'l'){
					intBoard.table[i][j] = 200;
				}
				
				if(mySquares[i][j].getType() == '_'){
					intBoard.table[i][j] += 10;
				}
				else if(mySquares[i][j].getType() == 'h'){
					intBoard.table[i][j] += 20;
				}
				else if(mySquares[i][j].getType() == 'v'){
					intBoard.table[i][j] += 30;
				}
				else if(mySquares[i][j].getType() == 'b'){
					intBoard.table[i][j] += 40;
				}
				else if(mySquares[i][j].getType() == 'p'){
					intBoard.table[i][j] += 50;
				}
				
				if(mySquares[i][j].getColour() == '0'){
					intBoard.table[i][j] += 0;
				}
				else if(mySquares[i][j].getColour() == '1'){
					intBoard.table[i][j] += 1;
				}
				else if(mySquares[i][j].getColour() == '2'){
					intBoard.table[i][j] += 2;
				}
				else if(mySquares[i][j].getColour() == '3'){
					intBoard.table[i][j] += 3;
				}
                else if(mySquares[i][j].getColour() == '_'){
					intBoard.table[i][j] += 4;
                }
			}
		}
	}
	
	else if(conversion == "I2S"){
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                int temp = intBoard.table[i][j];
                if (temp == -1){
                    mySquares[i][j].setColour('_');
                    mySquares[i][j].setType('_');
                    mySquares[i][j].setExtra('_');
                }
                else{
                    if(temp%10 == 0){
                        mySquares[i][j].setColour('0');
                    }
                    else if(temp%10 == 1){
                        mySquares[i][j].setColour('1');
                    }
                    else if(temp%10 == 2){
                        mySquares[i][j].setColour('2');
                    }
                    else if(temp%10 == 3){
                        mySquares[i][j].setColour('3');
                    }
                    
                    else if(temp%10 == 4){
                        mySquares[i][j].setColour('_');
                    }
                    
                    if((temp%100)/10 == 1){
                        mySquares[i][j].setType('_');
                    }
                    else if((temp%100)/10 == 2){
                        mySquares[i][j].setType('h');
                    }
                    else if((temp%100)/10 == 3){
                        mySquares[i][j].setType('v');
                    }
                    else if((temp%100)/10 == 4){
                        mySquares[i][j].setType('b');
                    }
                    else if((temp%100)/10 == 5){
                        mySquares[i][j].setType('p');
                    }
                    
                    if(temp/10 == 1){
                        mySquares[i][j].setExtra('_');
                    }
					else if(temp/10 == 2){
                        mySquares[i][j].setExtra('l');
                    }
                }
            }
        }
    }
	
	else if(conversion == "T2S"){
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				mySquares[i][j].setExtra((myTextBoard->tb[i][j])[0]);
				mySquares[i][j].setType((myTextBoard->tb[i][j])[1]);
				mySquares[i][j].setColour((myTextBoard->tb[i][j])[2]);
                
			}
		}
	}
	
	else{
		cerr << "Passed wrong command!" << endl;
	}
}
//**************-------------------------- transform()- END --------------------------***************

//**************------------------------ operator<<()- START -------------------------***************
//Purpose: Overloaded output operator to print out the Board.
//Arguments: Board object
//Returns: out

ostream& operator<<(ostream& out, const Board& b) {
    int len = 10;
    for (int i = 0; i<len; i++){
        for (int j = 0; j<len; j++){
            out<<b.mySquares[i][j].getExtra();
            out<<b.mySquares[i][j].getType();
            out<<b.mySquares[i][j].getColour()<<" ";
        }
        cout<<endl;
    }
    return out;
}
//**************------------------------- operator<<()- END --------------------------***************

//**************--------------------------- swap()- START ----------------------------***************
// Purpose: Consumes a table, co-ordinates, and swap direction, then returns the swapped table.
// Arguments: Table, X-coordinate, Y-coordinate, and Swap direction
// Retruns: int Fail/Success

int Board::swap(int x, int y, int z){
	int temp;	//Temporary Variable for swap.
	if((x < 10 && x >= 0) && (y < 10 && y >= 0)){
		
		if(z == 0 && x > 0)	{ // Can swap NORTH check
			temp = intBoard.table[x][y];
			intBoard.table[x][y] = intBoard.table[x-1][y];
			intBoard.table[x-1][y] = temp;
		}
		
		else if(z == 1 && x < 9) { // Can swap SOUTH check
			temp = intBoard.table[x][y];
			intBoard.table[x][y] = intBoard.table[x+1][y];
			intBoard.table[x+1][y] = temp;
		}
		
		else if(z == 2 && y > 0) { // Can swap WEST check
			temp = intBoard.table[x][y];
			intBoard.table[x][y] = intBoard.table[x][y-1];
			intBoard.table[x][y-1] = temp;
		}
		
		else if(z == 3 && y < 9) { // Can swap EAST check
			temp = intBoard.table[x][y];
			intBoard.table[x][y] = intBoard.table[x][y+1];
			intBoard.table[x][y+1] = temp;
		}
		
		else {
			cerr << "Invalid Z Co-ordinate!"<<endl;
			return 1;
		}
	}
	
	else {
		cerr << "Invalid (X,Y) Co-ordinate!"<<endl;
		return 1;
	}
	return 0;
}
//**************---------------------------- swap()- END -----------------------------***************

//**************--------------------------- hint()- START ----------------------------***************
//Purpose: Outputs a valid move (x,y, z as above) that would lead to a match.
//Arguments: NIL
//Side Effects: Print out a valid move in the board if possible.
//Returns: int Fail/Success 

int Board::hint(int silent){
    this->intBoard.scoreSwitch = 0;
    // Test matches to EAST
    this->transform("S2I");
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 9; ++j){
            swap(i,j,3);
            if(this->intBoard.bigMatch() != 0){
                this->transform("S2I");
				if(!silent){
					cout<<"Hint: Try swapping "<<i<<", "<<j<<", 3."<<endl;
				}
                this->intBoard.scoreSwitch = 1;
                return 0;
            }
            else{
                this->intBoard.scoreSwitch = 0;
                this->transform("S2I");
            }
        }
    }
	
    // Test matches to SOUTH
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 10; ++j){
            swap(i,j,1);
            if(this->intBoard.bigMatch() != 0){
                this->transform("S2I");
				if(!silent){
                cout<<"Hint: Try swapping "<<i<<", "<<j<<", 1."<<endl;
				}
                this->intBoard.scoreSwitch = 1;
                return 0;
            }
            else{
                this->intBoard.scoreSwitch = 0;
                this->transform("S2I");
            }
        }
    }
    this->transform("S2I");
	if(!silent){
    cerr<<"Hint: No swapping options! Try rescrambling the board!"<<endl;
	}
    this->intBoard.scoreSwitch = 1;
    return 1;
}
//**************---------------------------- hint()- END -----------------------------***************

//**************-------------------------- checker()- START --------------------------***************
//Purpose: Checks for any possible basic matches (match of 3).
//Arguments: int X-Co-ordinate, and int Y-Co-ordinate
//Returns: int Fail/Success

int Board::checker(int x, int y){
    int colour = this->intBoard.table[x][y]%10;
    if((x > 1) && (colour == this->intBoard.table[x-1][y]%10)
       && (colour == this->intBoard.table[x-2][y]%10)){
        return 1;
    }
    if((x < 8) && (colour == this->intBoard.table[x+1][y]%10)
       && (colour == this->intBoard.table[x+2][y]%10)){
        return 1;
    }
    if((y > 1) && (colour == this->intBoard.table[x][y-1]%10)
       && (colour == this->intBoard.table[x][y-2]%10)){
        return 1;
    }
    if((y < 8) && (colour == this->intBoard.table[x][y+1]%10)
       && (colour == this->intBoard.table[x][y+2]%10)){
        return 1;
    }
    if((x > 0) && (x < 9) && (colour == this->intBoard.table[x-1][y]%10)
       && (colour == this->intBoard.table[x+1][y]%10)){
        return 1;
    }
    if((y > 0) && (y < 9) && (colour == this->intBoard.table[x][y-1]%10)
       && (colour == this->intBoard.table[x][y+1]%10)){
        return 1;
    }
    return 0;
}
//**************--------------------------- checker()- END ---------------------------***************

//**************------------------------- scramble()- START --------------------------***************
//Purpose: Scrambles the Board randomly with the existing squares on the Board.
//Arguments: NIL
//Returns: NIl

void Board::scramble(){
    int temp, randX, randY;
    bool repeat = false;
    this->transform("S2I");
    cout<<endl;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            do{
                repeat = true;
                randX = rand() % 10;
                randY = rand() % 10;
                temp = this->intBoard.table[i][j];
                this->intBoard.table[i][j] = this->intBoard.table[randX][randY];
                this->intBoard.table[randX][randY] = temp;
                if(checker(i,j) || checker(randX,randY)){
                    temp = this->intBoard.table[i][j];
                    this->intBoard.table[i][j] = this->intBoard.table[randX][randY];
                    this->intBoard.table[randX][randY] = temp;
                }
                else{
                    repeat = false;
                }
            }while(repeat);
        }
    }
}
//**************-------------------------- scramble()- END ---------------------------***************

//**************------------------------- moveDown()- START --------------------------***************
//Purpose: Shifts all the squares vertically down.
//Arguments: NIL
//Returns:NIL

void Board::moveDown(){
    int k;
    for(int i = 9; i > 0; --i){
        for(int j = 0; j < 10; ++j){
            if((mySquares[i][j].getExtra() == '_') && (mySquares[i][j].getColour() == '_')){
                k = i-1;
				while((mySquares[k][j].getExtra() == '_') && (mySquares[k][j].getColour() == '_') 
					  && (k > 0)){
					k = k-1;
				}
				
				if(mySquares[k][j].getColour() != '_'){
					mySquares[i][j].setColour(mySquares[k][j].getColour());
					mySquares[i][j].setType(mySquares[k][j].getType());
					mySquares[i][j].setExtra(mySquares[k][j].getExtra());
					mySquares[k][j].setType('_');
					mySquares[k][j].setColour('_');
					mySquares[k][j].setExtra('_');
					this->update();
					this->graphicSetter();
				}
			}
        }
    }
}
//**************-------------------------- moveDown()- END ---------------------------***************

//**************----------------------- boardFromFile()- START -----------------------***************
//Purpose: Creates the Board based on the input from a file.
//Arguments: string Filename
//Returns: NIL

void Board::boardFromFile(string fileName){
    string eachSquare;
	int len = 10;
    ifstream fs(fileName.c_str());
    for (int i = 0; i<len; i++){
        for (int j = 0; j<len; j++){
            fs>>eachSquare;
            this->squareInit(i, j, eachSquare);
        }
    }
}
//**************------------------------ boardFromFile()- END ------------------------***************

//**************-------------------------- notify()- START ---------------------------***************
//Purpose: Function to notify() display (graphicSetter());
//Arguments: NIL
//Returns: NIL

void Board::notify(){
    this->transform("I2S");
    this->transform("S2T");
	freeLocks();
	addLocks();
	cout<<endl<<"Level: "<<this->numCurLevel<<endl;
    cout<<"Score: "<<this->intBoard.getScore()<<endl;
	cout<<"------------------------"<<endl<<endl;
    cout<<*(this->myTextBoard)<<endl;
    usleep(20000);
	if(!this->onlyText){
		this->graphicSetter();
	}
}
//**************--------------------------- notify()- END ----------------------------***************

//**************-------------------- initialRandomSquare()- START --------------------***************
//Purpose: Creates the initial board for Level 1 and up based on their probability of squares.
//Arguments: NIL
//Returns: NIL

void Board::initialRandomSquare(){
    int len = 10;
    for (int i = 0; i<len; i++){
        for (int j = 0; j<len; j++){
			this->mySquares[i][j].setColour('_');
			this->mySquares[i][j].setType('_');
			this->mySquares[i][j].setExtra('_');
            this->curLevel->randomGenerator(&(this->mySquares[i][j]));
        }
    }
}
//**************--------------------- initialRandomSquare()- END ---------------------***************

//**************---------------------- readNewSquares()- START -----------------------***************
//Purpose: Reads the next row of squares from a file.
//Arguments: NIL
//Returns: bool Fail/Success

bool Board::readNewSquares(){
    int len = 10;
    bool theSwitch = false;
    for (int j = 0; j  < len; j++){
        if(((this->mySquares[0][j]).getColour() == '_')
           &&
           ((this->mySquares[0][j]).getExtra() == '_')
           &&
           ((this->mySquares[0][j]).getType()== '_')){
            this->curLevel->readFromFile(&(this->mySquares[0][j]));
            theSwitch = true;
        }
    }
    return theSwitch;
}
//**************----------------------- readNewSquares()- END ------------------------***************

//**************-------------------------- update()- START ---------------------------***************
//Purpose: Updates the Integer and Text Board using the Squares from gameBoard.
//Arguments: NIL
//Returns: NIL

void Board::update(){
    this->transform("S2I");
    this->transform("S2T");
}
//**************--------------------------- update()- END ----------------------------***************

//**************------------------------- squareGen()- START -------------------------***************
//Purpose: Creates a new row of random Squares based on level probabilities
//Arguments: NIL
//Returns: bool Fail/Success

bool Board::squareGen(){
    int len = 10, tempArr[len], temp, randPos;
    bool theSwitch = false;
	
	for(int i = 0; i < len; ++i){
		tempArr[i] = i;
	}
	
	for(int i = 0; i < len; ++i){
		randPos = rand()%len;
		temp = tempArr[i];
		tempArr[i] = tempArr[randPos];
		tempArr[randPos] = temp;
	}
	
	for(int i = 0; i < len; ++i){
        if(((this->mySquares[0][tempArr[i]]).getColour() == '_')
           && ((this->mySquares[0][tempArr[i]]).getExtra() == '_')
           && ((this->mySquares[0][tempArr[i]]).getType()== '_')){
            this->curLevel->randomGenerator(&(this->mySquares[0][tempArr[i]]));
            theSwitch = true;
        }
	}
	return theSwitch;
}
//**************-------------------------- squareGen()- END --------------------------***************

//**************----------------------- graphicSetter()- START -----------------------***************
//Purpose: Displays the current state of the Text Board in the graphical window (XWindows)
//Arguments: NIL
//Returns: NIL

void Board::graphicSetter(){
    int len = 10;
    int pixelLen = 50;
    string temp;
    for (int i = 0; i<len; i++){
        for (int j = 0; j<len; j++){
            temp = (this->myTextBoard->tb[i][j])[2];
            if (temp == "0"){
                this->myGraphic->fillRectangle(pixelLen*j, pixelLen*i, pixelLen, pixelLen, WHITE);
            }
            else if(temp == "1"){
                this->myGraphic->fillRectangle(pixelLen*j, pixelLen*i, pixelLen, pixelLen, RED);
            }
            else if(temp == "2"){
                this->myGraphic->fillRectangle(pixelLen*j, pixelLen*i, pixelLen, pixelLen, GREEN);
            }
            else if(temp == "3"){
                this->myGraphic->fillRectangle(pixelLen*j, pixelLen*i, pixelLen, pixelLen, BLUE);
            }
            else if(temp == "_"){
                this->myGraphic->fillRectangle(pixelLen*j, pixelLen*i, pixelLen, pixelLen, BROWN);
                this->myGraphic->drawBigString(pixelLen*j + pixelLen/3 , pixelLen*i + pixelLen/1.5, 
											   ".", BLACK);
                usleep(10000);
            }
            else{
                //More colors might be added later
            }
            temp = (this->myTextBoard->tb[i][j])[1];
            if (temp != "_"){
                this->myGraphic->drawBigString(pixelLen*j + pixelLen/3 , pixelLen*i + pixelLen/1.5, 
											   temp, BLACK);
            }
        }
    }
	graphicLocks();
}
//**************------------------------ graphicSetter()- END ------------------------***************

void Board::freeLocks(){
    int len = 10;
    if (this->numCurLevel == 2){
        for (int i = 0; i<len; i++){
            for (int j = 0; j<len; j++){
                int temp = this->intBoard.scoreBoard[i][j];
                if (temp == 3 || temp == 4 || temp == 5 || temp == 6){
                    this->curLevel->lockTable[i][j] = 'n';
                }
            }
        }
    }
}

//*******
void Board::graphicLocks(){
    int len = 10;
    int thickness = 3;
    int pixelLen = 50;
    if (numCurLevel == 2){
        for (int i = 0; i<len; i++){
            for (int j = 0; j<len; j++){
                if ('l' == (myTextBoard->tb[i][j])[0]){
                    this->myGraphic->fillRectangle(pixelLen*j, pixelLen*i, pixelLen, thickness, BLACK);
                    this->myGraphic->fillRectangle(pixelLen*j, pixelLen*i, thickness, pixelLen, BLACK);
                    this->myGraphic->fillRectangle(pixelLen*j, pixelLen*i + pixelLen -1, pixelLen, thickness, BLACK);
                    this->myGraphic->fillRectangle(pixelLen*j + pixelLen-1, pixelLen*i, thickness, pixelLen+2, BLACK);
                }
            }
        }
    }
}

//****
bool Board::lockChecker(){
    int len = 10;
    if (this->numCurLevel == 2){
        for (int i = 0; i<len; i++){
            for (int j = 0; j<len; j++){
                if ('l' == this->curLevel->lockTable[i][j]){
                    return false;
                }
            }
        }
    }
    return true;
}
//*****
void Board::addLocks(){
    int len = 10;
    if (this->numCurLevel == 2){
        for (int i = 0; i<len; i++){
            for (int j = 0; j<len; j++){
                if ('l' == this->curLevel->lockTable[i][j]){
                    (this->myTextBoard->tb[i][j])[0] = 'l';
                }
            }
        }
    }
}

void Board::lockFromFile(string fileName){
    ifstream fSS(fileName.c_str());
    int len = 10;
    string temp;
    for (int i = 0; i<len; ++i){
        for (int j = 0; j<len; ++j){
            fSS>>temp;
            if (temp[0] == 'l'){
                curLevel->lockTable[i][j] = 'l';
            }
            else{
                curLevel->lockTable[i][j] = 'n';
            }
        }
    }
}
