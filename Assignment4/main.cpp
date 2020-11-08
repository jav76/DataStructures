#include "sorting.h"


int main()
{
    int choice;
    while (true)
    {
        
        choice = getChoice();
        //choice = 20;

        vector<int> unsorted = genData(choice);
        

        /*
        for (vector<int>::iterator begin = unsorted.begin(); begin != unsorted.end(); ++begin)
        {
            cout << *begin << endl;
        }
        */

        vector<int> toSort(unsorted);

        cout << "\n\n\n\n\n\n\n\n";

        vector<int> sorted = bubbleSort(toSort);

        /*
        for (vector<int>::iterator begin = sorted.begin(); begin != sorted.end(); ++begin)
        {
            cout << *begin << endl;
        }
        */

    }
}


int getChoice()
{
    cout << "1) 1000" << endl;
    cout << "2) 5000" << endl;
    cout << "3) 10,000" << endl;
    cout << "4) 50,000" << endl;
    cout << "5) 75,000" << endl;
    cout << "6) 100,000" << endl;
    cout << "7) 500,000" << endl;
    cout << "Enter the size of the dataset to test: ";

    int choice;
    cin >> choice;
    while (cin.fail() || choice < 1 || choice > 7)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "Invalid option. Please try again." << endl;
        cin >> choice;
    }
    switch (choice)
    {
        case 1:
            return 1000;
        case 2:
            return 5000;
        case 3:
            return 10000;
        case 4:
            return 50000;
        case 5:
            return 75000;
        case 6:
            return 100000;
        case 7:
            return 500000;
    }
}