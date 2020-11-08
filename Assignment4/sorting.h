#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using namespace std::chrono;

vector<int>genData(int size);

int getChoice();
vector<int> bubbleSort(vector<int> data);