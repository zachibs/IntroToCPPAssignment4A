#include "Point.hpp"

using namespace std;

namespace ariel{

    Point::Point(): x(0), y(0){}

    Point::Point(double otherX, double otherY): x(otherX), y(otherY){}

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

    Point Point::moveTowards(Point &source, Point &destination, double amount) {
        
        double dx = source.getX() - destination.getX();
        double dy = source.getY() - destination.getY();

        double currentDist = sqrt(pow(dx, 2) + pow(dy,2));

        if (currentDist <= amount){
            return destination;
        }else{
            double towardsX = source.x + (dx * (amount / currentDist));
            double towardsY = source.y + (dy * (amount / currentDist));
            return Point(towardsX, towardsY);
        }
    }

    void Point::print(){
        cout << "(x=" << x << ", y=" << y << ")" << endl;
    }

}