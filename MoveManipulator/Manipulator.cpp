#include <iostream>
#include "Manipulator.h"
#

using namespace std;

double Manipulator::getRadius()
{
	return radius;
}



void Manipulator::setRadius(double cRadius)
{
	radius = cRadius;
}

//radius check
bool Manipulator::proverkaEntry(double cX, double cY)
{
	if (pow((this->get_x() - cX), 2) + pow((this->get_y() - cY), 2) <= pow(radius, 2)) {
		return true;

	}
	else
		return false;
}

void Manipulator::entry_x_y_r()
{
	double x, y, r;
	cout << "¬ведите координаты и радиус работы манипул€тора" << endl;;
	cout << " x = ";
	cin >> x;
	cout << " y = ";
	cin >> y;
	cout << " radius = ";
	cin >> r;

	this->set_x(x);
	this->set_y(y);
	this->setRadius(r);
}


