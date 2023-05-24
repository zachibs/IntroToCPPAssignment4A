#include "Point.hpp"

using namespace std;

namespace ariel{

    Point::Point(): x(0), y(0){}

    Point::Point(double otherX, double otherY): x(otherX), y(otherY){}

    double Point::distance(Point other){
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

    Point Point::moveTowards(Point source, Point destination, double amount) {

        if (amount < 0){
            throw invalid_argument("amount < 0");
        }
        
        double dx = destination.getX() - source.getX();
        double dy = destination.getY() - source.getY();

        double currentDist = sqrt(pow(dx, 2) + pow(dy,2));

        if (currentDist <= amount){
            return destination;
        }else{
            double newDistance = (amount / currentDist);
            double towardsX = source.getX() + (dx * newDistance);
            double towardsY = source.getY() + (dy * newDistance);
            return Point(towardsX, towardsY);
        }
    }

    void Point::print(){
        cout << "(x=" << x << ", y=" << y << ")" << endl;
    }

}