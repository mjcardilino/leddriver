/*!
 * @file
 * @brief Tests for Linked List module.
 *
 * Copyright (c) 2014 - General Electric - All rights reserved.
 */

extern "C"
{
#include "LedDriver.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "uassert_test.h"

TEST_GROUP(LedDriver)
{
   void setup()
   {
   }

   void teardown()
   {
   }
};

TEST(LedDriver, MyFirstTest)
{
   FAIL("My first test is running!");
}

#if(0)


#endif
