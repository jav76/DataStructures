
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string; 

char getImplementationOption(void);

struct cityData
{
    string cityName;
    float xPos;
    float yPos;
};

int main()
{
    cityData citiesList[1000];
    while (true)
    {
        getImplementationOption();
    }




}


char getImplementationOption(void)
{
    char userOption;
    cout << "Select an implementation option:" << endl;
    cout << "A. Use an array-based list implementation" << endl;
    cout << "B. Use a linked-list based implementation" << endl;
    cin >> userOption;
    userOption = toupper(userOption);
    while (cin.fail() || (userOption != 'A' && userOption != 'B'))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "Invalid option entered. Please try again." << endl << endl;
        cout << "A. Use an array-based list implementation" << endl;
        cout << "B. Use a linked-list based implementation" << endl;
        cin >> userOption;
        userOption = toupper(userOption);
    }
    cout << "User selected option " << userOption << endl;
    return userOption;

}

void insertRecord(char implementation, &citiesList, )
{

}