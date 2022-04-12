
#include <iostream>
#include "Point.h"
#include "ManipulatorSystem.h"
#include "Manipulator.h"
#include <vector>


using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    

    //crete two vectors for coordinates and to store information about the used manipulator 
    vector<Point> massivCoordinate;
    vector<bool>  pathManipulators;


    // cteate Object of manipulatorSystem for operation with manupulators
    //ManipulatorSystem Mang;
    ManipulatorSystem* Mang = new ManipulatorSystem;
    Mang->entryMassivOfDetails(massivCoordinate);


    // creating two manipulators
    Manipulator* M1 = new Manipulator;
    Manipulator* M2 = new Manipulator;

    //setting coordinates and radius
    cout << "Настройки первого манипулятора :" << endl;
    M1->entry_x_y_r();
    cout << "\n Настройки второго манипулятора :" << endl;
    M2->entry_x_y_r();

    //selecting an effective manipulator 
    cout << "Проверка каким манипулятором пользоватьcя эффективнее " << endl;

    for (int i = 0; i < massivCoordinate.size(); i++)
    {

        if ((M1->proverkaEntry(massivCoordinate.at(i).get_x(), massivCoordinate.at(i).get_y()) == true) && (M2->proverkaEntry(massivCoordinate.at(i).get_x(), massivCoordinate.at(i).get_y()) == false))
        {
            pathManipulators.push_back(0);
        }
        else
        {
            if ((M1->proverkaEntry(massivCoordinate.at(i).get_x(), massivCoordinate.at(i).get_y()) == false) && (M2->proverkaEntry(massivCoordinate.at(i).get_x(), massivCoordinate.at(i).get_y()) == true))
            {
                pathManipulators.push_back(1);
            }
            else
            {
                if ((M1->proverkaEntry(massivCoordinate.at(i).get_x(), massivCoordinate.at(i).get_y()) == false) && (M2->proverkaEntry(massivCoordinate.at(i).get_x(), massivCoordinate.at(i).get_y()) == false))
                {

                    if ((sqrt((pow((massivCoordinate.at(i).get_x() - M1->get_x()), 2) + pow((massivCoordinate.at(i).get_y() - M1->get_y()), 2))) ) <= ((sqrt((pow((massivCoordinate.at(i).get_x() - M2->get_x()), 2) + pow((massivCoordinate.at(i).get_y() - M2->get_y()), 2)))) ))
                    {
                        Mang->changePoint(M1, &massivCoordinate.at(i));
                        pathManipulators.push_back(0);
                    }
                    else
                    {
                        Mang->changePoint(M2, &massivCoordinate.at(i));
                        pathManipulators.push_back(1);
                    }
                }
                else
                    if ((M1->proverkaEntry(massivCoordinate.at(i).get_x(), massivCoordinate.at(i).get_y()) == true) && ((M2->proverkaEntry(massivCoordinate.at(i).get_x(), massivCoordinate.at(i).get_y())) == true))
                    {
                        if ((sqrt((pow((massivCoordinate.at(i).get_x() - M1->get_x()), 2) + pow((massivCoordinate.at(i).get_y() - M1->get_y()), 2)))) <= ((sqrt((pow((massivCoordinate.at(i).get_x() - M2->get_x()), 2) + pow((massivCoordinate.at(i).get_y() - M2->get_y()), 2))))))
                        {
                            pathManipulators.push_back(0);
                        }
                        else
                        {
                            pathManipulators.push_back(1);


                        }
                    }
            }


        }
    }

    
     //show table iteration and coordinates
    Mang->showTablePath(massivCoordinate, pathManipulators);

    delete M1,M2, Mang;

}
