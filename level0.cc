//
//  Level0.cpp
//  myMatches
//
//  Created by H ghiassi on 2014-11-20.
//  Copyright (c) 2014 H ghiassi. All rights reserved.
//

#include "Level0.h"
#include <fstream>
using namespace std;

Level0::Level0(string theFile):fStream(theFile.c_str()){
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
void Level0::readFromFile(Square *sq){
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
void Level0::randomGenerator(Square *sq){
    
}

Level0::~Level0(){}

int Level0::limit(){
    return 200;
}
