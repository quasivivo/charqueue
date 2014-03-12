//
//  CharQueueCombinedTest.cpp
//  CharQueue
//
//  Created by Will Hannah on 3/12/14.
//  Copyright (c) 2014 Will Hannah. All rights reserved.
//

#include "CharQueue1.h"
#include "CharQueue2.h"
#include "TestHarness.h"
#include <sstream>

TEST(megaPushPop, CharQueue)
{
    CharQueue1 cq1(10000);
    CharQueue2 cq2(10000);
    for (int i=1; i < 9999; i++){
        cq1.pushChar(i%25+65);
        cq2.pushChar(i%25+65);
    }
    
    // First item in is i=1, 1%25 = 1 + 65 = 66 = Ascii B
    // Both charQueues should return the same char, B.
    
    CHECK_EQUAL(cq1.popChar(), cq2.popChar());
}

TEST(ostreamCompare, CharQueue)
{
    std::stringstream compareCQ1;
    std::stringstream compareCQ2;

    CharQueue1 cq1(10000);
    CharQueue2 cq2(10000);
    for (int i=1; i < 9999; i++){
        cq1.pushChar(i%25+65);
        cq2.pushChar(i%25+65);
    }
    
    compareCQ1 << cq1;
    compareCQ2 << cq2;
    
    CHECK_EQUAL(compareCQ1.str(), compareCQ2.str());
}