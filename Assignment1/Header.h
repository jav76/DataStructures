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
    float xPos = -1;
    float yPos = -1;
};

class node
{
public:
    string cityName = "";
    float xPos = -1;
    float yPos = -1;
    node* next = nullptr;
};

void importDataList(cityData cityList[], int& numCities);

char getImplementationOption(void);
int getOperationOption(void);
string getCityName(void);
float getXPos(void);
float getYPos(void);
float getDistance(void);

void insertListRecord(cityData cityList[], string cityName, float xPos, float yPos, int& numCities);
void searchListByName(cityData cityList[], string cityName, int& numCities);
void searchListByCoord(cityData cityList[], float xPos, float yPos, int& numCities);
void deleteListRecordByName(cityData cityList[], string cityName, int& numCities);
void deleteListRecordByCoord(cityData cityList[], float xPos, float yPos, int& numCities);
void printListRecords(cityData cityList[], int& numCities);
double decToRad(double degrees);
double getDistanceBetweenCoords(double lat1, double long1, double lat2, double long2);
void printListWithinDistance(cityData cityList[], string cityName, float distance, int& numCities);