#include "Cowboy.hpp"

namespace ariel{

    Cowboy::Cowboy(string name, Point loc): Character(loc, 110, name), bullets(6){}

    string Cowboy::print(){
        return ("C, " + this->getName() + ", " + to_string(this->getHitPoint()) + ", (" + to_string(this->getLocation().getX()) + ", " + to_string(this->getLocation().getY()) + ")"); 
    }

    void Cowboy::shoot(Character *other){

        if(!this->isAlive() || !other->isAlive() || this == other){
            throw runtime_error("Not alive");
        }

        if(isAlive() && this->bullets > 0){
            other->hit(10);
            this->bullets -= 1;
        }
    }

    bool Cowboy::hasboolets(){
        return this->bullets > 0;
    }

    void Cowboy::reload(){

        if (!this->isAlive()){
            throw runtime_error("dead so cant reload");
        }
        this->bullets = 6;
    }
}