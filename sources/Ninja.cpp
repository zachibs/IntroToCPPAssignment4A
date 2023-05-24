#include "Ninja.hpp"

namespace ariel{

    Ninja::Ninja(string name, Point loc, int spd, int hit): Character(loc, hit, name), speed(spd){}

    string Ninja::print(){
        return ("N, " + this->getName() + ", " + to_string(this->getHitPoint()) + ", (" + to_string(this->getLocation().getX()) + ", " + to_string(this->getLocation().getY()) + ")"); 
    }

    void Ninja::move(Character *other){
        Point src = this->getLocation();
        Point dst = other->getLocation();
        Point end = src.moveTowards(src, dst, speed);
        this->setLocation(end);
    }

    void Ninja::slash(Character *other){

        if(!this->isAlive() || !other->isAlive() || this == other){
            throw runtime_error("Not alive");
        }

        if (this->isAlive() && this->distance(other) < 1){
            other->hit(40);
        }
    }
}