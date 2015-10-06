#ifndef LedDriver_H
#define LedDriver_H

#include <stdint.h>
#include <stdbool.h>

void LedDriver_Create(uint16_t * address);
void LedDriver_Destroy(void);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn(void);

#endif