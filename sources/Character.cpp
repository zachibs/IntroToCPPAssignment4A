#include "Character.hpp"

namespace ariel{

    Character::Character(): location(), hitPoint(0), name("Default"){}
    Character::Character(Point &point, int hit, string newName): location(point), hitPoint(hit), name(newName){}

    bool Character::isAlive(){
        return hitPoint > 0;
    }

    double Character::distance(Character &otherCharacter){
        return 0;
    }

    void Character::hit(int value){
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

    void Character::print(){
        cout << "this will print the character" << endl;
    }

    Point Character::getLocation(){
        return location;
    }

    void Character::setLocation(Point &otherPoint){
        location = otherPoint;
    }

    int Character::getHitPoint(){
        return hitPoint;
    }

    void Character::setHitPoint(int newHitPoint){
        hitPoint = newHitPoint;
    }
}