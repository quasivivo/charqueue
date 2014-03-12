//
//  CharQueue2.h
//  CharQueue
//
//  Created by Will Hannah on 3/9/14.
//  Copyright (c) 2014 Will Hannah. All rights reserved.
//

#ifndef __CharQueue__CharQueue2__
#define __CharQueue__CharQueue2__

#include <iostream>

class CharQueue2
{
private:
    char *queue;
    int filledCount;
    
public:
    friend std::ostream& operator<< (std::ostream& o, CharQueue2 const& cq2);
    CharQueue2(const long maxQueueSize);
    ~CharQueue2();
    void pushChar(const char input);
    char popChar();
};

#endif /* defined(__CharQueue__CharQueue2__) */
