#include "CppUTest/TestHarness.h"

extern "C"
{
#include "Source/LedDriver.h"
}

TEST_GROUP(LedDriver) 
{
    void setup() 
    {
        LedDriver_Create();
    }
    
};

TEST(LedDriver, Create)
{
    FAIL("Start here");
}