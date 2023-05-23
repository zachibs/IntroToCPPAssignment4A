#pragma once
#include "Character.hpp"
#include <vector>
#include <limits>

namespace ariel{

    class Team{
        private:
            Character *teamLeader;
            int teamSize;
            vector<Character *> team;
        
        public:
            Team(Character *);
            void add(Character *);
            string print();
            Character *closestCharacter(Character *);
            bool stillAlive();
            void attack(Team *);
            ~Team();

    };

}