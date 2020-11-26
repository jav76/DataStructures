/*
Data structures 3460:316
Assignment 4
Jaret Varn, jav76@zips.uakron.edu

This program allows a user to select select a size of a set of numbers to run a round of sorts on.
The same set of data is sorted using a bubble sort, insertion sort, selection sort, merge sort, and quicksort with a first element pivot and middle element pivot.
The sorting algorithms are timed for how long they can sort the random data set, and if the data is already sorted.
The times are ranked 1st 2nd and 3rd for n^2 sorts and nlogn sorts.
*/


#include "sorting.h"

int main()
{
    int choice;
    while (true)
    {
        
        choice = getChoice();

        switch (choice)
        {
            case 1: // 1k
            {
                const int SIZE = 1000;
                int original[SIZE];
                int toSort[SIZE];
                int temp[SIZE];
                race(original, toSort, temp, SIZE, true);
                race(original, toSort, temp, SIZE, false);

                break;
            }
            case 2: // 5k
            {
                const int SIZE = 5000;
                int original[SIZE];
                int toSort[SIZE];
                int temp[SIZE];
                race(original, toSort, temp, SIZE, true);
                race(original, toSort, temp, SIZE, false);

                break;
            }
            case 3: // 10k
            {
                const int SIZE = 10000;
                int original[SIZE];
                int toSort[SIZE];
                int temp[SIZE];
                race(original, toSort, temp, SIZE, true);
                race(original, toSort, temp, SIZE, false);

                break;
            }
            case 4: // 50k
            {
                const int SIZE = 50000;
                int original[SIZE];
                int toSort[SIZE];
                int temp[SIZE];
                race(original, toSort, temp, SIZE, true);
                race(original, toSort, temp, SIZE, false);

                break;
            }
            case 5: // 75k
            {
                const int SIZE = 75000;
                int original[SIZE];
                int toSort[SIZE];
                int temp[SIZE];
                race(original, toSort, temp, SIZE, true);
                race(original, toSort, temp, SIZE, false);

                break;
            }
            case 6: // 100k
            {
                const int SIZE = 100000;
                int original[SIZE];
                int toSort[SIZE];
                int temp[SIZE];
                race(original, toSort, temp, SIZE, true);
                race(original, toSort, temp, SIZE, false);

                break;
            }
            case 7: // 500k
            {
                const int SIZE = 500000;
                int original[SIZE];
                int toSort[SIZE];
                int temp[SIZE];
                race(original, toSort, temp, SIZE, true);
                race(original, toSort, temp, SIZE, false);

                break;
            }
        }

    }
    return 0;
}