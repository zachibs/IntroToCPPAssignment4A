#include "Character.hpp"

namespace ariel{

    Character::Character(): location(), hitPoint(0), name("Default"){}
    Character::Character(Point &point, int hit, string newName): location(point), hitPoint(hit), name(newName), isInTeam(false){}

    bool Character::isAlive(){
        return hitPoint > 0;
    }

    double Character::distance(Character &otherCharacter){
        Point tempPoint = otherCharacter.getLocation();
        return this->location.distance(tempPoint);
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

    bool Character::getIsInTeam(){
        return isInTeam;
    }

    void Character::setIsInTeam(bool in){
        isInTeam = in;
    }

    Cowboy::Cowboy(Point &loc, string name): Character(loc, 110, name), bullets(6){}

    string Cowboy::print(){
        return ("C, " + this->getName() + ", " + to_string(this->getHitPoint()) + ", (" + to_string(this->getLocation().getX()) + ", " + to_string(this->getLocation().getY()) + ")"); 
    }

    void Cowboy::shoot(Character &other){
        if(isAlive() && this->bullets > 0){
            other.hit(10);
            this->bullets -= 1;
        }
    }

    bool Cowboy::hasboolets(){
        return this->bullets > 0;
    }

    void Cowboy::reload(){
        this->bullets = 6;
    }

    Ninja::Ninja(Point &loc, string name, int spd, int hit): Character(loc, hit, name), speed(spd){}

    string Ninja::print(){
        return ("N, " + this->getName() + ", " + to_string(this->getHitPoint()) + ", (" + to_string(this->getLocation().getX()) + ", " + to_string(this->getLocation().getY()) + ")"); 
    }

    void Ninja::move(Character &other){
        Point src = this->getLocation();
        Point dst = other.getLocation();
        Point end = src.moveTowards(src, dst, speed);
        this->setLocation(end);
    }

    void Ninja::slash(Character &other){
        if (this->isAlive() && this->distance(other) < 1){
            other.hit(40);
        }
    }

    YoungNinja::YoungNinja(Point &loc, string name): Ninja(loc, name, 14, 100){}

    TrainedNinja::TrainedNinja(Point &loc, string name): Ninja(loc, name, 12, 120){}
    
    OldNinja::OldNinja(Point &loc, string name): Ninja(loc, name, 8, 150){}

}