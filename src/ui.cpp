/*
Functions that are primarily outputting things/interacting with user
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime>

#include "ui.h"
#include "logic.h"
#include "file_management.h"
#include "header.h"

using std::cin;
using std::cout;
using std::vector;

// Allow user to check their entries
void check()
{
    vector<char> yes_or_no(1);
    cout << "\nDo you want to check your entries? y/n: ";
    cin >> yes_or_no[0];
    cout << '\n';

    if (yes_or_no[0] == 'y' || yes_or_no[0] == 'Y')
    {
        for (auto const &element : people)
        {
            element.printPancakesEaten(cout, element); // Person.cpp
        }
        cout << '\n';

        vector<char> yes_or_no2(1);
        cout << "Is this correct? y/n: ";
        cin >> yes_or_no2[0];

        if (yes_or_no2[0] == 'N' || yes_or_no2[0] == 'n')
        {
            editEntries();
        }

        else if (yes_or_no2[0] == 'Y' || yes_or_no2[0] == 'y')
        {
            return;
        }

        else
        { // TODO: Add function to go back to beginning of if statement
            cout << "Your entry is invalid, please try again.";
        }
    }

    else if (yes_or_no[0] == 'n' || yes_or_no[0] == 'N')
    {
        return;
    }

    else
    {
        std::cerr << "Your entry is invalid, please try again.\n";
        check();
    }
}

// Add user-specified number of people to vector<Person> people;
void getPeople()
{
    int numPeople;
    cout << "\nHow many people are there? ";
    cin >> numPeople;
    cout << '\n';

    for (int i = 1; i <= numPeople; ++i)
    {
        Person person(i);
        people.push_back(person);
    }

    for (auto &element : people)
    {
        element.getPancakesConsumed(element); // Person.cpp
    }
}

// Don't immediately exit
void waitToExit()
{
    string input;
    cout << "\nType anything, then press enter to exit program.\n";
    cin >> input;
}

void viewOldData()
{
    cout << "\nChoose a file from the following list to review!\n";
    cout << "Type the number at the front of the file name and press enter.\n\n";
    showOutFiles();
    cout << '\n';
}

vector<Person> editEntries()
{
    int personToEdit;
    cout << "Please type the number of the person to edit: ";
    cin >> personToEdit;
    cout << '\n';

    people[personToEdit].getPancakesConsumed(people[personToEdit - 1]);

    return people;
}