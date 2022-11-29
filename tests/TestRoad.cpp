#include "gtest/gtest.h"
#include "Road.hpp"
#include "Box.hpp"
#include "Player.hpp"

TEST(Road, Construct)
{
    ASSERT_NO_FATAL_FAILURE(Road r);
    ASSERT_NO_FATAL_FAILURE(Road r(0, 0));
    ASSERT_NO_FATAL_FAILURE(Road r(-0, -0));
    ASSERT_NO_FATAL_FAILURE(Road r(123456, 123456));
}

TEST(Road, AddAdjecent)
{
    Road r0(81 * 0, 0);
    Road r1(81 * 1, 0);
    Road r2(81 * 2, 0);

    ASSERT_NO_FATAL_FAILURE(r0.AddAdjecent(&r1));
    ASSERT_NO_FATAL_FAILURE(r1.AddAdjecent(&r2));
    ASSERT_NO_FATAL_FAILURE(r2.AddAdjecent(&r0));
}

TEST(Road, IsAdjecent)
{
    Road r0(81 * 0, 0);
    Road r1(81 * 1, 0);
    Road r2(81 * 2, 0);
    Road r3(81 * 3, 0);
    Road r4(81 * 4, 0);

    r0.AddAdjecent(&r1);
    r1.AddAdjecent(&r2);
    r2.AddAdjecent(&r3);
    r3.AddAdjecent(&r4);
    r4.AddAdjecent(&r0);

    ASSERT_TRUE(r0.IsAdjecent(r1.crd.x, r1.crd.y));
    ASSERT_TRUE(r1.IsAdjecent(r0.crd.x, r0.crd.y));

    ASSERT_TRUE(r1.IsAdjecent(r2.crd.x, r2.crd.y));
    ASSERT_TRUE(r2.IsAdjecent(r1.crd.x, r1.crd.y));

    ASSERT_TRUE(r4.IsAdjecent(r0));
    ASSERT_TRUE(r0.IsAdjecent(r4));

    ASSERT_FALSE(r2.IsAdjecent(r0));
    ASSERT_FALSE(r2.IsAdjecent(r4));
}

TEST(Road, GetAdjecent)
{
    Road r0(0, 0);
    Road r1(100, 100);
    Road r2(200, 200);
    Road r3(300, 300);
    Road r4(400, 400);

    r0.AddAdjecent(&r1);
    r0.AddAdjecent(&r2);
    r0.AddAdjecent(&r3);
    r0.AddAdjecent(&r4);

    ASSERT_NE(r0.GetAdjecent(300, 300), nullptr);
    ASSERT_EQ(r0.GetAdjecent(300, 300), &r3);
}

TEST(Road, SetEntity)
{
    Road r(0, 0);

    Box b;
    void *entity = static_cast<void *>(&b);

    ASSERT_NO_FATAL_FAILURE(r.SetEntity(entity));
}

TEST(Road, RemoveEntity)
{
    Road r(0, 0);

    ASSERT_NO_FATAL_FAILURE(r.RemoveEntity());

    Box b;
    void *entity = static_cast<void *>(&b);
    r.SetEntity(entity);

    ASSERT_NO_FATAL_FAILURE(r.RemoveEntity());
}

TEST(Road, HasEntity)
{
    Road r(0, 0);

    ASSERT_FALSE(r.HasEntity());

    Box b;
    void *entity = static_cast<void *>(&b);
    r.SetEntity(entity);

    ASSERT_TRUE(r.HasEntity());

    r.RemoveEntity();
    ASSERT_FALSE(r.HasEntity());
}
