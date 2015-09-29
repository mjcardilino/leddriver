/*! \file uassert.cpp
 \brief User-defined assert implementation for TDD

 Copyright (c) 2013 - General Electric - All rights reserved.
 */

#include <stdexcept>

typedef struct
{
   bool asserted;
} Module_t;

static Module_t module;

extern "C" void __uassert_func(const char * fileName, const int lineNumber,
   const bool condition, const char *conditionString)
{
   (void) fileName;
   (void) lineNumber;
   (void) conditionString;

   if(!condition)
   {
      module.asserted = true;
      throw std::runtime_error("assertion failed");
   }
}

void uassert_ExpectAssertion(void)
{
   module.asserted = false;
}

bool uassert_Asserted(void)
{
   return module.asserted;
}
