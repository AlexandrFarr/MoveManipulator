#include "ManipulatorSystem.h"
#include <math.h>

using namespace std;

//change of coordinates
void ManipulatorSystem::changePoint(Manipulator* a, Point* p)
{
	a->set_x(p->get_x());
	a->set_y(p->get_y());
	
	/*double cx, cy;

	cx = p->get_x() - a->get_x();
	cy = p->get_y() - a->get_y();

	
	if (abs(cx) > a->getRadius())
	{
		if (cx > 0) {

			a->set_x(cx - a->getRadius());
		}
		else
		{
			a->set_x(cx + a->getRadius());
		}
	}
	if (abs(cy) > a->getRadius())
	{
		if (cy > 0) {
			a->set_y(cy - a->getRadius());
		}
		else
		{
			a->set_y(cy + a->getRadius());
		}
	}
	
	*/
}

//input array of parts
void ManipulatorSystem::entryMassivOfDetails(std::vector<Point>& vec)
{
	unsigned n = 0;
	std::cout << "entry nubmer of details n= ";
	std::cin >> n;
	std::cout << "/n entry coordinates of details x,y" << std::endl;

	for (int i = 0; i < n; i++)
	{
		double vx, vy;
		std::cout << " ââåäèòå êîîðäèíàòó  x= ";
		std::cin >> vx;
		std::cout << "/n ââåäèòå êîîðäèíàòó  y= ";
		std::cin >> vy;
		Point P(vx, vy);
		vec.push_back(P);
	}

	
}

//show table iteration ,coordinate and manipulators
void ManipulatorSystem::showTablePath(std::vector<Point>& vec, std::vector<bool>& boolvec)
{
	double y, z;

	string str1;
	string str2;




	for (int i = 0; i < vec.size(); i++)
	{
		ostringstream ss2, ss3;
		ss2.precision(2);
		ss3.precision(2);


		if (boolvec.at(i) == 0)
		{
			;

			y = vec.at(i).get_x();
			z = vec.at(i).get_y();
			ss2 << fixed << y;
			ss3 << fixed << z;
			str1 = str1 + ss2.str() + ";" + ss3.str() + "\t";
			str2 = str2 + "\t" + "\t";

		}
		else
		{
			y = vec.at(i).get_x();
			z = vec.at(i).get_y();

			ss2 << fixed << y;
			ss3 << fixed << z;

			str1 = str1 + "\t" + "\t";
			str2 = str2 + ss2.str() + ";" + ss3.str() + "\t";

		}
	}

	cout << "Èòåðàöèÿ\t";
	for (int i = 0; i < boolvec.size(); i++)
	{
		cout << i + 1 << "\t" << "\t";
	}
	cout << endl;


	cout << "Ìàíèïóëÿòîð1\t" << str1 << endl;
	cout << "Ìàíèïóëÿòîð2\t" << str2 << endl;
}

