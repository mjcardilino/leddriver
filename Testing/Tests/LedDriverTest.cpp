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
   
   void GivenThatAllLedsAreOn()
   {
      virtualLeds = 0xffff;
   }
   
   void WhenLedsAreCreated()
   {
      LedDriver_Create(&virtualLeds);
   }
   
   void AllLedsShouldBeOff()
   {
      LONGS_EQUAL(0, virtualLeds);
   }
   
   void AllLedsShouldBeOn()
   {
      LONGS_EQUAL(0xffff, virtualLeds);
   }
   
   void GivenLedIsOn(int ledNumber)
   {
      LedDriver_TurnOn(ledNumber);
   }
   
   void WhenValidLedIsTurnedOff(int ledNumber)
   {
      LedDriver_TurnOff(ledNumber);
   }
   
   void WhenInvalidLedIsTurnedOn(int ledNumber)
   {
      LedDriver_TurnOn(ledNumber);
   }
   
   void WhenInvalidLedIsTurnedOff(int ledNumber)
   {
      LedDriver_TurnOff(ledNumber);
   }
   
   void CorrectLedsShouldBeOn(uint16_t value)
   {
      LONGS_EQUAL(value, virtualLeds);
   }
   
   void WhenAllLedsAreTurnedOn() 
   {
      LedDriver_TurnAllOn();
   }
   
   void WhenAllLedsAreTurnedOff()
   {
      LedDriver_TurnAllOff();
   }
   
   void LedIsOff(int ledNumber)
   {
      CHECK_EQUAL(true, LedDriver_IsOff(ledNumber));
   }
   
   void LedIsOn(int ledNumber)
   {
      CHECK_EQUAL(true, LedDriver_IsOn(ledNumber));
   }
   
   void GivenLedIsOff(int ledNumber)
   {
      LedDriver_TurnOff(ledNumber);
   }

};

TEST(LedDriver, LedsShouldBeOffAfterCreate) 
{
   GivenThatAllLedsAreOn();
   WhenLedsAreCreated();
   AllLedsShouldBeOff();
}

TEST(LedDriver, Led01ShouldTurnOn)
{
   GivenLedIsOn(1);
   CorrectLedsShouldBeOn(1);
}

TEST(LedDriver, Led01ShouldTurnOff)
{
   GivenLedIsOn(1);
   WhenValidLedIsTurnedOff(1);
   AllLedsShouldBeOff();
}

TEST(LedDriver, MultipleLedsShouldTurnOn) 
{
   GivenLedIsOn(9);
   GivenLedIsOn(8);
   CorrectLedsShouldBeOn(0x180);
}

TEST(LedDriver, AllLedsShouldTurnOn) 
{
   WhenAllLedsAreTurnedOn();
   AllLedsShouldBeOn();
}

TEST(LedDriver, ShouldTurnOffAnyLed)
{
   WhenAllLedsAreTurnedOn();
   WhenValidLedIsTurnedOff(8);
   CorrectLedsShouldBeOn(0xff7f);
}

TEST(LedDriver, LedMemoryShouldNotBeReadable) 
{
   GivenThatAllLedsAreOn();
   GivenLedIsOn(8);
   CorrectLedsShouldBeOn(0x80);
}

TEST(LedDriver, UpperAndLowerBoundsShouldTurnOn) 
{
   GivenLedIsOn(1);
   GivenLedIsOn(16);
   CorrectLedsShouldBeOn(0x8001);
}

TEST(LedDriver, TurnOnOutOfBoundsShouldFail)
{
   CHECK_ASSERTION_FAILED(WhenInvalidLedIsTurnedOn(-1));
   CHECK_ASSERTION_FAILED(WhenInvalidLedIsTurnedOn(300));
}

TEST(LedDriver, TurnOffOutOfBoundsShouldFail)
{
   CHECK_ASSERTION_FAILED(WhenInvalidLedIsTurnedOff(-1));
   CHECK_ASSERTION_FAILED(WhenInvalidLedIsTurnedOff(300));
}

TEST(LedDriver, ShouldNotReportTheWrongLedIsOn)
{
   GivenLedIsOn(2);
   LedIsOff(3);
}

TEST(LedDriver, ShouldBeAbleToCheckIfAnLedIsOn)
{
   GivenLedIsOff(11);
   GivenLedIsOn(11);
   LedIsOn(11);
}

TEST(LedDriver, ShouldBeAbleToCheckIfAnLedIsOff)
{
   GivenLedIsOn(12);
   GivenLedIsOff(12);
   LedIsOff(12);
}

TEST(LedDriver, MultipleLedsShouldTurnOff)
{
   WhenAllLedsAreTurnedOn();
   WhenValidLedIsTurnedOff(9);
   WhenValidLedIsTurnedOff(8);
   CorrectLedsShouldBeOn((~0x180)&0xffff);
}

TEST(LedDriver, AllLedsShouldTurnOff)
{
   WhenAllLedsAreTurnedOn();
   WhenAllLedsAreTurnedOff();
   AllLedsShouldBeOff();
}