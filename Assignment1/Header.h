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

        void insertRecord(string cityName, double xPos, double yPos);
        void searchByName(string cityName);
        void searchByCoord(double xPos, double yPos);
        void deleteByName(string cityName);
        void deleteByCoord(double xPos, double yPos);
        void printRecords();


};

void importDataArray(cityData cityList[], int& numCities);

char getImplementationOption(void);
int getOperationOption(void);
string getCityName(void);
double getXPos(void);
double getYPos(void);
double getDistance(void);

void insertArrayRecord(cityData cityList[], string cityName, double xPos, double yPos, int& numCities);
void searchArrayByName(cityData cityList[], string cityName, int& numCities);
void searchArrayByCoord(cityData cityList[], double xPos, double yPos, int& numCities);
void deleteArrayRecordByName(cityData cityList[], string cityName, int& numCities);
void deleteArrayRecordByCoord(cityData cityList[], double xPos, double yPos, int& numCities);
void printArrayRecords(cityData cityList[], int& numCities);
double decToRad(double degrees);
double getDistanceBetweenCoords(double lat1, double long1, double lat2, double long2);
void printArrayWithinDistance(cityData cityList[], string cityName, double distance, int& numCities);