#pragma once

#include "Point.hpp"
#include "Character.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
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
            void print();
            Character *closestCharacter(Character *);
            int stillAlive();
            void attack(Team *);
            ~Team();
            Character* getTeamLeader();
            void setTeamLeader(Character *);
            int getTeamSize();
            vector<Character *> getTeam();

    };

}