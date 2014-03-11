//
//  CharQueue1.h
//  CharQueue
//
//  Created by Will Hannah on 3/11/14.
//  Copyright (c) 2014 Will Hannah. All rights reserved.
//

#ifndef __CharQueue__CharQueue1__
#define __CharQueue__CharQueue1__

#include <iostream>
#include <deque>

class CharQueue1
{
private:
    std::deque<char> charQueue;
    
public:
    CharQueue1();
    void pushChar(const char input);
    char popChar();
};

#endif /* defined(__CharQueue__CharQueue1__) */
