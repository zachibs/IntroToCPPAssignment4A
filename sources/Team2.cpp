#include "Team2.hpp"

namespace ariel{

    Team2::Team2(Character *member): Team(member){}

    
    Character *Team2::closestCharacter(Character *teamLeader){
        double minDistance = numeric_limits<double>::max();
        Character *character = nullptr;

        for(Character *member : this->getTeam()){
            if(member->isAlive()){
                if (teamLeader->distance(member) < minDistance){
                    minDistance = teamLeader->distance(member);
                    character = member;
                }
            }
        }

        return character;
    }

    void Team2::attack(Team *enemyTeam){
        if(enemyTeam == nullptr){
            throw invalid_argument("Nullptr");
        }

        if(!enemyTeam->stillAlive() || !this->stillAlive()){
            throw runtime_error("Team not alive");
        }

        if(!this->getTeamLeader()->isAlive()){
            Character *newLeader = this->closestCharacter(this->getTeamLeader());

            if(newLeader == nullptr){
                return;
            }

            this->setTeamLeader(newLeader);
            this->getTeamLeader()->setIsInTeam(true);
        }

        Character *victim = enemyTeam->closestCharacter(this->getTeamLeader());

        if (victim == nullptr){
            return;
        }

        for(Character *member : getTeam()){
            if (dynamic_cast<Cowboy *>(member) != NULL){
                if (member->isAlive()){
                    Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
                    if(cowboy->hasboolets()){
                        cowboy->shoot(victim);
                    }else{
                        cowboy->reload();
                    }
                }
            }else if (dynamic_cast<Ninja *>(member) != NULL){
                if (member->isAlive()){
                    Ninja *ninja = dynamic_cast<Ninja *>(member);
                    if(ninja->distance(victim) <= 1){
                        ninja->slash(victim);
                    }else{
                        ninja->move(victim);
                    }
                }
            }

            if(!victim->isAlive()){
                victim = enemyTeam->closestCharacter(this->getTeamLeader());
                if(victim == NULL){
                    return;
                }
            }
        }
    }

    int Team2::stillAlive(){

        int aliveCount = 0;

        for(Character *member : getTeam()){
            if((*member).isAlive()){
                aliveCount += 1;
            }
        }

        return aliveCount;

    }

    void Team2::print(){
        for (auto member : getTeam()){
            cout << member->print() << endl;
        }
    }
}