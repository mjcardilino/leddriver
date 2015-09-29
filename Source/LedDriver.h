#ifndef LedDriver_H
#define LedDriver_H

#include <stdint.h>

void LedDriver_Create(uint16_t * address);
void LedDriver_Destroy(void);
void LedDriver_TurnOn(int ledNumber);

#endif