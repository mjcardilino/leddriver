#include "CppUTest/TestHarness.h"

extern "C"
{
#include "LedDriver.h"
#include "RuntimeErrorStub.h"
}

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver) 
{
   
}

TEST_TEAR_DOWN(LedDriver)
{
   
}

TEST(LedDriver, LedsOffAfterCreate)
{
   TEST_FAIL_MESSAGE("Start here");
}