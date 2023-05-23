#pragma once
#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel{

    class Character{
        private: 
            Point location;
            int hitPoint;
            string name;
            bool isInTeam;

        public:
            Character();
            Character(Point &, int, string);

            bool isAlive();
            double distance(Character &);
            void hit(int);
            string getName();
            virtual string print() = 0;
            Point getLocation();
            void setLocation(Point &);
            int getHitPoint();
            void setHitPoint(int);
            bool getIsInTeam();
            void setIsInTeam(bool);
    };

    class Cowboy : public Character{
        private:
            int bullets;

        public:
            Cowboy(Point &, string);
            void shoot(Character &);
            bool hasboolets();
            void reload();
            string print();

    };

    class Ninja : public Character{
        private:
            int speed;
        
        public:
            Ninja(Point &, string, int, int);
            void move(Character &);
            void slash(Character &);
            string print();
    };


    class YoungNinja : Ninja{
        public:
            YoungNinja(Point &, string);
    };

    class TrainedNinja : Ninja{
        public:
            TrainedNinja(Point &, string);
    };

    class OldNinja : Ninja{
        public:
            OldNinja(Point &, string);
    };
}
