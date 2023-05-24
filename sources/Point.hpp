#pragma once
#include <iostream>
#include <cmath>

namespace ariel{
    class Point{
        private:
            double x;
            double y;

        public:
            Point();
            Point(double, double);
            double distance(Point);
            double getX();
            double getY();
            static Point moveTowards(Point, Point, double);
            void print();
        };
}