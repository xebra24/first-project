/*
Functions that are primarily not doing things with the user
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

#include "header.h"
#include "ui.h"
#include "logic.h"
#include "file_management.h"

using std::cin;
using std::cout;
using std::vector;

void basicStatistics()
{
    vector<char> yes_or_no(1);
    cout << "Would you like to see some basic statistics? y/n: ";
    cin >> yes_or_no[0];

    if (yes_or_no[0] == 'y' || yes_or_no[0] == 'Y')
    {
        std::sort(people.begin(), people.end(), sortPancakes);

        int sum = 0, num_people = 0;
        double average = 0, median_person = 0, median = 0;

        for (auto &element : people)
        {
            sum += element.returnPancakesConsumed();
            ++num_people;
        }

        if (num_people % 2)
        {
            median = (people.at(people.size() / 2).returnPancakesConsumed() + people.at((people.size() / 2) + 1).returnPancakesConsumed()) / 2;
        }

        else
        {
            median = people.at(people.size() / 2).returnPancakesConsumed();
        }

        average = sum / num_people;

        cout << "\nThe average number of pancakes consumed is "
             << average << ".\n";

        cout << "\nThe median number of pancakes consumed is "
             << median << ".\n\n";

        std::sort(people.begin(), people.end(), sortPNum); // Reset ordering of people
    }

    else if (yes_or_no[0] == 'n' || yes_or_no[0] == 'N')
    {
        return;
    }

    else
    {
        cout << "Your entry is invalid, please try again.";
    }
}

// For use in std::sort(); used instead of operator<
bool sortPancakes(const Person &lhs, const Person &rhs)
{
    return lhs.returnPancakesConsumed() < rhs.returnPancakesConsumed(); //Person.cpp
}

// For use in std::sort(); used instead of operator<
bool sortPNum(const Person &lhs, const Person &rhs)
{
    return lhs.returnPersonNumber() < rhs.returnPersonNumber(); //Person.cpp
}

// Allow user choice of creating new data or reviewing old data
void choose()
{
    printFileContents(choice_txt);

    vector<char> choice(1);
    cin >> choice[0];

    // If creating new data
    if (choice[0] == '1')
    {
        getPeople();
        check();
        basicStatistics();
        sortPeople();
        saveInput();
        waitToExit();
    }

    // Otherwise we review old .txt output file (NOT FUNCTIONAL)
    else if (choice[0] == '2')
    {
        showOutFiles();
        waitToExit();
    }

    else if (choice[0] == '3')
    {
        return;
    }

    else
    {
        std::cerr << "Your entry is invalid, please try again.\n";
        choose();
    }
}

// Check if user wants ordered list, if yes returns sorted
// vector<People> people, low to high, otherwise exits program.
void sortPeople()
{
    vector<char> yes_or_no(1);
    cout << "\nWould you like an ordered list? y/n: ";
    cin >> yes_or_no[0];

    if (yes_or_no[0] == 'y' || yes_or_no[0] == 'Y')
    {
        cout << std::endl;
        std::sort(people.begin(), people.end(), sortPancakes);
        for (auto &element : people)
        {
            element.printPancakesEaten(cout, element); // Person.cpp
        }
    }

    else if (yes_or_no[0] == 'n' || yes_or_no[0] == 'N')
    {
        return;
    }

    else
    {
        cout << "Your entry is invalid, please try again.\n";
        sortPeople();
    }

    std::sort(people.begin(), people.end(), sortPNum); // Reset ordering of people
}