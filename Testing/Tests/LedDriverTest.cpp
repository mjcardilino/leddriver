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
#include "uassert_test.cpp"

TEST_GROUP(LedDriver)
{
   uint16_t virtualLeds;
   
   void setup()
   {
      LedDriver_Create(&virtualLeds);
   }

   void teardown()
   {
      LedDriver_Destroy();
   }
};

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

// Test to turn off specific LEDs
TEST(LedDriver, TurnOffAnyLed)
{
   LedDriver_TurnAllOn();
   LedDriver_TurnOff(8);
   LONGS_EQUAL(0xff7f, virtualLeds);
}

// Test that shows that the driver is not getting
// the current LED state from the hardware
TEST(LedDriver, LedMemoryIsNotReadable) 
{
   virtualLeds = 0xffff;
   LedDriver_TurnOn(8);
   LONGS_EQUAL(0x80, virtualLeds);
}

// Test boundary conditions
TEST(LedDriver, UpperAndLowerBounds) 
{
   LedDriver_TurnOn(1);
   LedDriver_TurnOn(16);
   LONGS_EQUAL(0x8001, virtualLeds);
}

// Test to handle out-of-bounds (for TurnOn situation)
TEST(LedDriver, OutOfBoundsTurnOn)
{
   CHECK_ASSERTION_FAILED(LedDriver_TurnOn(-1));
   CHECK_ASSERTION_FAILED(LedDriver_TurnOn(300));
}

// Test to handle out-of-bounds (for TurnOff situation)
TEST(LedDriver, OutOfBoundsTurnOff)
{
   CHECK_ASSERTION_FAILED(LedDriver_TurnOff(-1));
   CHECK_ASSERTION_FAILED(LedDriver_TurnOff(300));
}

// Test to check if LED is on
TEST(LedDriver, IsOn)
{
   CHECK_EQUAL(false, LedDriver_IsOn(11));
   LedDriver_TurnOn(11);
   CHECK_EQUAL(true, LedDriver_IsOn(11));
}

// Test to check if LED is off
TEST(LedDriver, IsOff)
{
   CHECK_EQUAL(true, LedDriver_IsOff(12));
   LedDriver_TurnOn(12);
   CHECK_EQUAL(false, LedDriver_IsOff(12));
}

// Test to turn off multiple LEDs
TEST(LedDriver, TurnOffMultipleLeds)
{
   LedDriver_TurnAllOn();
   LedDriver_TurnOff(9);
   LedDriver_TurnOff(8);
   LONGS_EQUAL((~0x180)&0xffff, virtualLeds);
}

// Test to turn off all LEDs
TEST(LedDriver, AllOff)
{
   LedDriver_TurnAllOn();
   LedDriver_TurnAllOff();
   LONGS_EQUAL(0, virtualLeds);
}