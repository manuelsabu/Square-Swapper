//
//  level2.cpp
//  myMatches
//
//  Created by H ghiassi on 2014-11-29.
//  Copyright (c) 2014 H ghiassi. All rights reserved.
//

#include "level2.h"


using namespace std;



void Level2::randomGenerator(Square *sq){
    int myRange = 4;
    int myRand = rand()% myRange;
    if (myRand == 0){
        sq->setColour('0');//set to white
    }
    else if (myRand == 1){
        sq->setColour('1');//set to red
    }
    else if (myRand == 2){
        sq->setColour('2');//set to green
    }
    else {
        sq->setColour('3');//set to blue
    }
}

void Level2::readFromFile(Square *sq){
    char read;
    read = str[0];
    str.erase(str.begin());
    str = str + read;
    if (read == '0'){
        sq->setColour('0');
    }
    else if (read == '1'){
        sq->setColour('1');
    }
    else if (read == '2'){
        sq->setColour('2');
    }
    else if(read == '3'){
        sq->setColour('3');
    }
    sq->setExtra('_');
    sq->setType('_');
}

Level2::~Level2(){}

Level2::Level2(string theFile):fStream(theFile.c_str()){
    int len = 10;
    string myIgnore;
    for (int i = 0; i<len; i++){
        getline(fStream, myIgnore);
    }
    myIgnore = "";
    while(fStream>>myIgnore){
        str = str + myIgnore;
    }
    for (int i = 0;i<len; i++){
        for (int j = 0; j<len; j++){
            this->lockTable[i][j] = 'n';
        }
    }
    this->randomLock();
}

void Level2::randomLock(){
    int numLock = 20;
    int randX, randY;
    while(numLock>0){
        randX = rand()%10;
        randY = rand()%10;
        if (this->lockTable[randX][randY] != 'l'){
			this->lockTable[randX][randY] = 'l';
			numLock--;
        }
    }
    
}

int Level2::limit(){
    return 500;
}