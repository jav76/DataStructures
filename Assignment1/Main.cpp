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
    char implementation;
    int operation;
    bool exit = false;
    string cityName;
    double xPos;
    double yPos;
    double distance;
    importDataArray(citiesList, numCities);

    linkedList list;
    while (exit == false)
    {
        implementation = getImplementationOption();
        operation = getOperationOption();
        switch (implementation)
        {
            case 'A': // Array based list implementation 
                switch (operation)
                {
                    case 1: // Insert new record
                        cityName = getCityName();
                        xPos = getXPos();
                        yPos = getYPos();
                        insertArrayRecord(citiesList, cityName, xPos, yPos, numCities);
                        break;

                    case 2: // Search for record by name
                        cityName = getCityName();
                        searchArrayByName(citiesList, cityName, numCities);
                        break;

                    case 3: // Search for record by coordinate
                        xPos = getXPos();
                        yPos = getYPos();
                        searchArrayByCoord(citiesList, xPos, yPos, numCities);
                        break;
                    
                    case 4: // Delete a record by name
                        cityName = getCityName();
                        deleteArrayRecordByName(citiesList, cityName, numCities);
                        break;

                    case 5: // Delete a record by coordinate
                        xPos = getXPos();
                        yPos = getYPos();
                        deleteArrayRecordByCoord(citiesList, xPos, yPos, numCities);
                        break;

                    case 6: // Print records within a given distance of a specific location
                        cityName = getCityName();
                        distance = getDistance();
                        printArrayWithinDistance(citiesList, cityName, distance, numCities);
                        break;

                    case 7: // Print all records in the list
                        printArrayRecords(citiesList, numCities);
                        break;

                    case 8:
                        exit = true; 
                        break;
                }
                break;
            case 'B': // Linked list based implentation 
                switch (operation)
                {
                case 1: // Insert a record
                    cityName = getCityName();
                    xPos = getXPos();
                    yPos = getYPos();
                    list.insertRecord(cityName, xPos, yPos);
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
                    list.printRecords();
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
