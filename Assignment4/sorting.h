#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <chrono>
#include <map>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::multimap;
using std::string;
using std::pair;
using namespace std::chrono;



void genData(int*, int);
void printArray(int* data, int size);
void copyArray(int* source, int* dest, int size);

void bubbleSort(int* data, int size);
void insertionSort(int* data, int size);
void selectionSort(int* data, int size);


void mergeSort(int* data, int* temp, int left, int right);

int partitionMid(int* data, int left, int right);
void quickSortMid(int* data, int left, int right);

int partitionFirst(int* data, int left, int right);
void quickSortFirst(int* data, int left, int right);

void race(int* original, int* toSort, int* temp, int size, bool sorted);
int getChoice();