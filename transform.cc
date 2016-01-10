#include <iostream>
#include "square.h"					

std::string transform(string conversion){
	int	intTable[10][10];
	int textTable[10][10];
	
	if(conversion == "S2T")
	{
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				textTable[i][j] = mySquares[i][j].getExtra();
				textTable[i][j] += mySquares[i][j].getType();
				textTable[i][j] += mySquares[i][j].getColour();
			}
		}
	}
	
	else if(conversion == "S2I"){
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				if(mySquares[i][j].getExtra() == '_'){
					intTable[i][j] = 100;
				}
				
				if(mySquares[i][j].getType() == '_'){
					intTable[i][j] += 10;
				}
				else if(mySquares[i][j].getType() == 'h'){
					intTable[i][j] += 20;
				}
				else if(mySquares[i][j].getType() == 'v'){
					intTable[i][j] += 30;
				}
				else if(mySquares[i][j].getType() == 'b'){
					intTable[i][j] += 40;
				}
				else if(mySquares[i][j].getType() == 'p'){
					intTable[i][j] += 50;
				}
				
				if(mySquares[i][j].getColour() == '0'){
					intTable[i][j] += 0;
				}
				
				else if(mySquares[i][j].getColour() == '1'){
					intTable[i][j] += 1;
				}
				
				else if(mySquares[i][j].getColour() == '2'){
					intTable[i][j] += 2;
				}
				
				else if(mySquares[i][j].getColour() == '3'){
					intTable[i][j] += 3;
				}
			}
		}
	}
	
	else if(conversion == "I2S"){
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				mySquares[i][j].setColour(intTable[i][j]%10);
				mySquares[i][j].setType((intTable[i][j]%100)/10);
				mySquares[i][j].setExtra(intTable[i][j]/10);
			}
		}
	}
	
	else if(conversion == "T2S"){
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				mySquares[i][j].setExtra((textTable[i][j])[0]);
				mySquares[i][j].setType((textTable[i][j])[1]);
				mySquares[i][j].setColour((textTable[i][j])[2]);
			}
		}
	}
}