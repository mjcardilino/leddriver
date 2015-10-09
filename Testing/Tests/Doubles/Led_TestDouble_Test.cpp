extern "C"
{
#include "Led_TestDouble.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "uassert_test.h"

enum
{
    Led1,
    Led2,
    Led3,
    LedCount
};

TEST_GROUP(LedTestDouble)
{
   Led_TestDouble_t testDoubleInstance;
   I_Led_t *ledInstance;
   bool leds[LedCount];
   
   void setup()
   {
      ledInstance = &testDoubleInstance.interface;
   }
   
   void GivenTheLedTestDoubleIsInitialized()
   {
      Led_TestDouble_Init(&testDoubleInstance, leds, LedCount);
   }
   
   void WhenLedIsTurnedOn(LedId_t led)
   {
      // To use the interface we just pass our I_Led instance reference
      // to the macro that really just calls the api method of the test double.
      // The macro just beautifies the call making it look like a straight function call.
      // If I were to design a component I would have it always interact with an I_Led and not
      // have to know what is actually behind the interface (test double or hardware)
      Led_TurnOn(ledInstance, led);
   }
   
   void LedShouldBeOn(LedId_t led)
   {
      CHECK_EQUAL(true, leds[led]);
   }
};

TEST(LedTestDouble, ShouldBeAbleToTurnOnAnLed)
{
    GivenTheLedTestDoubleIsInitialized();
    
    WhenLedIsTurnedOn(Led1);
    LedShouldBeOn(Led1);
}

TEST(LedTestDouble, ShouldAssertNoNullPointers)
{
  CHECK_ASSERTION_FAILED(Led_TestDouble_Init(NULL, leds, 3))
  CHECK_ASSERTION_FAILED(Led_TestDouble_Init(&testDoubleInstance, NULL, 3))
}