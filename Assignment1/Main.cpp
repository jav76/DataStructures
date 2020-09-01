
#include <iostream>
#include "Header.h"

using std::cout;
using std::cin;
using std::endl;
using std::string; 

int main()
{
    cityData citiesList[ARRAYSIZE];
    int numCities = 0;
    node* head = new node();
    char implementation;
    int operation;
    bool exit = false;
    string cityName;
    float xPos;
    float yPos;
    while (exit == false)
    {
        implementation = getImplementationOption();
        operation = getOperationOption();
        switch (implementation)
        {
            case 'A':
                switch (operation)
                {
                    case 1:
                        cityName = getCityName();
                        xPos = getXPos();
                        yPos = getYPos();
                        insertListRecord(citiesList, cityName, xPos, yPos, numCities);
                        break;

                    case 7:
                        printListRecords(citiesList, numCities);
                        break;


                    case 8:
                        exit = true; // shut this bitch down
                        break;
                }
                break;
            case 'B':
                switch (operation)
                {
                    case 1:
                        // do some other shit
                        cout << "I'm just putting this here so this mfer builds";
                        break;
                    case 8:
                        exit = true;
                        break;
                }
                break;
        }
    }
    return 0;
}
