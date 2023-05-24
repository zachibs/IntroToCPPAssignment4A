#include "SmartTeam.hpp"

namespace ariel{

    SmartTeam::SmartTeam(Character *member): Team(member){}

    void SmartTeam::attack(Team *enemyTeam){
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

        vector<Character *> enemyTeamVector = enemyTeam->getTeam();
        Character *victim = selectVictim(enemyTeamVector);

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
                victim = selectVictim(enemyTeamVector);
                if(victim == NULL){
                    return;
                }
            }
        }
    }

    Character* SmartTeam::selectVictim(vector<Character*>& victims) {
        Character* victim = nullptr;

        for (Character* character : victims) {
            if (character->getHitPoint() < victim->getHitPoint()) {
                victim = character;
            }
        }

        return victim;
    }

}