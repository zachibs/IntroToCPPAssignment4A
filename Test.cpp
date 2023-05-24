#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/SmartTeam.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace ariel;

TEST_CASE("Point") {
  Point firstPoint(0, 1);
  CHECK(firstPoint.distance(Point(0, 0)) == 1);
  CHECK_FALSE(firstPoint.distance(Point(0, 0)) == 2);

  Point secondPoint(2, 0);
  CHECK(secondPoint.distance(Point(0, 0)) == 2);
  CHECK_FALSE(secondPoint.distance(Point(0, 0)) == 4);

  Point thirdPoint = Point::moveTowards(firstPoint, secondPoint, 3);
  CHECK_FALSE(firstPoint.distance(thirdPoint) == 3);

  Point fourthPoint = Point::moveTowards(firstPoint, secondPoint, 5);
  CHECK(firstPoint.distance(fourthPoint) == firstPoint.distance(secondPoint));
}

TEST_CASE("Cowboy"){
    Cowboy cowboy("John", Point(0, 2));

    CHECK(cowboy.isAlive());
    CHECK_EQ(cowboy.getName(), "John");
    CHECK(cowboy.hasboolets());
    CHECK_EQ(cowboy.getLocation().distance(Point(0, 0)), Point(2, 0).distance(Point(0, 0)));
}

TEST_CASE("YoungNinja class"){
    YoungNinja kidNinj("ninj", Point(1,0));

    CHECK(kidNinj.isAlive());
    CHECK_EQ(kidNinj.getName(), "ninj");
    CHECK_EQ(kidNinj.getLocation().distance(Point(0, 0)), Point(0, 0).distance(Point(0, 1)));
}

TEST_CASE("Trained Ninja"){
    TrainedNinja *trainedNinj = new TrainedNinja("better ninj", Point(0.0, 0.0));
    Cowboy *cowboy = new Cowboy("cowboy", Point(1.0, 1.0));

    CHECK_EQ(trainedNinj->getHitPoint(), 120);
    CHECK(trainedNinj->isAlive());
    CHECK_THROWS(trainedNinj->slash(trainedNinj));
    trainedNinj->slash(cowboy);
    trainedNinj->move(cowboy);
    trainedNinj->slash(cowboy);
    CHECK_EQ(cowboy->getHitPoint(), 70);

    trainedNinj->slash(cowboy);
    trainedNinj->slash(cowboy);
    CHECK_FALSE(cowboy->isAlive());
    CHECK_EQ(cowboy->getHitPoint(), -10);
}

TEST_CASE("Old Ninja"){
    OldNinja *oldNinj = new OldNinja("older ninj", Point(0.0, 0.0));
    Cowboy *cowboy = new Cowboy("cowboy", Point(1.0, 1.0));

    CHECK_EQ(oldNinj->getHitPoint(), 150);
    CHECK(oldNinj->isAlive());
    CHECK_THROWS(oldNinj->slash(oldNinj));
    oldNinj->slash(cowboy);
    oldNinj->move(cowboy);
    oldNinj->slash(cowboy);
    CHECK_EQ(cowboy->getHitPoint(), 70);

    oldNinj->slash(cowboy);
    oldNinj->slash(cowboy);
    CHECK_FALSE(cowboy->isAlive());
    CHECK_EQ(cowboy->getHitPoint(), -10);
}

TEST_CASE("Team"){
    Point firstPoint(0, 0);
    Point secondPoint(1, 3);
    Cowboy *cowboy = new Cowboy("cowboy", firstPoint);
    OldNinja *oldNinj = new OldNinja("older ninj", secondPoint);
    YoungNinja *youngNinj = new YoungNinja("ninj", Point(10, 0));
    TrainedNinja *trainedNinj = new TrainedNinja("better ninj", Point(20, 30));
    Team firstTeam(cowboy);
    Team secondTeam(oldNinj);

    firstTeam.add(youngNinj);
    CHECK(firstTeam.stillAlive() == 2);

    secondTeam.add(trainedNinj);
    CHECK(secondTeam.stillAlive() == 2);

    firstTeam.attack(&secondTeam);
    CHECK(secondTeam.stillAlive() == 2);

    secondTeam.attack(&firstTeam);
    secondTeam.attack(&firstTeam);
    secondTeam.attack(&firstTeam);
    CHECK(firstTeam.stillAlive() == 1);

    while (secondTeam.stillAlive() > 0){
        firstTeam.attack(&secondTeam);
    }

    CHECK(secondTeam.stillAlive() == 0);

    CHECK_THROWS(secondTeam.attack(&firstTeam));
}