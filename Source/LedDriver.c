#include "LedDriver.h"
#include "uassert.h"

static uint16_t * ledAddress;
static uint16_t ledImage;

enum 
{
    AllLedsOn = ~0, 
    AllLedsOff = ~AllLedsOn
};

enum 
{
    FirstLed = 1, 
    LastLed = 16 
};

static bool LedIsOutOfBounds(LedNumber_t ledNumber)
{
    return ((ledNumber < FirstLed) || (ledNumber > LastLed));
}

static uint16_t ConvertLedNumberToBit(LedNumber_t ledNumber)
{
    return 1 << (ledNumber - 1);
}

static void UpdateHardware(void) 
{
    *ledAddress = ledImage;
}

void LedDriver_Create(uint16_t * address) 
{
    ledAddress = address;
    ledImage = AllLedsOff;
    UpdateHardware();
}

void LedDriver_Destroy(void)
{
    ledImage = AllLedsOff;
    UpdateHardware();
}

static void SetLedImageBit(LedNumber_t ledNumber)
{
    ledImage |= ConvertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOn(LedNumber_t ledNumber)
{
    uassert(!LedIsOutOfBounds(ledNumber));

    SetLedImageBit(ledNumber);
    UpdateHardware();
}

static void ClearLedImageBit(LedNumber_t ledNumber)
{
    ledImage &= ~ConvertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(LedNumber_t ledNumber)
{
    uassert(!LedIsOutOfBounds(ledNumber));
    
    if(!LedIsOutOfBounds(ledNumber))
    {
        ClearLedImageBit(ledNumber);
        UpdateHardware();
    }
}

void LedDriver_TurnAllOn(void)
{
    ledImage = AllLedsOn;
    UpdateHardware();
}

bool LedDriver_IsOn(LedNumber_t ledNumber)
{
    if (LedIsOutOfBounds(ledNumber))
    {
        return false;
    }
    else
    {
        return ledImage && (ConvertLedNumberToBit(ledNumber));
    }
}

bool LedDriver_IsOff(LedNumber_t ledNumber)
{
    return !LedDriver_IsOn(ledNumber);
}

void LedDriver_TurnAllOff(void)
{
    ledImage = AllLedsOff;
    UpdateHardware();
}