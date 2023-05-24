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
            Character(Point, int, string);

            bool isAlive();
            double distance(Character *);
            void hit(int);
            string getName();
            virtual string print() = 0;
            Point getLocation();
            void setLocation(Point);
            int getHitPoint();
            void setHitPoint(int);
            bool getIsInTeam();
            void setIsInTeam(bool);
            virtual ~Character() = default;
    };

}
