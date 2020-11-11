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