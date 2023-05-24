#include "Character.hpp"

namespace ariel{

    Character::Character(): location(), hitPoint(0), name("Default"){}
    Character::Character(Point point, int hit, string newName): location(point), hitPoint(hit), name(newName), isInTeam(false){}

    bool Character::isAlive(){
        return hitPoint > 0;
    }

    double Character::distance(Character *otherCharacter){
        Point tempPoint = otherCharacter->getLocation();
        return this->location.distance(tempPoint);
    }

    void Character::hit(int value){

        if(value < 0){
            throw invalid_argument("Negative number");
        }

        if (isAlive()){
            if (hitPoint > 0){
                hitPoint -= value;
            } else{
                hitPoint = 0;
            }
        }
    }

    string Character::getName(){
        return name;
    }

    Point Character::getLocation(){
        return location;
    }

    void Character::setLocation(Point otherPoint){
        location = otherPoint;
    }

    int Character::getHitPoint(){
        return hitPoint;
    }

    void Character::setHitPoint(int newHitPoint){
        hitPoint = newHitPoint;
    }

    bool Character::getIsInTeam(){
        return isInTeam;
    }

    void Character::setIsInTeam(bool in){
        isInTeam = in;
    }

}