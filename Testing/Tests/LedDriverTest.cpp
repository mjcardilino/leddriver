#include "CppUTest/TestHarness.h"

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