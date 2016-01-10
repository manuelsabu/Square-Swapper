//
//  level.h
//  myMatches
//
//  Created by H ghiassi on 2014-11-19.
//  Copyright (c) 2014 H ghiassi. All rights reserved.
//

#ifndef __myMatches__level__
#define __myMatches__level__

#include <iostream>
#include "square.h"

class Level {
    
public:
    char lockTable[10][10];
    virtual ~Level();
    virtual void randomGenerator(Square *sq) = 0;
    virtual void readFromFile(Square *sq) = 0;
    virtual int limit() = 0;
};
#endif
