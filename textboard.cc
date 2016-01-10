//
//  textboard.cpp
//  myMatches
//
//  Created by H ghiassi on 2014-11-19.
//  Copyright (c) 2014 H ghiassi. All rights reserved.
//

#include "textboard.h"
using namespace std;
TextBoard::TextBoard(){
    int n = 10;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            tb[i][j] = "___";
        }
    }
}

void TextBoard::notify(int r, int c, string value){
    tb[r][c] = value;
}

ostream& operator<<(ostream &out, const TextBoard& myTextBoard){
    int n = 10;
    for (int i = 0;i < n; i++){
        for (int j = 0; j < n; j++){
            out<<myTextBoard.tb[i][j];
            if (j != 10){
                out<<" ";
            }
        }
        out<<endl;
    }
    return out;
}



