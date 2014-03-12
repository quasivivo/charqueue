//
//  CharQueue1.h
//  CharQueue
//
//  Created by Will Hannah on 3/9/14.
//  Copyright (c) 2014 Will Hannah. All rights reserved.
//

#ifndef __CharQueue__CharQueue1__
#define __CharQueue__CharQueue1__

#include <iostream>
#include <deque>

class CharQueue1
{
private:
    std::deque<char> queue;
    
public:
    friend std::ostream& operator<< (std::ostream& o, CharQueue1 const& cq1);
    CharQueue1(const long maxQueueSize);
    void pushChar(const char input);
    char popChar();
    void printQueue();
};

#endif /* defined(__CharQueue__CharQueue1__) */
