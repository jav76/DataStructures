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

int getChoice(); // Gets the user selected choice for the size of data
void genData(int*, int); // Fills an array with random numbers
void printArray(int* data, int size); // Prints out elements in an array (for testing purposes)
void copyArray(int* source, int* dest, int size); // Copies the elements of one array to another array

// Times all the sorting algorithms on the random and sorted dataset and displays the ranked timing results
void race(int* original, int* toSort, int* temp, int size, bool sorted); 


void bubbleSort(int* data, int size); // Implementation of the bubble sort
void insertionSort(int* data, int size); // Implementation of the insertion sort
void selectionSort(int* data, int size); // Implementation of the selection sort


void mergeSort(int* data, int* temp, int left, int right); // Implementation of the merge sort

int partitionMid(int* data, int left, int right); // Partitions arrays with a middle pivot for quick sort
void quickSortMid(int* data, int left, int right); // Implementation of the quick sort with a middle pivot

int partitionFirst(int* data, int left, int right); // Partitions arrays with a first element pivot for quick sort
void quickSortFirst(int* data, int left, int right);// Implementation of the quick sort with a first element pivot