//
//  textboard.h
//  myMatches
//
//  Created by H ghiassi on 2014-11-19.
//  Copyright (c) 2014 H ghiassi. All rights reserved.
//

#ifndef __myMatches__textboard__
#define __myMatches__textboard__

#include <iostream>
#include <string>

class TextBoard {
public:
    std::string tb[10][10];
    TextBoard();
    void notify(int r, int c, std::string value);
    friend std::ostream& operator<<(std::ostream &out, const TextBoard& myTextBoard);
};
#endif
