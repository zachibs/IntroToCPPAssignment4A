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

    void Team::print(){
        for(int i = 0; i < 2; i++){
            for (auto member : team){
                if(i == 0 && dynamic_cast<Cowboy *>(member) != NULL){
                    cout << member->print() << endl;
                } else if(i == 1 && dynamic_cast<Ninja *>(member) != NULL){
                    cout << member->print() << endl;
                }
            }
        }
    }

    Character * Team::closestCharacter(Character *teamLeader){
        double min = numeric_limits<double>::max();
        Character *character = nullptr;

        for(int i = 0; i < 2; i++){
            for (Character *member : team){
                if(i == 0 && dynamic_cast<Cowboy *>(member) != NULL){
                    if(member->isAlive()){
                        if (teamLeader->distance(member) < min){
                            min = teamLeader->distance(member);
                            character = member;
                        }
                    }
                } else if(i == 1 && dynamic_cast<Ninja *>(member) != NULL){
                    if(member->isAlive()){
                        if (teamLeader->distance(member) < min){
                            min = teamLeader->distance(member);
                            character = member;
                        }
                    }
                }
            }
        }

        return character;
    }


    int Team::stillAlive(){

        int aliveCount = 0;

        for(int i = 0; i < 2; i++){
            for (auto member : team){
                if(i == 0 && dynamic_cast<Cowboy *>(member) != NULL){
                    if((*member).isAlive()){
                        aliveCount += 1;
                    }
                } else if(i == 1 && dynamic_cast<Ninja *>(member) != NULL){
                    if((*member).isAlive()){
                        aliveCount += 1;
                    }
                }
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
                        cowboy->shoot(victim);
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
                    if(ninja->distance(victim) <= 1){
                        ninja->slash(victim);
                    }else{
                        ninja->move(victim);
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

    Character* Team::getTeamLeader(){
        return this->teamLeader;
    }

    int Team::getTeamSize(){
        return this->teamSize;
    }

    vector<Character *> Team::getTeam(){
        return this->team;
    }

    void Team::setTeamLeader(Character *other){
        this->teamLeader = other;
    }
}