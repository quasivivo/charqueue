//
//  CharQueue2.cpp
//  CharQueue
//
//  Created by Will Hannah on 3/11/14.
//  Copyright (c) 2014 Will Hannah. All rights reserved.
//

#include "CharQueue2.h"

void CharQueue2::pushChar(const char input) {
    tmpQueue = input + charQueue;

    charQueue = tmpQueue;
}

char CharQueue2::popChar() {
    if (sizeof(charQueue) >= 1) {
        const unsigned long newLength = (sizeof(charQueue)-1);
        std::array<char,newLength> newCharQueue;
        for (int i=0; i<newLength; i++) {
            newCharQueue[i] = charQueue[i];
        }
        return charQueue[sizeof(charQueue)];
    }
    return ' ';
}

CharQueue2::~CharQueue2() {
}