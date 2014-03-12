//
//  CharQueue2.cpp
//  CharQueue
//
//  Created by Will Hannah on 3/11/14.
//  Copyright (c) 2014 Will Hannah. All rights reserved.
//

#include "CharQueue2.h"

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
    } else if (filledCount != strlen(queue)) {
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

void CharQueue2::printQueue() {
    std::cout << filledCount << " items in the array." << std::endl;
    for (int i=0; i<filledCount; i++) {
        std::cout << i << ": " << queue[i] << std::endl;
    }
}

CharQueue2::~CharQueue2() {
    delete [] queue;
}