#ifndef HEADER_HPP
#define HEADER_HPP
#include <string>

using std::string;

const int ARRAYSIZE = 1000;

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


char getImplementationOption(void);
int getOperationOption(void);
string getCityName(void);
float getXPos(void);
float getYPos(void);

void insertListRecord(cityData cityList[], string cityName, float xPos, float yPos, int& numCities);
void searchListByName(cityData cityList[], string cityName, int& numCities);
void searchListByCoord(cityData cityList[], float xPos, float yPos, int& numCities);
void deleteListRecordByName(cityData cityList[], string cityName, int& numCities);
void deleteListRecordByCoord(cityData cityList[], float xPos, float yPos, int& numCities);
void printListRecords(cityData cityList[], int& numCities);


#endif