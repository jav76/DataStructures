#include "Header.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;


char getImplementationOption(void)
{
    char userOption;
    cout << "Implementation options:" << endl;
    cout << "A. Use an array-based list implementation" << endl;
    cout << "B. Use a linked-list based implementation" << endl;
    cout << endl << "Enter your implementation option: ";
    cin >> userOption;
    userOption = toupper(userOption);
    while (cin.fail() || (userOption != 'A' && userOption != 'B'))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "Invalid option entered. Please try again." << endl << endl;
        cout << "Enter your implementation option: ";
        cin >> userOption;
        userOption = toupper(userOption);
    }
    return userOption;

}

int getOperationOption(void)
{
    int userOption;
    cout << endl << "Operation options:" << endl;
    cout << "1. Insert a record" << endl;
    cout << "2. Search for a record by name" << endl;
    cout << "3. Search for a record by coordinate" << endl;
    cout << "4. Delete a record by name" << endl;
    cout << "5. Delete a record by coordinate" << endl;
    cout << "6. Print record within a given distance of specified location" << endl;
    cout << "7. Print all records" << endl;
    cout << "8. Exit" << endl;

    cout << endl << "Enter your operation option: ";
    cin >> userOption;
    while (cin.fail() || userOption > 8 || userOption < 1)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "Invalid option entered. Please try again. " << endl << endl;
        cout << "Enter your implementation option: ";
        cin >> userOption;
    }
    return userOption;
}

string getCityName(void)
{
    cout << endl << "Enter name of the city: ";
    string cityName;
    cin >> cityName;
    while (cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "Invalid option entered. Please try again." << endl;
        cout << "Enter name of the city: ";
        cin >> cityName;
    }
    return cityName;
}

float getXPos(void)
{
    cout << endl << "Enter x coordinate of the city: ";
    float xPos;
    cin >> xPos;
    while (cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "Invalid option entered. Please try again." << endl;
        cout << "Enter x coordinate of the city: ";
        cin >> xPos;
    }
    return xPos;
}

float getYPos(void)
{
    cout << endl << "Enter y coordinate of the city: ";
    float yPos;
    cin >> yPos;
    while (cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "Invalid option entered. Please try again." << endl;
        cout << "Enter y coordinate of the city: ";
        cin >> yPos;
    }
    return yPos;
}

void insertListRecord(cityData cityList[], string cityName, float xPos, float yPos, int& numCities)
{

    if (numCities < ARRAYSIZE)
    {
        cityData newEntry;
        newEntry.cityName = cityName;
        newEntry.xPos = xPos;
        newEntry.yPos = yPos;
        cityList[numCities] = newEntry;
        numCities++;
        cout << endl << "Record inserted successfully." << endl;
    }
    else
    {
        cout << endl << "Array is full. Please delete an entry first." << endl;
    }
}

void printListRecords(cityData cityList[], int& numCities)
{
    cout << endl << "Output:" << endl;
    for (int i = 0; i < numCities; i++)
    {
        cout << "City " << cityList[i].cityName << " (" << cityList[i].xPos << ", " << cityList[i].yPos << ")" << endl;
    }
}