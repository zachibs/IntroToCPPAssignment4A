#pragma once
#include "Team.hpp"

namespace ariel{
    class SmartTeam : public Team{

        public:
            SmartTeam(Character *leader);
            Character *selectVictim(vector<Character*>&);
            void attack(Team *);
    };
}