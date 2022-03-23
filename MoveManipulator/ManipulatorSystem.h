#pragma once
#include <vector>
#include "Point.h"
#include "Manipulator.h"

#include <iostream>
#include <sstream>
#include <string>

class ManipulatorSystem : public Manipulator
{
private:

	//std::vector<Point> massivCoordinate

public:

	void changePoint(Manipulator* a, Point* p);
	void entryMassivOfDetails( std::vector<Point> &vec);
	void showTablePath(std::vector<Point>& vec, std::vector < bool > & boolvec);

};

