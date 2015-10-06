#ifndef LedDriver_H
#define LedDriver_H

#include <stdint.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

void LedDriver_Create(uint16_t * address);
void LedDriver_Destroy(void);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn(void);
BOOL LedDriver_IsOn(int ledNumber);

#endif