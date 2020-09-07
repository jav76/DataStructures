#include <iostream>
#include "Header.h"
#include <chrono>

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
    float distance;
    importDataList(citiesList, numCities);
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

                    case 2: // Search for record by name
                        cityName = getCityName();
                        searchListByName(citiesList, cityName, numCities);
                        break;

                    case 3: // Search for record by coordinate
                        xPos = getXPos();
                        yPos = getYPos();
                        searchListByCoord(citiesList, xPos, yPos, numCities);
                        break;
                    
                    case 4: // Delete a record by name
                        cityName = getCityName();
                        deleteListRecordByName(citiesList, cityName, numCities);
                        break;

                    case 5: // Delete a record by coordinate
                        xPos = getXPos();
                        yPos = getYPos();
                        deleteListRecordByCoord(citiesList, xPos, yPos, numCities);
                        break;

                    case 6: // Print records within a given distance of a specific location
                        cityName = getCityName();
                        distance = getDistance();
                        printListWithinDistance(citiesList, cityName, distance, numCities);
                        break;

                    case 7:
                        printListRecords(citiesList, numCities);
                        break;

                    case 8:
                        exit = true; 
                        break;
                }
                break;
            case 'B':
                switch (operation)
                {
                case 1: // Insert a record

                    break;

                case 2: // Search for record by name

                    break;

                case 3: // Search for record by coordinate

                    break;

                case 4: // Delete a record by name

                    break;

                case 5: // Delete a record by coordinate

                    break;
                case 6: // Print records within a given distance of a specific location

                    break;

                case 7: // Print all records

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
