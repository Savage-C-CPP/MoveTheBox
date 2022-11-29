#include "gtest/gtest.h"
#include "Box.hpp"

TEST(Box, Construct)
{
    ASSERT_NO_FATAL_FAILURE(Box b());
}

TEST(Box, MoveUp)
{
    Road r0(0, 0);
    Road r1(0, 80);
    Road r2(0, 160);
    Road r3(0, 240);

    Box b;
    b.SetPivot(&r2);

    // No way to move

    ASSERT_EQ(b.pivot, &r2);
    ASSERT_NO_FATAL_FAILURE(b.MoveUp());
    ASSERT_EQ(b.pivot, &r2);

    // Connect b's pivot with several roads so it can move on some of them

    r1.AddAdjecent(&r0);
    r1.AddAdjecent(&r2);
    r1.AddAdjecent(&r3);

    ASSERT_NO_FATAL_FAILURE(b.MoveUp());

    ASSERT_NE(b.pivot, &r0);
    ASSERT_NE(b.pivot, &r2);
    ASSERT_NE(b.pivot, &r3);
    ASSERT_EQ(b.pivot, &r1);

    // If there is an entity on the road b try to move on

    Box b2;
    b.SetPivot(&r2);
    b2.SetPivot(&r1);

    ASSERT_NE(b.pivot, &r1);
    ASSERT_EQ(b.pivot, &r2);

    ASSERT_NO_FATAL_FAILURE(b.MoveUp());
    ASSERT_NE(b.pivot, &r1);
    ASSERT_EQ(b.pivot, &r2);
}

TEST(Box, MoveRight)
{
    Road r0(0, 0);
    Road r1(80, 80);
    Road r2(80, 0);
    Road r3(160, 0);

    Box b;
    b.SetPivot(&r0);

    // No way to move

    ASSERT_EQ(b.pivot, &r0);
    ASSERT_NO_FATAL_FAILURE(b.MoveRight());
    ASSERT_EQ(b.pivot, &r0);

    // Connect b's pivot with several roads so it can move on some of them

    r0.AddAdjecent(&r1);
    r0.AddAdjecent(&r2);

    ASSERT_NO_FATAL_FAILURE(b.MoveRight());
    ASSERT_NE(b.pivot, &r0);
    ASSERT_NE(b.pivot, &r1);
    ASSERT_EQ(b.pivot, &r2);

    // If there is an entity on the road b try to move on

    Box b2;
    b2.SetPivot(&r3);

    r2.AddAdjecent(&r3);

    ASSERT_NO_FATAL_FAILURE(b.MoveRight());
    ASSERT_NE(b.pivot, &r3);
    ASSERT_EQ(b.pivot, &r2);
}

TEST(Box, MoveDown)
{
    Road r0(0, 0);
    Road r1(0, 80);
    Road r2(0, 160);
    Road r3(0, 240);

    Box b;
    b.SetPivot(&r2);

    ASSERT_EQ(b.pivot, &r2);
    ASSERT_NO_FATAL_FAILURE(b.MoveDown());
    ASSERT_EQ(b.pivot, &r2);

    r2.AddAdjecent(&r0);
    r2.AddAdjecent(&r1);
    r2.AddAdjecent(&r3);

    ASSERT_NO_FATAL_FAILURE(b.MoveDown());

    ASSERT_NE(b.pivot, &r0);
    ASSERT_NE(b.pivot, &r1);
    ASSERT_NE(b.pivot, &r2);
    ASSERT_EQ(b.pivot, &r3);

    // If there is an entity on the road b try to move on

    Box b2;
    b.SetPivot(&r2);
    b2.SetPivot(&r3);

    ASSERT_NE(b.pivot, &r3);
    ASSERT_EQ(b.pivot, &r2);

    ASSERT_NO_FATAL_FAILURE(b.MoveDown());
    ASSERT_NE(b.pivot, &r3);
    ASSERT_EQ(b.pivot, &r2);
}

TEST(Box, MoveLeft)
{
    Road r0(0, 0);
    Road r1(80, 80);
    Road r2(80, 0);
    Road r3(0, 80);

    Box b;
    b.SetPivot(&r2);

    // No way to move

    ASSERT_EQ(b.pivot, &r2);
    ASSERT_NO_FATAL_FAILURE(b.MoveLeft());
    ASSERT_EQ(b.pivot, &r2);

    // Connect b's pivot with several roads so it can move on some of them

    r0.AddAdjecent(&r1);
    r0.AddAdjecent(&r2);

    ASSERT_NO_FATAL_FAILURE(b.MoveLeft());
    ASSERT_NE(b.pivot, &r2);
    ASSERT_NE(b.pivot, &r1);
    ASSERT_EQ(b.pivot, &r0);

    // If there is an entity on the road b try to move on

    Box b2;
    b.SetPivot(&r1);
    b2.SetPivot(&r3);

    ASSERT_NE(b.pivot, &r0);
    ASSERT_EQ(b.pivot, &r1);

    r1.AddAdjecent(&r3);

    ASSERT_NO_FATAL_FAILURE(b.MoveLeft());
    ASSERT_NE(b.pivot, &r3);
    ASSERT_EQ(b.pivot, &r1);
}
