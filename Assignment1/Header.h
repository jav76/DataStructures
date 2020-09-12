#pragma once
#include <string>
#include <fstream>

using std::string;
using std::ifstream;

const int ARRAYSIZE = 1000;
const double R = 3963.191;
const double M_PI = 3.1415926535;

struct cityData
{
    string cityName = "";
    double xPos = -1;
    double yPos = -1;
};

class linkedList
{

    public:
        struct node
        {
            string cityName = "";
            double xPos = -1;
            double yPos = -1;
            node* next = nullptr;
        };

        node* head = nullptr;
        node* tail = nullptr;

        // function to import data from the test data text file into the linked list
        void importData();

        // function to insert a record into the linked list
        void insertRecord(string cityName, double xPos, double yPos);

        // function to search the linked list for a record by name
        void searchByName(string cityName);

        // function to search the linked list for specified coordinates
        void searchByCoord(double xPos, double yPos);

        // function to delete a linked list item by name
        void deleteByName(string cityName);

        // function to delete a linked list item by coordinate
        void deleteByCoord(double xPos, double yPos);

        // function to print all records in the linked list within a specified distance
        void printWithinDistance(string cityName, double distance);

        // function to print all of the items in the linked list
        void printRecords();


};

// function to import data from the test data text file into the array
void importDataArray(cityData cityList[], int& numCities);

// function to print out the menu for the implementation choices and get input from the user
char getImplementationOption(void);

// function to print out the menu for operation choices and get input from the user
int getOperationOption(void);

// Get a city name input from the user
string getCityName(void);

// Get a x coordinate input from the user
double getXPos(void);

// Get a y coordinate input from the user
double getYPos(void);

// Get a distance input from the user
double getDistance(void);


// Insert a city data item into the array
void insertArrayRecord(cityData cityList[], string cityName, double xPos, double yPos, int& numCities);

// Search the array for a city by name
void searchArrayByName(cityData cityList[], string cityName, int& numCities);

// Search the array for a city by coordinate
void searchArrayByCoord(cityData cityList[], double xPos, double yPos, int& numCities);

// Delete an array item by name and shift array items to be contiguous 
void deleteArrayRecordByName(cityData cityList[], string cityName, int& numCities);

// Delete an array item by coordinate and shift aray items to be contiguous
void deleteArrayRecordByCoord(cityData cityList[], double xPos, double yPos, int& numCities);

// Print all of the records in the array
void printArrayRecords(cityData cityList[], int& numCities);

// Convert a decimal input to radians
double decToRad(double degrees);

// Get the distance between two coordinates
double getDistanceBetweenCoords(double lat1, double long1, double lat2, double long2);

// Print array records within a given distance
void printArrayWithinDistance(cityData cityList[], string cityName, double distance, int& numCities);