//
//  CharQueue2.cpp
//  CharQueue
//
//  Created by Will Hannah on 3/9/14.
//  Copyright (c) 2014 Will Hannah. All rights reserved.
//

#include "CharQueue2.h"
#include <sstream>

std::ostream& operator<< (std::ostream& o, CharQueue2 const& cq2) {
    std::stringstream retVal;
    retVal << cq2.filledCount << " items in the array." << std::endl;
    
    for (int i=0; i<cq2.filledCount; i++) {
        retVal << i << ": " << cq2.queue[i] << std::endl;
    }
    return o << retVal.str();
}

CharQueue2::CharQueue2(const long maxQueueSize) {
    queue = new char[maxQueueSize];
    filledCount = 0;
    for (int i=0; i<maxQueueSize-1; i++) {
        queue[i] = ' ';
    }
    queue[maxQueueSize-1] = '\0';
}

void CharQueue2::pushChar(const char input) {
    if (!filledCount) {
        queue[0] = input;
        filledCount++;
    } else {
        for (int i=filledCount+1; i>=1; i--) {
            queue[i] = queue[i-1];
        }
        queue[0] = input;
        filledCount++;
    }
}

char CharQueue2::popChar() {
    char returnChar = ' ';
    
    if (filledCount) {
        returnChar = queue[filledCount-1];
        filledCount--;
    }
    
    return returnChar;
}

CharQueue2::~CharQueue2() {
    delete [] queue;
}