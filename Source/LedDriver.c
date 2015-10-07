#include "LedDriver.h"
#include "uassert.h"

static uint16_t * ledAddress;
static uint16_t ledImage;

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 1, LAST_LED = 16 };

static BOOL IsLedOutOfBounds(int ledNumber)
{
    return(ledNumber < FIRST_LED) || (ledNumber > LAST_LED);
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

static void updateHardware(void) 
{
    *ledAddress = ledImage;
}

void LedDriver_Create(uint16_t * address) 
{
    ledAddress = address;
    ledImage = ALL_LEDS_OFF;
    updateHardware();
}

void LedDriver_Destroy(void)
{
}

static void setLedImageBit(int ledNumber)
{
    ledImage |= convertLedNumberToBit(ledNumber);
}
void LedDriver_TurnOn(int ledNumber)
{
    if(IsLedOutOfBounds(ledNumber))
    {
        return;
    }
    
    setLedImageBit(ledNumber);
    updateHardware();
}

static void clearLedImageBit(int ledNumber)
{
    ledImage &= ~convertLedNumberToBit(ledNumber);
}
void LedDriver_TurnOff(int ledNumber)
{
    if(IsLedOutOfBounds(ledNumber))
        return;
        
    clearLedImageBit(ledNumber);
    updateHardware();
}

void LedDriver_TurnAllOn(void)
{
    ledImage = ALL_LEDS_ON;
    updateHardware();
}

BOOL LedDriver_IsOn(int ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
        return FALSE;
        
    return ledImage && (convertLedNumberToBit(ledNumber));
}

BOOL LedDriver_IsOff(int ledNumber)
{
    return !LedDriver_IsOn(ledNumber);
}

void LedDriver_TurnAllOff(void)
{
    ledImage = ALL_LEDS_OFF;
    updateHardware();
}