//
//  level1.cpp
//  myMatches
//
//  Created by H ghiassi on 2014-11-19.
//  Copyright (c) 2014 H ghiassi. All rights reserved.
//

#include "level1.h"

using namespace std;

int Level1::fSpecial = 0;
void Level1::randomGenerator(Square *sq){
    char spArray[4] = {'p','b','v','h'};
    int myRange = 6;
    int myRand = rand() % myRange;
    if (myRand == 0 || myRand == 1){
        sq->setColour('0');//set to white
    }
	
    else if (myRand == 2 || myRand == 3){
        sq->setColour('1');//set to red
    }
	
    else if (myRand == 4){
        sq->setColour('2');//set to green
    }
	
    else {
        sq->setColour('3');//set to blue
    }
	
    if(fSpecial == 4){
        int specialRand = rand()%4;
        sq->setType(spArray[specialRand]);
        fSpecial = 0;
    }
    else {
        sq->setType('_');//set to basic
        fSpecial++;
    }
}
void Level1::readFromFile(Square *sq){
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

Level1::Level1(string theFile):fStream(theFile.c_str()){
    int len = 10;
    string myIgnore;
    for (int i = 0; i<len; i++){
        getline(fStream, myIgnore);
    }
    myIgnore = "";
    while(fStream>>myIgnore){
        str = str + myIgnore;
    }
}

Level1::~Level1(){}
int Level1::limit(){
    return 300;
}
