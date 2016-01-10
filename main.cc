#include <iostream>
#include "window.h"
#include "time.h"
#include "intboard.h"
#include "textboard.h"
#include "Board.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include <unistd.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

clock_t t1, t2;
int main(int argc, const char * argv[])
{    
	// Default settings
    int xCord, yCord, dir, tempNum, numSeed = time(NULL), prevScore = 0, numLevel = 0;
    bool textOnly = false, scriptFile = false;
    string readFile = "sequence.txt", theSeed, strLevel = "0";
	
    // Make Argument
    if (argc == 1){
        textOnly = false;
        scriptFile = false;
        readFile = "sequence.txt";
        numSeed = time(NULL);
        srand(numSeed);
        strLevel = "0";
        numLevel = 0;
    }
	
    else {
        for (int i = 1; i < argc; ++i){
            if(string(argv[i]) == "-text"){
                textOnly = true;
            }
            else if(string(argv[i]) == "-seed"){
                theSeed = argv[i+1];
                istringstream ss(theSeed);
                ss>>numSeed;
                srand(numSeed);
                
            }
            else if(string(argv[i]) == "-scriptfile"){
                readFile = argv[i+1];
                scriptFile = true;
            }
            else if(string(argv[i]) == "-startlevel"){
                strLevel = argv[i+1];
                istringstream ss(strLevel);
                ss>>numLevel;
            }
        }
    }
	
    //Creating the Board as a singleton object
    Board *gameBoard = Board::getInstance();
    gameBoard->myTextBoard = new TextBoard();
	gameBoard->intBoard.chainFactor = 1;
	gameBoard->onlyText = textOnly;
    gameBoard->numCurLevel = numLevel;
	
	if(!textOnly){
		gameBoard->myGraphic = new Xwindow();
	}
	
    //Creating the appropriate Level for start of the Game
    if (0 == numLevel){
        gameBoard->curLevel = new Level0(readFile);
        gameBoard->boardFromFile(readFile);
    }
    else if(1 == numLevel){
        gameBoard->curLevel = new Level1(readFile);
        if (scriptFile){
            gameBoard->boardFromFile(readFile);
			
        }
        else {
            gameBoard->initialRandomSquare();
        }
    }
    else if(2 == numLevel){
        gameBoard->curLevel = new Level2(readFile);
        if (scriptFile){
            gameBoard->boardFromFile(readFile);
			gameBoard->lockFromFile(readFile);
        }
        else {
            gameBoard->initialRandomSquare();
        }
    }
	
    else{
        //Extra levels may be added later
    }
	
    //***********************
    //Initialyzing the Board
	gameBoard->intBoard.scoreSwitch = 1; //The score will be calculated
	gameBoard->numCurLevel = numLevel;
    gameBoard->update();
	
    if (numLevel != 0 && !scriptFile){
        gameBoard->scramble();
    }
	
    gameBoard->notify();
    //***********************
    // Instruction names can be easily renamed
    string swap = "swap";
    string hint = "hint";
    string scramble = "scramble";
    string levelup = "levelup";
    string leveldown = "leveldown";
    string restart = "restart";
    string input;
    //Consuming the input
    while (cin>>input){
		
		// Swap
		//---------------------
        if (input == swap){
            cin>>xCord;
            cin>>yCord;
            cin>>dir;
            gameBoard->swap(xCord, yCord, dir);
            gameBoard->notify();
            int matchOcc = gameBoard->intBoard.bigMatch();
            if (!matchOcc){
                gameBoard->swap(xCord, yCord, dir);
                gameBoard->notify();
            }
            else{
				do{
					gameBoard->notify();
					gameBoard->moveDown();
					if ((numLevel == 0) || scriptFile){
						while(gameBoard->readNewSquares()){
							gameBoard->update();
							gameBoard->notify();
							gameBoard->moveDown();
						}
					}
					else {
						while(gameBoard->squareGen()){
							gameBoard->update();
							gameBoard->notify();
							gameBoard->moveDown();
						}
					}
					gameBoard->update();
					gameBoard->notify();
					
					//The score limit
                    if (((gameBoard->intBoard.getScore() - prevScore) >= gameBoard->curLevel->limit())
                        && gameBoard->lockChecker()){
                        if(numLevel == 2){
						 input = "won";
						}
						
						else{
							input = levelup;
						}
                        break;
                    }
                    //**
                    gameBoard->freeLocks();
                    gameBoard->intBoard.chainFactor *= 2;
					
				}while(gameBoard->intBoard.bigMatch());
				gameBoard->intBoard.chainFactor = 1;
			}
            
        }
		
		// Hint
		//---------------------
        else if(input == hint){
            gameBoard->hint();
        }
		
		// Scramble
		//---------------------
        else if (input == scramble){
			
			if(gameBoard->hint(true) == 0){
				cout<<"You can't scramble the Board! A match still exists!"<<endl;
			}
			else{
				gameBoard->scramble();
				gameBoard->notify();
			}
        }
		
		// Level up
		//---------------------
        if (input == levelup){
            if (numLevel == 0 || numLevel == 1){
                delete gameBoard->curLevel;
				
                if (numLevel == 0){
                    gameBoard->curLevel = new Level1(readFile);
                }
                else if(numLevel == 1){
                    gameBoard->curLevel = new Level2(readFile);
                }
				
				if (scriptFile){
					gameBoard->boardFromFile(readFile);
					gameBoard->lockFromFile(readFile);
					gameBoard->update();
				}
				else {
					gameBoard->initialRandomSquare();
					gameBoard->update();
					gameBoard->scramble();
				}
				numLevel++;
                gameBoard->numCurLevel++;
				gameBoard->notify();
                prevScore = gameBoard->intBoard.getScore();
            }
        }
		
		// Level down
		//---------------------
        if (input == leveldown){
            if (numLevel == 1 || numLevel == 2){
                delete gameBoard->curLevel;
				
                if (numLevel == 1){
                    gameBoard->curLevel = new Level0(readFile);
                }
                else if(numLevel == 2) {
                    gameBoard->curLevel = new Level1(readFile);
                }
				
				numLevel--;
				gameBoard->numCurLevel--;
				
                if (scriptFile || numLevel == 0){
					gameBoard->boardFromFile(readFile);
					gameBoard->update();
                }
                else{
                    gameBoard->initialRandomSquare();
					gameBoard->update();
					gameBoard->scramble();
                }
                gameBoard->notify();
				prevScore = gameBoard->intBoard.getScore();
            }
        }
		
		// Restart
		//---------------------
        if (input == restart){
			delete gameBoard->curLevel;
			
			if(numLevel == 0){
				gameBoard->curLevel = new Level0(readFile);
			}
			
			if(numLevel == 1){
				gameBoard->curLevel = new Level1(readFile);
			}
			
			if(numLevel == 2){
				gameBoard->curLevel = new Level2(readFile);
			}
			
            if (numLevel == 0 || scriptFile){
                gameBoard->boardFromFile(readFile);
				gameBoard->update();
            }
            else{
                gameBoard->initialRandomSquare();
				gameBoard->update();
				gameBoard->scramble();
            }
			
			gameBoard->intBoard.setScore();
            gameBoard->notify();
        }
		
		if(input == "won"){
			cout<<"YOU WON! THANKS FOR PLAYING!! :D";
			cout<<"Press any key to exit..";
			getchar();
			input = "exit";		
		}
		
		// Exit
		//---------------------
		if(input == "quit" || input == "exit" || input == "q"){
			delete gameBoard->myTextBoard;
			
			if(!textOnly){
				delete gameBoard->myGraphic;
			}
			
			delete gameBoard->curLevel;
			exit(0);
		}
    }
    
}