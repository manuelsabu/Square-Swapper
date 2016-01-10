#include "intboard.h"
#include "level.h"

using namespace std;

//**************-------------------------- matchL1()- START --------------------------***************
//Purpose:
//Arguments:
//Returns:

int IntBoard::matchL1(){
    int myColor, c1, c2, c3, c4;
    int type0, type1, type2, type3, type4;
    int len = 10;
    int unstable = 40;
    int myCounter = 0;
    for (int i = 0; i<len-2; i++){
        for (int j = 0; j<len-2; j++){
            myColor = (table[i][j])%10;
            type0 = ((table[i][j])%100)/10;
            c1 = (table[i][j+1])%10;
            type1 = ((table[i][j+1])%100)/10;
            c2 = (table[i][j+2])%10;
            type2 = ((table[i][j+2])%100)/10;
            c3 = (table[i+1][j])%10;
            type3 = ((table[i+1][j])%100)/10;
            c4 = (table[i+2][j])%10;
            type4 = ((table[i+2][j])%100)/10;
            if ((myColor==c1)&&(myColor==c2)&&(myColor==c3)&&(myColor==c4)){
                myCounter++;
                table[i][j] = unstable + myColor;
                table[i][j+1] = (type1 == 4) ? -type1-5 : -type1;
                table[i][j+2] = (type2 == 4) ? -type2-5 : -type2;
                table[i+1][j] = (type3 == 4) ? -type3-5 : -type3;
                table[i+2][j] = (type4 == 4) ? -type4-5 : -type4;
                if (table[i][j+1] == -5){
                    table[i][j+1] = -myColor*10 - 5;
                }
                if (table[i][j+2] == -5){
                    table[i][j+2] = -myColor*10 - 5;
                }
                if (table[i+1][j] == -5){
                    table[i+1][j] = -myColor*10 - 5;
                }
                if (table[i+2][j] == -5){
                    table[i+2][j] = -myColor*10 - 5;
                }
                if ((1 == type0)&&(1 == type1)&&(1 == type2)&&(1 == type3)&&(1 == type4)){
                    scoreBoard[i][j+1] = scoreBoard[i][j+2] = scoreBoard[i+1][j] = scoreBoard[i+2][j] = 5;
                    scoreBoard[i][j] = 5;
                }
                
            }
        }
    }
    return myCounter;
}
//**************--------------------------- matchL1()- END ---------------------------***************

//**************-------------------------- matchL2()- START --------------------------***************
//Purpose:
//Arguments:
//Returns:

int IntBoard::matchL2(){
    int myColor, c1, c2, c3, c4;
    int type0, type1, type2, type3, type4;
    int len = 10;
    int unstable = 40;
    int myCounter = 0;
    for (int i = 0; i<len-2; i++){
        for (int j = 2; j<len; j++){
            myColor = (table[i][j])%10;
            type0 = ((table[i][j])%100)/10;
            c1 = (table[i][j-1])%10;
            type1 = ((table[i][j-1])%100)/10;
            c2 = (table[i][j-2])%10;
            type2 = ((table[i][j-2])%100)/10;
            c3 = (table[i+1][j])%10;
            type3 = ((table[i+1][j])%100)/10;
            c4 = (table[i+2][j])%10;
            type4 = ((table[i+2][j])%100)/10;
            if ((myColor==c1)&&(myColor==c2)&&(myColor==c3)&&(myColor==c4)){
                myCounter++;
                
                table[i][j-1] = (type1 == 4) ? -type1-5 : -type1;
                table[i][j-2] = (type2 == 4) ? -type2-5 : -type2;
                table[i+1][j] = (type3 == 4) ? -type3-5 : -type3;
                table[i+2][j] = (type4 == 4) ? -type4-5 : -type4;
                
                table[i][j] = unstable + myColor;
                if (table[i][j-1] == -5){
                    table[i][j-1] = -myColor*10 - 5;
                }
                if (table[i][j-2] == -5){
                    table[i][j-2] = -myColor*10 - 5;
                }
                if (table[i+1][j] == -5){
                    table[i+1][j] = -myColor*10 - 5;
                }
                if (table[i+2][j] == -5){
                    table[i+2][j] = -myColor*10 - 5;
                }
                
                if ((1 == type0)&&(1 == type1)&&(1 == type2)&&(1 == type3)&&(1 == type4)){
                    scoreBoard[i][j-1] = scoreBoard[i][j-2] = scoreBoard[i+1][j] = scoreBoard[i+2][j] = 5;
                    scoreBoard[i][j] = 5;
                }
                
                
            }
        }
    }
    return myCounter;
}
//**************--------------------------- matchL2()- END ---------------------------***************

//**************-------------------------- matchL3()- START --------------------------***************
//Purpose:
//Arguments:
//Returns:

int IntBoard::matchL3(){
    int myColor, c1, c2, c3, c4;
    int type0, type1, type2, type3, type4;
    int len = 10;
    int unstable = 40;
    int myCounter = 0;
    for (int i = 2; i<len; i++){
        for (int j = 0; j<len-2; j++){
            myColor = (table[i][j])%10;
            type0 = ((table[i][j])%100)/10;
            c1 = (table[i][j+1])%10;
            type1 = ((table[i][j+1])%100)/10;
            c2 = (table[i][j+2])%10;
            type2 = ((table[i][j+2])%100)/10;
            c3 = (table[i-1][j])%10;
            type3 = ((table[i-1][j])%100)/10;
            c4 = (table[i-2][j])%10;
            type4 = ((table[i-2][j])%100)/10;
            if ((myColor==c1)&&(myColor==c2)&&(myColor==c3)&&(myColor==c4)){
                myCounter++;
                table[i][j] = unstable + myColor;
                table[i][j+1] = (type1 == 4) ? -type1-5 : -type1;
                table[i][j+2] = (type2 == 4) ? -type2-5 : -type2;
                table[i-1][j] = (type3 == 4) ? -type3-5 : -type3;
                table[i-2][j] = (type4 == 4) ? -type4-5 : -type4;
                if (table[i][j+1] == -5){
                    table[i][j+1] = -myColor*10 - 5;
                }
                if (table[i][j+2] == -5){
                    table[i][j+2] = -myColor*10 - 5;
                }
                if (table[i-1][j] == -5){
                    table[i-1][j] = -myColor*10 - 5;
                }
                if (table[i-2][j] == -5){
                    table[i-2][j] = -myColor*10 - 5;
                }
                if ((1 == type0)&&(1 == type1)&&(1 == type2)&&(1 == type3)&&(1 == type4)){
                    scoreBoard[i][j+1] = scoreBoard[i][j+2] = scoreBoard[i-1][j] = scoreBoard[i-2][j] = 5;
                    scoreBoard[i][j] = 5;
                }
                
            }
        }
    }
    return myCounter;
}
//**************--------------------------- matchL3()- END ---------------------------***************

//**************-------------------------- matchL4()- START --------------------------***************
//Purpose:
//Arguments:
//Returns:

int IntBoard::matchL4(){
    int myColor, c1, c2, c3, c4; //Stores each color
    int type0, type1, type2, type3, type4;
    int len = 10;
    int unstable = 40;
    int myCounter = 0;
    for (int i = 2; i<len; i++){   //Loops go throgh the our array
        for (int j = 2; j<len; j++){
            myColor = (table[i][j])%10;
            type0 = ((table[i][j])%100)/10;
            c1 = (table[i][j-1])%10;
            type1 = ((table[i][j-1])%100)/10;
            c2 = (table[i][j-2])%10;
            type2 = ((table[i][j-2])%100)/10;
            c3 = (table[i-1][j])%10;
            type3 = ((table[i-1][j])%100)/10;
            c4 = (table[i-2][j])%10;
            type4 = ((table[i-2][j])%100)/10;
            if ((myColor==c1)&&(myColor==c2)&&(myColor==c3)&&(myColor==c4)){
                myCounter++;
                table[i][j] = unstable + myColor;
                table[i][j-1] = (type1 == 4) ? -type1-5 : -type1;
                table[i][j-2] = (type2 == 4) ? -type2-5 : -type2;
                table[i-1][j] = (type3 == 4) ? -type3-5 : -type3;
                table[i-2][j] = (type4 == 4) ? -type4-5 : -type4;
                if (table[i][j-1] == -5){
                    table[i][j-1] = -myColor*10 - 5;
                }
                if (table[i][j-2] == -5){
                    table[i][j-2] = -myColor*10 - 5;
                }
                if (table[i-1][j] == -5){
                    table[i-1][j] = -myColor*10 - 5;
                }
                if (table[i-2][j] == -5){
                    table[i-2][j] = -myColor*10 - 5;
                }
                if ((1 == type0)&&(1 == type1)&&(1 == type2)&&(1 == type3)&&(1 == type4)){
                    scoreBoard[i][j-1] = scoreBoard[i][j-2] = scoreBoard[i-1][j] = scoreBoard[i-2][j] = 5;
                    scoreBoard[i][j] = 5;
                }
            }
        }
    }
    return myCounter;
}
//**************--------------------------- matchL4()- END ---------------------------***************

//**************-------------------------- matchL()- START ---------------------------***************
//Purpose: Finds the all possible L matches. It has four sub functions
//Arguments:
//Returns:

int IntBoard::matchL(){
    int myCounter = 0;
    myCounter += matchL1();
    myCounter += matchL2();
    myCounter += matchL3();
    myCounter += matchL4();
    return myCounter;
}
//**************--------------------------- matchL()- END ----------------------------***************

//**************------------------------ matchOtherH()- START ------------------------***************
//Purpose: Checks the horizontal matches for matchOther.
//Arguments:
//Returns:

int IntBoard::matchOtherH(int matchType, int firstTest){
    int myColor, c1, c2, c3, c4;
    int type0, type1, type2, type3, type4;
    int base;
    int myCounter = 0;
    for (int i = 0; i<10; i++){
        for (int j = 0; j<=(10-matchType); j++){
            myColor = (table[i][j])%10;
            type0 = ((table[i][j])%100)/10;
            if (matchType == 3){
                c1 = (table[i][j+1])%10;
                type1 = ((table[i][j+1])%100)/10;
                c2 = (table[i][j+2])%10;
                type2 = ((table[i][j+2])%100)/10;
                if ((myColor==c1)&&(myColor==c2)){
                    myCounter++;
                    if (!firstTest){
                        table[i][j] = (type0 == 4) ? -type0-matchType : -type0;
                        table[i][j+1] = (type1 == 4) ? -type1-matchType : -type1;
                        table[i][j+2] = (type2 == 4) ? -type2-matchType : -type2;
                        for (int s=0; s<3; s++){
                            if (table[i][j+s] == -5){
                                table[i][j+s]= -myColor*10 - 5;
                            }
                        }
                        if ((1 == type0)&&(1 == type1)&&(1 == type2)){
                            scoreBoard[i][j] = scoreBoard[i][j+1] = scoreBoard[i][j+2] = 3;
                        }
                    }
                }
                
            }
            else if(matchType == 4){
                c1 = (table[i][j+1])%10;
                type1 = ((table[i][j+1])%100)/10;
                c2 = (table[i][j+2])%10;
                type2 = ((table[i][j+2])%100)/10;
                c3 = (table[i][j+3])%10;
                type3 = ((table[i][j+3])%100)/10;
                if ((myColor==c1)&&(myColor==c2)&&(myColor==c3)){
                    myCounter++;
                    table[i][j] = (type0 == 4) ? -type0-matchType : -type0;
                    table[i][j+1] = (type1 == 4) ? -type1-matchType : -type1;
                    table[i][j+2] = (type2 == 4) ? -type2-matchType : -type2;
                    table[i][j+3] = (type3 == 4) ? -type3-matchType : -type3;
                    //counting score
                    if ((1 == type0)&&(1 == type1)&&(1 == type2)&&(1 == type3)){
                        scoreBoard[i][j] = scoreBoard[i][j+1] = scoreBoard[i][j+2] = scoreBoard[i][j+3] = 4;
                    }
                    //****
                    for (int s=0; s<4; s++){
                        if (table[i][j+s] == -5){
                            table[i][j+s]= -myColor*10 - 5;
                        }
                    }
                    //if (type1 == 1){
                    base = 20;
                    table[i][j+1] = base + myColor;
                    //}
                    //else {
                    //   table[i][j+1] = -200-myColor;
                    //}
                }
            }
            else if(matchType == 5){
                c1 = (table[i][j+1])%10;
                type1 = ((table[i][j+1])%100)/10;
                c2 = (table[i][j+2])%10;
                type2 = ((table[i][j+2])%100)/10;
                c3 = (table[i][j+3])%10;
                type3 = ((table[i][j+3])%100)/10;
                c4 = (table[i][j+4])%10;
                type4 = ((table[i][j+4])%100)/10;
                if ((myColor==c1)&&(myColor==c2)&&(myColor==c3)&&(myColor==c4)){
                    myCounter++;
                    table[i][j] = (type0 == 4) ? -type0-matchType : -type0;
                    table[i][j+1] = (type1 == 4) ? -type1-matchType : -type1;
                    table[i][j+3] = (type3 == 4) ? -type3-matchType : -type3;
                    table[i][j+4] = (type4 == 4) ? -type4-matchType : -type4;
                    //for score
                    if ((1 == type0)&&(1 == type1)&&(1 == type2)&&(1 == type3)&&(1 == type4)){
                        scoreBoard[i][j] = scoreBoard[i][j+1] = scoreBoard[i][j+2] = scoreBoard[i][j+3] = 5;
                        scoreBoard[i][j+4] = 5;
                    }
                    for (int s=0; s<5; s++){
                        if (table[i][j+s] == -5){
                            table[i][j+s]= -myColor*10 - 5;
                        }
                    }
                    //  if (type1 == 1){
                    base = 50;
                    table[i][j+2] = base + myColor;
                    //  }
                    //  else {
                    //      table[i][j+2] = -502;
                    // }
                }
            }
        }
    }
    return myCounter;
}
//**************------------------------- matchOtherH()- END -------------------------***************

//**************------------------------ matchOtherV()- START ------------------------***************
//Purpose: Helper for matchOther. Takes care of vertical matches.
//Arguments:
//Returns:

int IntBoard::matchOtherV(int matchType, int firstTest){
    int myColor, c1, c2, c3, c4;
    int type0, type1, type2, type3, type4;
    int base;
    int myCounter = 0;
    for (int i = 0; i<=(10-matchType); i++){
        for (int j = 0; j<10; j++){
            myColor = (table[i][j])%10;
            type0 = ((table[i][j])%100)/10;
            if (matchType == 3){
                c1 = (table[i+1][j])%10;
                type1 = ((table[i+1][j])%100)/10;
                c2 = (table[i+2][j])%10;
                type2 = ((table[i+2][j])%100)/10;
                if ((myColor==c1)&&(myColor==c2)){
                    myCounter++;
                    if(!firstTest){
                        table[i][j] = (type0 == 4) ? -type0-matchType : -type0;
                        table[i+1][j] = (type1 == 4) ? -type1-matchType : -type1;
                        table[i+2][j] = (type2 == 4) ? -type2-matchType : -type2;
                        for (int s=0; s<3; s++){
                            if (table[i+s][j] == -5){
                                table[i+s][j]= -myColor*10 - 5;
                            }
                        }
                        if ((1 == type0)&&(1 == type1)&&(1 == type2)){
                            scoreBoard[i][j] = scoreBoard[i+1][j] = scoreBoard[i+2][j] = 3;
                        }
                    }
                }
                
            }
            else if(matchType == 4){
                c1 = (table[i+1][j])%10;
                type1 = ((table[i+1][j])%100)/10;
                c2 = (table[i+2][j])%10;
                type2 = ((table[i+2][j])%100)/10;
                c3 = (table[i+3][j])%10;
                type3 = ((table[i+3][j])%100)/10;
                if ((myColor==c1)&&(myColor==c2)&&(myColor==c3)){
                    myCounter++;
                    table[i][j] = (type0 == 4) ? -type0-matchType : -type0;
                    table[i+1][j] = (type1 == 4) ? -type1-matchType : -type1;
                    table[i+2][j] = (type2 == 4) ? -type2-matchType : -type2;
                    table[i+3][j] = (type3 == 4) ? -type3-matchType : -type3;
                    for (int s=0; s<4; s++){
                        if (table[i+s][j] == -5){
                            table[i+s][j]= -myColor*10 - 5;
                        }
                    }
                    if ((1 == type0)&&(1 == type1)&&(1 == type2)&&(1 == type3)){
                        scoreBoard[i][j] = scoreBoard[i+1][j] = scoreBoard[i+2][j] = scoreBoard[i+3][j] = 4;
                    }
                    base = 30;
                    table[i+1][j] = base + myColor;
                }
            }
            else if(matchType == 5){
                c1 = (table[i+1][j])%10;
                type1 = ((table[i+1][j])%100)/10;
                c2 = (table[i+2][j])%10;
                type2 = ((table[i+2][j])%100)/10;
                c3 = (table[i+3][j])%10;
                type3 = ((table[i+3][j])%100)/10;
                c4 = (table[i+4][j])%10;
                type4 = ((table[i+4][j])%100)/10;
                if ((myColor==c1)&&(myColor==c2)&&(myColor==c3)&&(myColor==c4)){
                    myCounter++;
                    table[i][j] = (type0 == 4) ? -type0-matchType : -type0;
                    table[i+1][j] = (type1 == 4) ? -type1-matchType : -type1;
                    table[i+3][j] = (type3 == 4) ? -type3-matchType : -type3;
                    table[i+4][j] = (type4 == 4) ? -type4-matchType : -type4;
                    for (int s=0; s<5; s++){
                        if (table[i+s][j] == -5){
                            table[i+s][j]= -myColor*10 - 5;
                        }
                    }
                    if ((1 == type0)&&(1 == type1)&&(1 == type2)&&(1 == type3)&&(1 == type4)){
                        scoreBoard[i][j] = scoreBoard[i+1][j] = scoreBoard[i+2][j] = scoreBoard[i+2][j] = 5;
                        scoreBoard[i][j+3] = 5;
                    }
                    base = 50;
                    table[i+2][j] = base + myColor;
                }
            }
        }
    }
    return myCounter;
}
//**************------------------------- matchOtherV()- END -------------------------***************

//**************------------------------ matchOther()- START -------------------------***************
//Purpose: Wrapper to find all the matches for 3, 4, and 5.
//Arguments:
//Returns:

int IntBoard::matchOther(int matchType, int firstTest){
    int myReturn = matchOtherH(matchType, firstTest);
    myReturn += matchOtherV(matchType, firstTest);
    if (!firstTest){
        if (matchType == 3){
            // score += myReturn*3*1;
        }
        else if(matchType == 4){
            //score += myReturn*4*2;
        }
        else {
            //score += myReturn*5*3;
        }
    }
    return myReturn;
}
//**************------------------------- matchOther()- END --------------------------***************

//**************------------------------- bigMatch()- START --------------------------***************
//Purpose: Finds all the possible matches in the grid and manipulates them in the appropriate way.
//Arguments:
//Returns:

//Purpose:
//
//
int IntBoard::bigMatch(){
    if (!(matchOther(3, 1))){
        return 0;
    }
    else {
        initScoreBoard();
        matchT();
        matchL();
        matchOther(5, 0);
        matchOther(4, 0);
        matchOther(3, 0);
        for (int i=0; i<100; i++){
            clearSpecial();
        }
        prepScoreBoard();
        calcScore();
        return 1;
    }
}
//**************-------------------------- bigMatch()- END ---------------------------***************

//**************-------------------------- matchT()- START ---------------------------***************
// Purpose: Looks for the 4 variations of the T shape in the grid.
// Arguments: A Table
// Return: Total number of T matches

int IntBoard::matchT(){
	int total = 0, c1, c2, c3, c4, c5, c6, c7;
	
	//Test for upright T
	for(int i = 0; i <= 7 ; ++i){
		for(int j = 2; j <= 7; ++j){
			if(table[i][j] != -1){
				c1 = table[i][j];
				c2 = table[i][j-1];
				c3 = table[i][j-2];
				c4 = table[i][j+1];
				c5 = table[i][j+2];
				c6 = table[i+1][j];
				c7 = table[i+2][j];
				if(((c1%10) == (c2%10)) && ((c1%10) == (c3%10)) && ((c1%10) == (c4%10)) &&
				   ((c1%10) == (c5%10)) && ((c1%10) == (c6%10)) && ((c1%10) == (c7%10))){
					table[i][j-1] = table[i][j-2] = table[i][j+1] =
					table[i][j+2] = table[i+1][j] = table[i+2][j] = -1; //Void square
					table[i][j] = ((c1/100)*100) + 60 + (c1%10);	//Set special square
					++total;
				}}}}
	
	//Test for left T
	for(int i = 2; i <= 7; ++i){
		for(int j = 0; j <= 7; ++j){
			if(table[i][j] != -1){
				c1 = table[i][j];
				c2 = table[i-1][j];
				c3 = table[i-2][j];
				c4 = table[i+1][j];
				c5 = table[i+2][j];
				c6 = table[i][j+1];
				c7 = table[i][j+2];
				if(((c1%10) == (c2%10)) && ((c1%10) == (c3%10)) && ((c1%10) == (c4%10)) &&
				   ((c1%10) == (c5%10)) && ((c1%10) == (c6%10)) && ((c1%10) == (c7%10))){
					table[i-1][j] = table[i-2][j] = table[i+1][j] =
					table[i+2][j] = table[i][j+1] = table[i][j+2] = -1; //Void square
					table[i][j] = ((c1/100)*100) + 60 + (c1%10);	//Set special square
					++total;
				}}}}
	
	//Test for right T
	for(int i = 2; i <= 7; ++i){
		for(int j = 2; j <= 9; ++j){
			if(table[i][j] != -1){
				c1 = table[i][j];
				c2 = table[i][j-1];
				c3 = table[i][j-2];
				c4 = table[i-1][j];
				c5 = table[i-2][j];
				c6 = table[i+1][j];
				c7 = table[i+2][j];
				if(((c1%10) == (c2%10)) && ((c1%10) == (c3%10)) && ((c1%10) == (c4%10)) &&
				   ((c1%10) == (c5%10)) && ((c1%10) == (c6%10)) && ((c1%10) == (c7%10))){
					table[i][j-1] = table[i][j-2] = table[i-1][j] =
					table[i-2][j] = table[i+1][j] = table[i+2][j] = -1; //Void square
					table[i][j] = ((c1/100)*100) + 60 + (c1%10);	//Set special square
					++total;
				}}}}
	
	//Test for upside down T
	for(int i = 2; i <= 9; ++i){
		for(int j = 2; j <= 7; ++j){
			if(table[i][j] != -1){
				c1 = table[i][j];
				c2 = table[i-1][j];
				c3 = table[i-2][j];
				c4 = table[i][j-1];
				c5 = table[i][j-2];
				c6 = table[i][j+1];
				c7 = table[i][j+2];
				if(((c1%10) == (c2%10)) && ((c1%10) == (c3%10)) && ((c1%10) == (c4%10)) &&
				   ((c1%10) == (c5%10)) && ((c1%10) == (c6%10)) && ((c1%10) == (c7%10))){
					table[i-1][j] = table[i-2][j] = table[i][j-1] =
					table[i][j-2] = table[i][j+1] = table[i][j+2] = -1; //Void square
					table[i][j] = ((c1/100)*100) + 60 + (c1%10);	//Set special square
					++total;
				}}}}
	return total;
}
//**************--------------------------- matchT()- END ----------------------------***************

//**************------------------------- setScore()- START --------------------------***************
//Purpose:
//Arguments:
//Returns:

int IntBoard::setScore(){
    score = 0;
	return 0;
}
//**************-------------------------- getScore()- END ---------------------------***************

//**************------------------------- getScore()- START --------------------------***************
//Purpose:
//Arguments:
//Returns:

int IntBoard::getScore(){
    return score;
}
//**************-------------------------- getScore()- END ---------------------------***************

//**************--------------------------- cave()- START ----------------------------***************
//Purpose:
//Arguments:
//Returns:

void IntBoard::cave(int x, int y, int z){
    int actual, myType;
    if (z>5) return;
    int startX, startY;
    if (z == 3){
        startX = x-1;
        startY = y-1;
    }
    else{
        startX = x-2;
        startY = y-2;
    }
    for (int i=0; i<z; i++){
        for (int j=0; j<z; j++){
            if ((0<=startX+i)&&(startX+i<=9)&&(0<=startY+j)&&(startY+j<=9)){
                actual = table[startX+i][startY+j];
                if (actual >= 0){
                    myType = (actual%100)/10;
                    table[startX+i][startY+j] = -myType;
                    if (myType == 4){
                        table[startX+i][startY+j]=-8;
                    }
                }
            }
        }
    }
}
//**************---------------------------- cave()- END -----------------------------***************

//**************---------------------- colourExploder()- START -----------------------***************
//Purpose:
//Arguments:
//Returns:

void IntBoard::colorExploder(int myColor){
    int len = 10;
    int actual;
    int myType, tempColor;
    for (int i=0; i<len; i++){
        for (int j=0; j<len; j++){
            actual = table[i][j];
            tempColor = actual%10;
            if (actual >= 0){
                if (tempColor == myColor){
                    myType = (actual%100)/10;
                    table[i][j] = -myType;
                }
            }
        }
    }
}
//**************----------------------- colourExploder()- END ------------------------***************

//**************------------------------- clearCol()- START --------------------------***************
//Purpose:
//Arguments:
//Returns:

void IntBoard::clearCol(int c){
    int len = 10;
    int actual;
    int myType;
    for (int i = 0; i<len; i++){
        actual = table[i][c];
        if (actual >= 0){
            myType = (actual%100)/10;
            table[i][c] = -myType;
            if (myType == 5){
                table[i][c]= -((actual%100)/10)*10 -myType;
            }
            if (myType == 4){
                table[i][c] = -8;
            }
        }
    }
}
//**************-------------------------- clearCol()- END ---------------------------***************

//**************------------------------- clearRow()- START --------------------------***************
//Purpose:
//Arguments:
//Returns:

void IntBoard::clearRow(int r){
    int len = 10;
    int actual;
    int myType;
    for (int j = 0; j<len; j++){
        actual = table[r][j];
        if (actual >= 0){
            myType = (actual%100)/10;
            table[r][j] = -myType;
            if (myType == 5){
                table[r][j]= -(actual%10)*10 -myType;
            }
            if (myType == 4){
                table[r][j] = -8;
            }
        }
    }
}
//**************-------------------------- clearRow()- END ---------------------------***************

//**************----------------------- clearSpecial()- START ------------------------***************
//Purpose:
//Arguments:
//Returns:

void IntBoard::clearSpecial(){
    int len = 10;
    int myType;
    for (int i=0; i<len; i++){
        for (int j=0; j<len; j++){
            myType = table[i][j];
            if (myType < 0){
                if (myType == -2){
                    table[i][j] = -1;
                    clearRow(i);
                }
                else if(myType == -3){
                    table[i][j] = -1;
                    clearCol(j);
                }
                
                /*else if(myType < -100){
                 int temp = ((-myType)%1000)/100;
                 int color = (-myType)%10;
                 table[i][j] = -1;
                 if (temp == 2){
                 clearRow(i);
                 }
                 temp = temp*10 + color;
                 table[i][j]=temp;
                 }*/
                else if((-myType)%10 == 5){
                    table[i][j] = -1;
                    colorExploder(((-myType)%100)/10);
                }
                else if(myType == -7){
                    table[i][j] = -1;
                    cave(i, j, 3);
                }
                else if((myType == -8)||(myType == -9)){
                    table[i][j] = -1;
                    cave(i, j, 5);
                }
            }
        }
    }
}
//**************------------------------ clearSpecial()- END -------------------------***************

//**************---------------------- initSchoreBoard()- START ----------------------***************
//Purpose:
//Arguments:
//Returns:

void IntBoard::initScoreBoard(){
    int len = 10;
    for (int i = 0; i<len; i++){
        for (int j = 0; j<len; j++){
            scoreBoard[i][j]=0;
        }
    }
}
//**************----------------------- initSchoreBoard()- END -----------------------***************

//**************---------------------- prepScoreBoard()- START -----------------------***************
//Purpose:
//Arguments:
//Returns:

void IntBoard::prepScoreBoard(){
    int len = 10;
    for (int i = 0; i<len; i++){
        for (int j = 0; j<len; j++){
            if ((scoreBoard[i][j] != 3)&&(scoreBoard[i][j] != 4)&&(scoreBoard[i][j] != 5)){
                if (table[i][j]<0){
                    scoreBoard[i][j] = 6;
                }
            }
        }
    }
}
//**************----------------------- prepScoreBoard()- END ------------------------***************

//**************------------------------- calcScore()- START -------------------------***************
//Purpose:
//Arguments: No arguments
//Returns: It changes the score field inside the IntBoard class

void IntBoard::calcScore(){
    int len = 10;
    int tempScore = 0;
    if (!scoreSwitch) return;
    for (int i = 0; i<len; i++){
        for (int j = 0; j<len; j++){
            if (scoreBoard[i][j] == 3){
                tempScore += 1;
            }
            else if (scoreBoard[i][j] == 4){
                tempScore += 2;
            }
            else if(scoreBoard[i][j] == 5){
                tempScore += 3;
            }
            else if (scoreBoard[i][j] == 6){
                tempScore += 4;
            }
        }
    }
    score = score + chainFactor*tempScore;
}
//**************-------------------------- calcScore()- END --------------------------***************

//**************------------------------ operator<<()- START -------------------------***************
//Purpose:
//Arguments:
//Returns:

ostream& operator<<(ostream& out, const IntBoard& ib){
    int len = 10;
    for (int i = 0; i<len; i++){
        for (int j = 0; j<len; j++){
            out<<ib.table[i][j]<<" ";
        }
        cout <<endl;
    }
    return out;
}
//**************------------------------- operator<<()- END --------------------------***************




