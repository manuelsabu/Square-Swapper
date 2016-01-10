//
//  level1.h
//  myMatches
//
//  Created by H ghiassi on 2014-11-19.
//  Copyright (c) 2014 H ghiassi. All rights reserved.
//

#ifndef __myMatches__level1__
#define __myMatches__level1__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "level.h"
#include "square.h"

class Level1 : public Level{
public:
    std::string str;
    std::ifstream fStream;
    static int fSpecial;
    void randomGenerator(Square *sq);
    void readFromFile(Square *sq);
    virtual int limit();
    Level1(std::string theFile);
    ~Level1();
};
#endif /* defined(__myMatches__level1__) */
