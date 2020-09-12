#include "Header.h"
#include <iostream>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using namespace std::chrono;

bool timingMode = true;

// function to insert a record into the linked list
void linkedList::insertRecord(string cityName, double xPos, double yPos)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    node* newNode = new node;
    newNode->next = nullptr;
    newNode->cityName = cityName;
    newNode->xPos = xPos;
    newNode->yPos = yPos;
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        cout << endl << "Record inserted successfully." << endl;
    }
    else
    {
        node* last = head;
        while (last != nullptr)
        {
            if (last->cityName == cityName && last->xPos == xPos && last->yPos == yPos)
            {
                cout << "No need to insert again, as this record exists in the existing data set." << endl;
                delete newNode;
                return;
            }
            last = last->next;
        }
        tail->next = newNode;
        tail = tail->next;
        cout << endl << "Record inserted successfully." << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Insert list record operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// function to search the linked list for a record by name
void linkedList::searchByName(string cityName)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    node* last = head;
    bool found = false;
    while (last != nullptr)
    {
        if (last->cityName == cityName)
        {
            if (found == false)
            {
                cout << endl << "Output: " << endl;
            }
            found = true;
            cout << last->cityName << ", (" << last->xPos << ", " << last->yPos << ")" << endl;
        }
        last = last->next;
    }
    if (found == false)
    {
        cout << "No such record exists in the existing data set" << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Search list by name operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// function to search the linked list for specified coordinates
void linkedList::searchByCoord(double xPos, double yPos)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    node* last = head;
    bool found = false;
    while (last != nullptr)
    {
        if (last->xPos == xPos && last->yPos == yPos)
        {
            if (found == false)
            {
                cout << endl << "Output: " << endl;
            }
            found = true;
            cout << last->cityName << ", (" << last->xPos << ", " << last->yPos << ")" << endl;
        }
        last = last->next;
    }
    if (found == false)
    {
        cout << "No such record exists in the existing data set" << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Search list by coordinate operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// function to delete a linked list item by name
void linkedList::deleteByName(string cityName)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    node* current = head;
    node* last = head;
    bool found = false;
    if (head != nullptr)
    {
        if (head->cityName == cityName)
        {
            found = true;
            head = head->next;
            delete last;
            current = nullptr;
        }
        else
        {
            current = head->next;
        }
    }
    while (current != nullptr)
    {
        if (current->cityName == cityName)
        {
            found = true;
            if (current == tail)
            {
                tail = last;
                tail->next = nullptr;
                delete current;
                break;
            }
            else
            {
                last->next = current->next;
                delete current;
                break;
            }
        }
        last = current;
        current = current->next;
    }
    if (found == true)
    {
        cout << "Deleted successfully" << endl;
    }
    else
    {
        cout << "No such record exists in the existing data set." << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Delete list record by name operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// function to delete a linked list item by coordinate
void linkedList::deleteByCoord(double xPos, double yPos)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    node* current = head;
    node* last = head;
    bool found = false;
    if (head != nullptr)
    {
        if (head->xPos == xPos && head->yPos == yPos)
        {
            found = true;
            head = head->next;
            delete last;
            current = nullptr;
        }
        else
        {
            current = head->next;
        }
    }
    while (current != nullptr)
    {
        if (current->xPos == xPos && current->yPos == yPos)
        {
            found = true;
            if (current == tail)
            {
                tail = last;
                tail->next = nullptr;
                delete current;
                break;
            }
            else
            {
                last->next = current->next;
                delete current;
                break;
            }
        }
        last = current;
        current = current->next;
    }
    if (found == true)
    {
        cout << "Deleted successfully" << endl;
    }
    else
    {
        cout << "No such record exists in the existing data set" << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Delete list record by coordinate operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// function to print all records in the linked list within a specified distance
void linkedList::printWithinDistance(string cityName, double distance)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    node* last = head;
    bool found = false;
    double lat1 = -1;
    double long1 = -1;
    while (last != nullptr)
    {
        if (last->cityName == cityName)
        {
            found = true;
            lat1 = decToRad(last->xPos);
            long1 = decToRad(last->yPos);
        }
        last = last->next;
    }
    if (found == false)
    {
        cout << "No such record exists in the existing data set" << endl;
        return;
    }

    cout << endl << "Output:" << endl;
    found = false;
    double lat2 = -1;
    double long2 = -1;
    double calculatedDistance = -1;
    last = head;
    while (last != nullptr)
    {
        lat2 = decToRad(last->xPos);
        long2 = decToRad(last->yPos);
        calculatedDistance = getDistanceBetweenCoords(lat1, long1, lat2, long2);
        if (abs(calculatedDistance) <= distance && cityName != last->cityName)
        {
            found = true;
            cout << "City " << last->cityName << " (" << last->xPos << ", " << last->yPos << ")" << endl;
        }
        last = last->next;
    }
    if (found == false)
    {
        cout << "No such record exists in the existing data set" << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Print all list records operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// function to print all of the items in the linked list
void linkedList::printRecords()
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (head == nullptr)
    {
        cout << "Nothing in list\n";
    }
    else
    {
        node* last = head;
        while (last != nullptr)
        {
            cout << "City " << last->cityName << " (" << last->xPos << ", " << last->yPos << ")" << endl;
            last = last->next;
        }
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Print all list records operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// function to import data from the test data text file into the linked list
void linkedList::importData()
{
    ifstream file;
    file.open("Assignment_1_ Test Data.txt", std::ios::in);
    if (file.is_open())
    {
        cityData tempEntry;
        while (!(std::getline(file, tempEntry.cityName, ':').eof()))
        {
            string name = tempEntry.cityName;
            name.erase(std::remove(name.begin(), name.end(), '\n'), name.end());
            file >> tempEntry.xPos;
            file >> tempEntry.yPos;
            insertRecord(name, tempEntry.xPos, tempEntry.yPos);
        }
    }
}

// function to import data from the test data text file into the array
void importDataArray(cityData cityList[], int& numCities)
{
    ifstream file;
    file.open("Assignment_1_ Test Data.txt", std::ios::in);
    if (file.is_open())
    {
        cityData newEntry;
        while (!(std::getline(file, newEntry.cityName, ':').eof()))
        {
            string name = newEntry.cityName;
            name.erase(std::remove(name.begin(), name.end(), '\n'), name.end());
            file >> newEntry.xPos;
            file >> newEntry.yPos;
            insertArrayRecord(cityList, name, newEntry.xPos, newEntry.yPos, numCities);
        }
    }
    else
    {
        cout << "Error reading file" << endl;
    }
}

// function to print out the menu for the implementation choices and get input from the user
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

// function to print out the menu for operation choices and get input from the user
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

// Get a city name input from the user
string getCityName(void)
{
    cout << endl << "Enter name of the city:";
    string cityName;
    std::getline(cin, cityName);
    std::getline(cin, cityName);
    return cityName;
}

// Get a x coordinate input from the user
double getXPos(void)
{
    cout << endl << "Enter x coordinate of the city: ";
    double xPos;
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

// Get a y coordinate input from the user
double getYPos(void)
{
    cout << endl << "Enter y coordinate of the city: ";
    double yPos;
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

// Get a distance input from the user
double getDistance(void)
{
    cout << endl << "Enter distance: ";
    double distance;
    cin >> distance;
    while (cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "Invalid option entered. Please try again." << endl;
        cout << "Enter distance: ";
        cin >> distance;
    }
    return distance;
}

// Insert a city data item into the array
void insertArrayRecord(cityData cityList[], string cityName, double xPos, double yPos, int& numCities)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    bool duplicate = false;
    if (numCities < ARRAYSIZE)
    {
        for (int i = 0; i < numCities; ++i)
        {
            if (cityList[i].cityName == cityName && cityList[i].xPos == xPos && cityList[i].yPos == yPos)
            {
                duplicate = true;
            }
        }
        if (duplicate == false)
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
            cout << "No need to insert again, as this record exists in the existing data set." << endl;
        }
    }
    else
    {
        cout << endl << "Array is full. Please delete an entry first." << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Insert array record operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// Search the array for a city by name
void searchArrayByName(cityData cityList[], string cityName, int& numCities)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    bool found = false;
    for (int i = 0; i < numCities; ++i)
    {
        if (cityList[i].cityName == cityName)
        {
            if (found == false)
            {
                cout << endl << "Output:" << endl;
            }
            found = true;
            cout << cityList[i].cityName << ", (" << cityList[i].xPos << ", " << cityList[i].yPos << ")" << endl;
        }
    }
    if (found == false)
    {
        cout << "No such record exists in the existing data set" << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Search array by name operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// Search the array for a city by coordinate
void searchArrayByCoord(cityData cityList[], double xPos, double yPos, int& numCities)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    bool found = false;
    for (int i = 0; i < numCities; ++i)
    {
        if (cityList[i].xPos == xPos && cityList[i].yPos == yPos)
        {
            if (found == false)
            {
                cout << endl << "Output:" << endl;
            }
            found = true;
            cout << cityList[i].cityName << ", (" << cityList[i].xPos << ", " << cityList[i].yPos << ")" << endl;
        }
    }
    if (found == false)
    {
        cout << "No such record exists in the existing data set" << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Search array by coordinate operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// Delete an array item by name and shift array items to be contiguous 
void deleteArrayRecordByName(cityData cityList[], string cityName, int& numCities)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    int index = -1;
    for (int i = 0; i < numCities; ++i)
    {
        if (cityList[i].cityName == cityName)
        {
            index = i;
            break; // Assume we are only going to delete the first matching name record
        }
    }
    if (index > -1)
    {
        --numCities;
        for (index; index < numCities; ++index)
        {
            cityList[index] = cityList[index + 1];
        }
        cout << "Deleted successfully" << endl;
    }
    else
    {
        cout << "No such record exists in the existing data set" << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Delete array record by name operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// Delete an array item by coordinate and shift aray items to be contiguous
void deleteArrayRecordByCoord(cityData cityList[], double xPos, double yPos, int& numCities)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    int index = -1;
    for (int i = 0; i < numCities; ++i)
    {
        if (cityList[i].xPos == xPos and cityList[i].yPos == yPos)
        {
            index = i;
            break; // Assume we are only going to delete the first matching coord record
        }
    }
    if (index > -1)
    {
        --numCities;
        for (index; index < numCities; ++index)
        {
            cityList[index] = cityList[index + 1];
        }
        cout << "Deleted successfully" << endl;
    }
    else
    {
        cout << "No such record exists in the existing data set" << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Delete list record by coordinate operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// Print all of the records in the array
void printArrayRecords(cityData cityList[], int& numCities)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    cout << endl << "Output:" << endl;
    for (int i = 0; i < numCities; i++)
    {
        cout << "City " << cityList[i].cityName << " (" << cityList[i].xPos << ", " << cityList[i].yPos << ")" << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Print all list records operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}

// Convert a decimal input to radians
double decToRad(double degrees)
{
    return degrees * (M_PI / 180.0);
}

// Get the distance between two coordinates
double getDistanceBetweenCoords(double lat1, double long1, double lat2, double long2)
{
    double distance = ( sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long2 - long1) );
    distance = R * acos(distance);
    return distance;
}

// Print array records within a given distance
void printArrayWithinDistance(cityData cityList[], string cityName, double distance, int& numCities)
{
    milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    double lat1 = -1;
    double long1 = -1;
    bool found = false;
    for (int i = 0; i < numCities; ++i)
    {
        if (cityList[i].cityName == cityName)
        {
            found = true;
            lat1 = decToRad(cityList[i].xPos);
            long1 = decToRad(cityList[i].yPos);
        }
    }
    if (found == false)
    {
        cout << "No such record exists in the existing data set" << endl;
        return;
    }

    cout << endl << "Output:" << endl;
    found = false;
    double lat2 = -1;
    double long2 = -1;
    double calculatedDistance = -1;
    for (int i = 0; i < numCities; i++)
    {
        lat2 = decToRad(cityList[i].xPos);
        long2 = decToRad(cityList[i].yPos);
        calculatedDistance = getDistanceBetweenCoords(lat1, long1, lat2, long2);
        if (abs(calculatedDistance) <= distance && cityName != cityList[i].cityName)
        {
            found = true;
            cout << "City " << cityList[i].cityName << " (" << cityList[i].xPos << ", " << cityList[i].yPos << ")" << endl;
        }
    }
    if (found == false)
    {
        cout << "No such record exists in the existing data set" << endl;
    }
    milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if (timingMode == true)
    {
        cout << "Print all list records operation took " << endTime.count() - startTime.count() << "ms" << endl;
    }
}