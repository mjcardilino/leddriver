/*!
 * @file
 * @brief User-defined assert mechanism
 *
 * Copyright (c) 2013 - General Electric - All rights reserved.
 */

#ifndef UASSERT_H_
#define UASSERT_H_

#include <stdbool.h>

#define uassert(condition) __uassert_func(__FILE__, __LINE__, (bool)(!!(condition)), #condition)

extern void __uassert_func(const char * fileName, int lineNumber, bool condition, const char *conditionString);

#endif