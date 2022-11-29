#include "gtest/gtest.h"
#include "Player.hpp"
#include "Box.hpp"

TEST(Player, Construct)
{
    ASSERT_NO_FATAL_FAILURE(Player p());
}

TEST(Player, MoveUp)
{
    Player p;
    Road r2(0, 160);

    p.SetPivot(&r2);
    ASSERT_EQ(p.pivot, &r2);
    ASSERT_NO_FATAL_FAILURE(p.MoveUp());
    ASSERT_EQ(p.pivot, &r2);

    // Connect player's pivot with several roads so it can move on some of them

    Road r0(0, 0);
    Road r1(0, 80);
    Road r3(0, 240);

    r2.AddAdjecent(&r0);
    r2.AddAdjecent(&r1);
    r2.AddAdjecent(&r3);

    ASSERT_NO_FATAL_FAILURE(p.MoveUp());
    ASSERT_NE(p.pivot, &r0);
    ASSERT_NE(p.pivot, &r2);
    ASSERT_NE(p.pivot, &r3);
    ASSERT_EQ(p.pivot, &r1);

    // If there is a box on the road and it can't move on in player's direction:

    Box box;
    Road players_road(0, 160);
    Road box_here(0, 80);

    p.SetPivot(&players_road);
    box.SetPivot(&box_here);

    players_road.AddAdjecent(&box_here);

    ASSERT_NO_FATAL_FAILURE(p.MoveUp());
    ASSERT_NE(p.pivot, &box_here);
    ASSERT_EQ(p.pivot, &players_road);
    ASSERT_NE(box.pivot, &players_road);

    // If there is a box, but we can move it

    Road box_will_be_here(0, 0);
    // box_here.AddAdjecent(&box_will_be_here);
    box_will_be_here.AddAdjecent(&box_here);

    p.SetPivot(&players_road);
    box.SetPivot(&box_here);

    ASSERT_NO_FATAL_FAILURE(p.MoveUp());
    ASSERT_NE(box.pivot, &box_here);
    ASSERT_EQ(box.pivot, &box_will_be_here);
    ASSERT_NE(p.pivot, &players_road);
    ASSERT_EQ(p.pivot, &box_here);
}

TEST(Player, MoveRight)
{
    Player p;
    Road r2(80, 0);

    p.SetPivot(&r2);
    ASSERT_EQ(p.pivot, &r2);
    ASSERT_NO_FATAL_FAILURE(p.MoveRight());
    ASSERT_EQ(p.pivot, &r2);

    // Connect player's pivot with several roads so it can move on some of them

    Road r0(0, 0);
    Road r1(160, 0);
    Road r3(240, 0);

    r2.AddAdjecent(&r0);
    r2.AddAdjecent(&r1);
    r2.AddAdjecent(&r3);

    ASSERT_NO_FATAL_FAILURE(p.MoveRight());
    ASSERT_NE(p.pivot, &r0);
    ASSERT_NE(p.pivot, &r3);
    ASSERT_NE(p.pivot, &r2);
    ASSERT_EQ(p.pivot, &r1);

    // If there is a box on the road and it can't move on in player's direction:

    Box box;
    Road players_road(80, 0);
    Road box_here(160, 0);

    p.SetPivot(&players_road);
    box.SetPivot(&box_here);

    players_road.AddAdjecent(&box_here);

    ASSERT_NO_FATAL_FAILURE(p.MoveRight());
    ASSERT_NE(p.pivot, &box_here);
    ASSERT_EQ(p.pivot, &players_road);
    ASSERT_NE(box.pivot, &players_road);

    // If there is a box, but we can move it

    Road box_will_be_here(240, 0);
    box_will_be_here.AddAdjecent(&box_here);

    p.SetPivot(&players_road);
    box.SetPivot(&box_here);

    ASSERT_NO_FATAL_FAILURE(p.MoveRight());
    ASSERT_NE(box.pivot, &box_here);
    ASSERT_EQ(box.pivot, &box_will_be_here);
    ASSERT_NE(p.pivot, &players_road);
    ASSERT_EQ(p.pivot, &box_here);
}

TEST(Player, MoveDown)
{
    Player p;
    Road r2(0, 160);

    p.SetPivot(&r2);
    ASSERT_EQ(p.pivot, &r2);
    ASSERT_NO_FATAL_FAILURE(p.MoveDown());
    ASSERT_EQ(p.pivot, &r2);

    // Connect player's pivot with several roads so it can move on some of them

    Road r0(0, 0);
    Road r1(0, 80);
    Road r3(0, 240);

    r2.AddAdjecent(&r0);
    r2.AddAdjecent(&r1);
    r2.AddAdjecent(&r3);

    ASSERT_NO_FATAL_FAILURE(p.MoveDown());
    ASSERT_NE(p.pivot, &r0);
    ASSERT_NE(p.pivot, &r1);
    ASSERT_NE(p.pivot, &r2);
    ASSERT_EQ(p.pivot, &r3);

    // If there is a box on the road and it can't move on in player's direction:

    Box box;
    Road players_road(0, 80);
    Road box_here(0, 160);

    p.SetPivot(&players_road);
    box.SetPivot(&box_here);

    players_road.AddAdjecent(&box_here);

    ASSERT_NO_FATAL_FAILURE(p.MoveDown());
    ASSERT_NE(p.pivot, &box_here);
    ASSERT_EQ(p.pivot, &players_road);
    ASSERT_NE(box.pivot, &players_road);

    // If there is a box, but we can move it

    Road box_will_be_here(0, 240);
    box_will_be_here.AddAdjecent(&box_here);

    p.SetPivot(&players_road);
    box.SetPivot(&box_here);

    ASSERT_NO_FATAL_FAILURE(p.MoveDown());
    ASSERT_NE(box.pivot, &box_here);
    ASSERT_EQ(box.pivot, &box_will_be_here);
    ASSERT_NE(p.pivot, &players_road);
    ASSERT_EQ(p.pivot, &box_here);
}

TEST(Player, MoveLeft)
{
    Player p;
    Road r2(160, 0);

    p.SetPivot(&r2);
    ASSERT_EQ(p.pivot, &r2);
    ASSERT_NO_FATAL_FAILURE(p.MoveLeft());
    ASSERT_EQ(p.pivot, &r2);

    // Connect player's pivot with several roads so it can move on some of them

    Road r0(0, 0);
    Road r1(80, 0);
    Road r3(240, 0);

    r2.AddAdjecent(&r0);
    r2.AddAdjecent(&r1);
    r2.AddAdjecent(&r3);

    ASSERT_NO_FATAL_FAILURE(p.MoveLeft());
    ASSERT_NE(p.pivot, &r0);
    ASSERT_NE(p.pivot, &r3);
    ASSERT_NE(p.pivot, &r2);
    ASSERT_EQ(p.pivot, &r1);

    // If there is a box on the road and it can't move on in player's direction:

    Box box;
    Road players_road(160, 0);
    Road box_here(80, 0);

    p.SetPivot(&players_road);
    box.SetPivot(&box_here);

    players_road.AddAdjecent(&box_here);

    ASSERT_NO_FATAL_FAILURE(p.MoveLeft());
    ASSERT_NE(p.pivot, &box_here);
    ASSERT_EQ(p.pivot, &players_road);
    ASSERT_NE(box.pivot, &players_road);

    // If there is a box, but we can move it

    Road box_will_be_here(0, 0);
    box_will_be_here.AddAdjecent(&box_here);

    p.SetPivot(&players_road);
    box.SetPivot(&box_here);

    ASSERT_NO_FATAL_FAILURE(p.MoveLeft());
    ASSERT_NE(box.pivot, &box_here);
    ASSERT_EQ(box.pivot, &box_will_be_here);
    ASSERT_NE(p.pivot, &players_road);
    ASSERT_EQ(p.pivot, &box_here);
}
