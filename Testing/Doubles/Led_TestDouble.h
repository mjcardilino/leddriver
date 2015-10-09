#ifndef LED_TESTDOUBLE_H
#define LED_TESTDOUBLE_H

#include <stdbool.h>
#include <stdint.h>
#include "I_Led.h"

typedef struct
{
    I_Led_t interface;
    
    struct
    {
        bool *leds;
        uint8_t numberOfLeds;
    } _private;
} Led_TestDouble_t;

void Led_TestDouble_Init(
    Led_TestDouble_t *instance, 
    bool *leds, 
    uint8_t numberOfLeds);

#endif
