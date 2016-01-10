//
//  Level0.h
//  myMatches
//
//  Created by H ghiassi on 2014-11-20.
//  Copyright (c) 2014 H ghiassi. All rights reserved.
//

#ifndef __myMatches__Level0__
#define __myMatches__Level0__

#include <iostream>
#include <fstream>
#include <sstream>
#include "level.h"

class Level0 : public Level{
public:
    std::ifstream fStream;
    std::string str;
    void randomGenerator(Square *sq);
    void readFromFile(Square *sq);
    Level0(std::string theFile);
    virtual int limit();
    ~Level0();
};

#endif
