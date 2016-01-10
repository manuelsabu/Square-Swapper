//
//  level2.h
//  myMatches
//
//  Created by H ghiassi on 2014-11-29.
//  Copyright (c) 2014 H ghiassi. All rights reserved.
//

#ifndef __myMatches__level2__
#define __myMatches__level2__

#include <iostream>
#include <fstream>
#include "square.h"
#include "level.h"

class Level2 : public Level{
    void randomLock();
public:
    std::string str;
    std::ifstream fStream;
    void randomGenerator(Square *sq);
    void readFromFile(Square *sq);
    Level2(std::string theFile);
    virtual int limit();
    ~Level2();
    
};
#endif /* defined(__myMatches__level2__) */
