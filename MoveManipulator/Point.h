#pragma once
class Point
{
private:
    double x, y;
public:
    Point() {
        x = 0;
        y = 0;
    }
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }

    double get_x();
    double get_y();
    void set_x(double _x);
    void set_y(double _y);
    void  showDisplay();



};