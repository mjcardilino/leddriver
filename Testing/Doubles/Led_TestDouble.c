#include "Led_TestDouble.h"
#include "uassert.h"

static void TurnOn(I_Led_t *_instance, LedId_t led)
{
    Led_TestDouble_t *instance = (Led_TestDouble_t *)_instance;
    
    instance->_private.leds[led] = true;
}

static void TurnOff(I_Led_t *_instance, LedId_t led)
{
    
}

static bool IsOn(I_Led_t *_instance, LedId_t led)
{
    return false;
}

static const I_Led_Api_t api = 
{ TurnOn, TurnOff, IsOn };

void Led_TestDouble_Init(
    Led_TestDouble_t *instance, 
    bool *leds, 
    uint8_t numberOfLeds)
{
    // Verify that nobody is passing in NULL pointers
    uassert(instance);
    uassert(leds);
    
    // We now plug our implementation of the I_Led api into the api.
    // This means when someone uses this module as an I_Led and calls
    // one of the api functions it will route to one of the methods above.
    // This approach lets us replace real concrete objects with test doubles/mocks
    // to make testing easier.
    instance->interface.api = &api;
    
    // This instance is given a reference to a buffer representing the led states
    // This approach allows us to have more than one "instance" of the test double.  If we declared
    // the led buffer as a local static variable we could only support one.
    instance->_private.leds = leds;
    instance->_private.numberOfLeds = numberOfLeds;
}