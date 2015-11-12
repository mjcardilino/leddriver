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

TEST(LedDriver, LedsShouldBeOffAfterCreate) 
{
   virtualLeds = 0xffff;
   LedDriver_Create(&virtualLeds);
   LONGS_EQUAL(0, virtualLeds);
}

TEST(LedDriver, Led01ShouldTurnOn)
{
   LedDriver_TurnOn(1);
   LONGS_EQUAL(1, virtualLeds);
}

TEST(LedDriver, Led01ShouldTurnOff)
{
   LedDriver_TurnOn(1);
   LedDriver_TurnOff(1);
   LONGS_EQUAL(0, virtualLeds);
}

TEST(LedDriver, MultLedsShouldTurnOn) 
{
   LedDriver_TurnOn(9);
   LedDriver_TurnOn(8);
   LONGS_EQUAL(0x180, virtualLeds);
}

TEST(LedDriver, AllLedsShouldTurnOn) 
{
   LedDriver_TurnAllOn();
   LONGS_EQUAL(0xffff, virtualLeds);
}

TEST(LedDriver, ShouldTurnOffAnyLed)
{
   LedDriver_TurnAllOn();
   LedDriver_TurnOff(8);
   LONGS_EQUAL(0xff7f, virtualLeds);
}

TEST(LedDriver, LedMemoryShoudlNotBeReadable) 
{
   virtualLeds = 0xffff;
   LedDriver_TurnOn(8);
   LONGS_EQUAL(0x80, virtualLeds);
}

TEST(LedDriver, UpperAndLowerBoundsShouldTurnOn) 
{
   LedDriver_TurnOn(1);
   LedDriver_TurnOn(16);
   LONGS_EQUAL(0x8001, virtualLeds);
}

TEST(LedDriver, TurnOnOutOfBoundsShouldFail)
{
   CHECK_ASSERTION_FAILED(LedDriver_TurnOn(-1));
   CHECK_ASSERTION_FAILED(LedDriver_TurnOn(300));
}

TEST(LedDriver, TurnOffOutOfBoundsShouldFail)
{
   CHECK_ASSERTION_FAILED(LedDriver_TurnOff(-1));
   CHECK_ASSERTION_FAILED(LedDriver_TurnOff(300));
}

TEST(LedDriver, LedShouldBeOn)
{
   CHECK_EQUAL(false, LedDriver_IsOn(11));
   LedDriver_TurnOn(11);
   CHECK_EQUAL(true, LedDriver_IsOn(11));
}

TEST(LedDriver, LedShouldBeOff)
{
   CHECK_EQUAL(true, LedDriver_IsOff(12));
   LedDriver_TurnOn(12);
   CHECK_EQUAL(false, LedDriver_IsOff(12));
}

TEST(LedDriver, MultLedsShouldTurnOff)
{
   LedDriver_TurnAllOn();
   LedDriver_TurnOff(9);
   LedDriver_TurnOff(8);
   LONGS_EQUAL((~0x180)&0xffff, virtualLeds);
}

TEST(LedDriver, AllLedsShouldTurnOff)
{
   LedDriver_TurnAllOn();
   LedDriver_TurnAllOff();
   LONGS_EQUAL(0, virtualLeds);
}