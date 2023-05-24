#pragma once
#include "Team.hpp"

namespace ariel{
    class Team2 : public Team{

        public:
            Team2(Character *);
            Character *closestCharacter(Character *);
            void attack(Team *);
            int stillAlive();
            void print();
    };
}