#ifndef I_LED_H
#define I_LED_H

#include <stdbool.h>
#include <stdint.h>

typedef uint8_t LedId_t;

struct I_Led_Api_t;

typedef struct
{
   const struct I_Led_Api_t *api;
} I_Led_t;

typedef struct I_Led_Api_t
{
   void (*TurnOn)(I_Led_t *instance, LedId_t led);
   void (*TurnOff)(I_Led_t *instance, LedId_t led);
   bool (*IsOn)(I_Led_t *instance, LedId_t led);
} I_Led_Api_t;

#define Led_TurnOn(instance, led) \
   (instance)->api->TurnOn((instance), (led))
   
#define Led_TurnOff(instance, led) \
   (instance)->api->TurnOff((instance), (led))
   
#define Led_IsOn(instance, led) \
   (instance)->api->IsOn((instance), (led))
   
#endif