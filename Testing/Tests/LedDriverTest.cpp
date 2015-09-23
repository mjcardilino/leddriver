/*!
 * @file
 * @brief Tests for Linked List module.
 *
 * Copyright (c) 2014 - General Electric - All rights reserved.
 */

extern "C"
{
#include "LinkedList.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "uassert_test.h"

TEST_GROUP(LinkedList)
{
   LinkedList_t instance;

   void setup()
   {
   }

   void teardown()
   {
   }
};

TEST(LinkedList, MyFirstTest)
{
   FAIL("My first test is running!");
}

#if(0)
TEST(LinkedList, EmptyAfterInit)
{
   LinkedList_Init(&instance);

   CHECK(0 == LinkedList_Count(&instance));
}

TEST(LinkedList, CountIncreasesAfterPushFront)
{
   LinkedListNode_t node;

   LinkedList_Init(&instance);
   LinkedList_PushFront(&instance, &node);

   CHECK(1 == LinkedList_Count(&instance));
}

TEST(LinkedList, CountIncreasesAfterPushBack)
{

}

TEST(LinkedList, PopBackRemovesAndReturnsTheLastElementInTheList)
{

}

TEST(LinkedList, PopFrontRemovesAndReturnsTheFirstElementInTheList)
{

}

TEST(LinkedList, CountDecreasesWhenAnElementIsPoppedFromTheFrontOfAList)
{

}

TEST(LinkedList, CountDecreasesWhenAnElementIsPoppedFromTheBackOfAList)
{

}

TEST(LinkedList, CountDecreasesWhenANodeIsRemoved)
{

}

TEST(LinkedList, CanRemoveNodeThatIsntInList)
{
   LinkedListNode_t node;

   LinkedList_Init(&instance);
   LinkedList_Remove(&instance, &node);
}

IGNORE_TEST(LinkedList, CannotAddNodeThatIsAlreadyInTheList)
{
   LinkedListNode_t node;

   LinkedList_Init(&instance);
   LinkedList_PushFront(&instance, &node);
   CHECK_ASSERTION_FAILED(LinkedList_PushFront(&instance, &node));
   CHECK_ASSERTION_FAILED(LinkedList_PushBack(&instance, &node));
}

TEST(LinkedList, CountIsUpdatedCorrectlyAfterAddingMultipleNodes)
{

}

TEST(LinkedList, CanGetTheNodeAtAnIndex)
{

}
#endif
