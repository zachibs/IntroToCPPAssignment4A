#include "Team.hpp"

namespace ariel{

    Team::Team(Character *member): teamLeader(member), teamSize(1){

        if(member->getIsInTeam()){
            throw runtime_error("Already in team");
        }

        team.push_back(member);

        member->setIsInTeam(true);
    }

    void Team::add(Character *member){
        if(teamSize >= 10 || member->getIsInTeam()){
            throw runtime_error("No room or member in team");
        }
        team.push_back(member);
        teamSize += 1;
        member->setIsInTeam(true);
    }

    string Team::print(){
        string toPrint;
        for (auto member : team){
            toPrint += member->print() + "\n";
        }
        return toPrint;
    }

    Character * Team::closestCharacter(Character *teamLeader){
        double min = numeric_limits<double>::max();
        Character *character = nullptr;

        for(Character *member : team){
            if(member->isAlive()){
                if (teamLeader->distance(*member) < min){
                    min = teamLeader->distance(*member);
                    character = member;
                }
            }
        }

        return character;
    }


    bool Team::stillAlive(){

        int aliveCount = 0;

        for(Character *member : team){
            if((*member).isAlive()){
                aliveCount += 1;
            }
        }

        return aliveCount;

    }

    void Team::attack(Team *enemyTeam){
        if(enemyTeam == nullptr){
            throw invalid_argument("Nullptr");
        }

        if(!enemyTeam->stillAlive() || !this->stillAlive()){
            throw runtime_error("Team not alive");
        }

        if(!this->teamLeader->isAlive()){
            Character *newLeader = this->closestCharacter(this->teamLeader);

            if(newLeader == nullptr){
                return;
            }

            this->teamLeader = newLeader;
            this->teamLeader->setIsInTeam(true);
        }

        Character *victim = enemyTeam->closestCharacter(this->teamLeader);

        if (victim == nullptr){
            return;
        }

        for(Character *member : team){
            if (dynamic_cast<Cowboy *>(member) != NULL){
                if (member->isAlive()){
                    Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
                    if(cowboy->hasboolets()){
                        cowboy->shoot(*victim);
                    }else{
                        cowboy->reload();
                    }
                }
            }

            if(!victim->isAlive()){
                victim = enemyTeam->closestCharacter(this->teamLeader);
                if(victim == NULL){
                    return;
                }
            }
        }

        for(Character *member : team){
            if (dynamic_cast<Ninja *>(member) != NULL){
                if (member->isAlive()){
                    Ninja *ninja = dynamic_cast<Ninja *>(member);
                    if(ninja->distance(*victim) <= 1){
                        ninja->slash(*victim);
                    }else{
                        ninja->move(*victim);
                    }
                }
            }

            if(!victim->isAlive()){
                victim = enemyTeam->closestCharacter(this->teamLeader);
                if(victim == NULL){
                    return;
                }
            }
        }
    }

    Team::~Team(){
        for(Character *member: team){
            delete member;
        }
}
}