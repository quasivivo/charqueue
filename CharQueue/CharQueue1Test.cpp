//
//  CharQueueTest.cpp
//  CharQueue
//
//  Created by Will Hannah on 3/9/14.
//  Copyright (c) 2014 Will Hannah. All rights reserved.
//

#include "CharQueue1.h"
#include "TestHarness.h"

// CharQueue1 tests
TEST(megaPushPop, CharQueue1)
{
    CharQueue1 cq1(10000);
    for (int i=1; i < 9999; i++){
        cq1.pushChar(i%25+65);
    }
    
    // First item in was i=1, 1%25 = 1 + 65 = 66 = Ascii B
    // Next item in was i=2, Ascii C
    
    std::string shouldBeBeeCee;
    shouldBeBeeCee.push_back(cq1.popChar());
    shouldBeBeeCee.push_back(cq1.popChar());
    
    CHECK_EQUAL("BC", shouldBeBeeCee);
}

TEST(pushPop, CharQueue1)
{
    CharQueue1 cq1(100);
    cq1.pushChar('A');
    cq1.pushChar('1');
    cq1.pushChar('3');
    cq1.pushChar('B');
    cq1.pushChar('Z');
    cq1.pushChar('5');
    cq1.pushChar('g');
    cq1.pushChar('~');
    
    // std::cout << cq1 << std::endl;
    
    std::string shouldBe;
    shouldBe.push_back(cq1.popChar());
    shouldBe.push_back(cq1.popChar());
    shouldBe.push_back(cq1.popChar());
    shouldBe.push_back(cq1.popChar());
    shouldBe.push_back(cq1.popChar());
    shouldBe.push_back(cq1.popChar());
    shouldBe.push_back(cq1.popChar());
    shouldBe.push_back(cq1.popChar());
    
    CHECK_EQUAL("A13BZ5g~", shouldBe);
}

TEST(pushPopEdge1, CharQueue1)
{
    CharQueue1 cq1(100);
    
    std::string shouldBeBlankChar;
    shouldBeBlankChar.push_back(cq1.popChar());
    
    // Empty charQueue pops will return a single space char
    
    CHECK_EQUAL(" ", shouldBeBlankChar);
}

TEST(pushPopEdge2, CharQueue1)
{
    CharQueue1 cq1(100);
    for (int i=0; i <=2000; i++){
        cq1.popChar();
        cq1.pushChar('J');
        cq1.popChar();
        cq1.pushChar('B');
        cq1.popChar();
        cq1.pushChar('Z');
    }
    
    std::string shouldBeZee;
    shouldBeZee.push_back(cq1.popChar());
    
    CHECK_EQUAL("Z", shouldBeZee);
}