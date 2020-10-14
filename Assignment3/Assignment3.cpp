#include <iostream>
#include "BST.h"

void printMenu();
int getChoice();
double getKey();

int main()
{
    binarySearchTree tree;
    bool quit = false;
    while (!quit)
    {
        printMenu();
        
        switch (getChoice())
        {
            case 1: // Search for a key
            {
                double key = getKey();
                binarySearchTree::node* found = tree.findKey(key);
                if (found != nullptr)
                {
                    std::cout << key << " exists in the tree.\n";
                }
                else
                {
                    std::cout << key << " does not exist in the tree.\n";
                }
                break;
            }

            case 2:
            {
                tree.insertNode(getKey());
                break;
            }

            case 3:
            {
                tree.deleteNode(getKey());
                break;
            }

            case 4:
            {
                // unimplemented
                break;
            }

            case 5:
            {
                tree.printTree();
                break;
            }

            case 6:
            {
                tree.expensivePath(getKey());
                break;
            }

            case 7:
            {
                quit = true;
                break;
            }
        }

    }
    return 0;
}


void printMenu()
{
    using std::cout;
    using std::endl;
    cout << "Select an operating for the binary search tree:" << endl;
    cout << "1) Search for a key value" << endl;
    cout << "2) Insert a new node" << endl;
    cout << "3) Delete a node" << endl;
    cout << "4) Display the tree" << endl;
    cout << "5) Print the keys in the tree" << endl;
    cout << "6) Print the cost of a path in the tree" << endl;
    cout << "7) Quit" << endl;
}

int getChoice()
{   
    using std::cout;
    using std::cin;
    int choice;
    cout << "Enter your operation: ";
    cin.clear();
    cin >> choice;
    while (cin.fail() || choice < 1 || choice > 7)
    {
        cout << "Invalid choice. Please enter a new operation: ";
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> choice;
    }
    cout << std::endl;
    return choice;
}

double getKey()
{
    using std::cout;
    using std::cin;
    double choice;
    cout << "Enter your key value: ";
    cin >> choice;
    while (cin.fail())
    {
        cout << "Invalid key. Enter a new key value: ";
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> choice;
    }
    cout << std::endl;
    return choice;
}