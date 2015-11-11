#ifndef LedDriver_H
#define LedDriver_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t LedNumber_t;

void LedDriver_Create(uint16_t * address);
void LedDriver_Destroy(void);
void LedDriver_TurnOn(LedNumber_t ledNumber);
void LedDriver_TurnOff(LedNumber_t ledNumber);
void LedDriver_TurnAllOn(void);
bool LedDriver_IsOn(LedNumber_t ledNumber);
bool LedDriver_IsOff(LedNumber_t ledNumber);
void LedDriver_TurnAllOff(void);
void LedDriver_RuntimeError(LedNumber_t ledNumber);

#endif