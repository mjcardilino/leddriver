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
      LedDriver_Create(&virtualLeds);
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

// Test that LED 01 is turned on
TEST(LedDriver, TurnOnLedOne)
{
   LedDriver_TurnOn(1);
   LONGS_EQUAL(1, virtualLeds);
}

// Test that LED 01 is turned off
TEST(LedDriver, TurnOffLedOne)
{
   LedDriver_TurnOn(1);
   LedDriver_TurnOff(1);
   LONGS_EQUAL(0, virtualLeds);
}

// Test to turn on multiple LEDS
TEST(LedDriver, TurnOnMultLeds) 
{
   LedDriver_TurnOn(9);
   LedDriver_TurnOn(8);
   LONGS_EQUAL(0x180, virtualLeds);
}

// Test to turn on all LEDs
TEST(LedDriver, AllOn) 
{
   LedDriver_TurnAllOn();
   LONGS_EQUAL(0xffff, virtualLeds);
}

#if 0
// Test to turn off specific LEDs
TEST(LedDriver, TurnOffAnyLed)
{
   LedDriver_TurnOn(9);
   LedDriver_TurnOn(8);
   LedDriver_TurnOff(8);
   LONGS_EQUAL(0x100, virtualLeds);
}
#endif