/*! \file uassert_test.h
 \brief User-defined assert mechanism

 Copyright (c) 2013 - General Electric - All rights reserved.
 */

#ifndef UASSERT_TEST_H_
#define UASSERT_TEST_H_

#define CHECK_ASSERTION_FAILED(code) \
   uassert_ExpectAssertion(); \
   try { code; } catch(...) { } \
   CHECK(uassert_Asserted())

extern void uassert_ExpectAssertion(void);
extern bool uassert_Asserted(void);

#endif /* UASSERT_TEST_H_ */
