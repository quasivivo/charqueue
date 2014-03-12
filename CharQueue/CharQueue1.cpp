//
//  CharQueue1.cpp
//  CharQueue
//
//  Created by Will Hannah on 3/9/14.
//  Copyright (c) 2014 Will Hannah. All rights reserved.
//

#include "CharQueue1.h"
#include <sstream>

std::ostream& operator<< (std::ostream& o, CharQueue1 const& cq1) {
    std::stringstream retVal;
    retVal << cq1.queue.size() << " items in the array." << std::endl;
    
    for (int i=0; i<cq1.queue.size(); i++) {
        retVal << i << ": " << cq1.queue[i] << std::endl;
    }
    return o << retVal.str();
}

CharQueue1::CharQueue1(const long maxQueueSize) {
    std::deque<char> queue(maxQueueSize,' ');
}

void CharQueue1::pushChar(const char input) {
    queue.push_front(input);
}

char CharQueue1::popChar() {
    char returnChar = ' ';
    if (queue.size() != 0) {
        returnChar = queue.back();
        queue.pop_back();
    }
    
    return returnChar;
}

void CharQueue1::printQueue() {
    std::cout << queue.size() << " items in the array." << std::endl;
    for (int i=0; i<queue.size(); i++) {
        std::cout << i << ": " << queue.at(i) << std::endl;
    }
}
