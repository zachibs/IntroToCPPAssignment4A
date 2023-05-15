#include "Point.hpp"

using namespace std;

namespace ariel{

    Point::Point(): x(0), y(0){}

    Point::Point(double otherX, double otherY): x(otherX), y(otherY){}

    Point::Point(Point &other): x(other.getX()), y(other.getY()){}

    double Point::distance(Point &other){
        double dx = other.getX() - this->getX();
        double dy = other.getY() - this->getY();

        return sqrt(pow(dx, 2) + pow(dy,2));
        
    }

    double Point::getX(){
        return this->x;
    }

    double Point::getY(){
        return this->y;
    }

    Point Point::moveTowards(Point &source, Point &destination, double amount){

        return source;
    }

    void Point::print(){
        cout << "Currently not implemented" << endl;
    }

}