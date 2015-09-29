/*!
 * @file
 * @brief Tests for LedDriver module.
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
   uint16_t virtualLeds;
   
   void setup()
   {
   }

   void teardown()
   {
   }
};

#if 0
// My first test
TEST(LedDriver, MyFirstTest)
{
   FAIL("My first test is running!");
}
#endif

// Test that LEDs are initialized correctly
TEST(LedDriver, LedsOffAfterCreate) 
{
   virtualLeds = 0xffff;
   LedDriver_Create(&virtualLeds);
   LONGS_EQUAL(0, virtualLeds);
}