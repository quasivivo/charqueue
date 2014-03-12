//
//  CharQueueTest.cpp
//  CharQueue
//
//  Created by Will Hannah on 3/11/14.
//  Copyright (c) 2014 Will Hannah. All rights reserved.
//

#include "CharQueue1.h"
#include "CharQueue2.h"
#include "TestHarness.h"

TEST(megaPushPop, CharQueue2)
{
    CharQueue2 cq2(10000);
    for (int i=1; i < 9999; i++){
        cq2.pushChar(i%25+65);
    }
    
    // First item in is i=1, 1%25 = 1 + 65 = 66 = Ascii B
    // Next item in is i=2, Ascii C
    
    std::string  shouldBeA;
    shouldBeA.push_back(cq2.popChar());
    shouldBeA.push_back(cq2.popChar());
    
    CHECK_EQUAL("BC", shouldBeA);
}

TEST(pushPop, CharQueue2)
{
    CharQueue2 cq2(100);
    cq2.pushChar('A');
    cq2.pushChar('1');
    cq2.pushChar('3');
    cq2.pushChar('B');
    cq2.pushChar('Z');
    cq2.pushChar('5');
    cq2.pushChar('g');
    cq2.pushChar('~');
    
    std::string shouldBe;
    shouldBe.push_back(cq2.popChar());
    shouldBe.push_back(cq2.popChar());
    shouldBe.push_back(cq2.popChar());
    shouldBe.push_back(cq2.popChar());
    shouldBe.push_back(cq2.popChar());
    shouldBe.push_back(cq2.popChar());
    shouldBe.push_back(cq2.popChar());
    shouldBe.push_back(cq2.popChar());
    
    CHECK_EQUAL("A13BZ5g~", shouldBe);
}

TEST(pushPopEdge1, CharQueue2)
{
    CharQueue2 cq2(100);
    
    std::string shouldBeBlankChar;
    shouldBeBlankChar.push_back(cq2.popChar());
    
    // Empty charQueue pops will return a single space char
    
    CHECK_EQUAL(" ", shouldBeBlankChar);
}

TEST(pushPopEdge2, CharQueue2)
{
    CharQueue2 cq2(100);
    for (int i=0; i <=2000; i++){
        cq2.popChar();
        cq2.pushChar('J');
        cq2.popChar();
        cq2.pushChar('B');
        cq2.popChar();
        cq2.pushChar('Z');
    }

    std::string shouldBeZee;
    shouldBeZee.push_back(cq2.popChar());
    
    CHECK_EQUAL("Z", shouldBeZee);
}