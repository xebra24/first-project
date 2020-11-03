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
#include "file_manage.h"
#include "header.h"

using std::vector;
using std::cout;
using std::cin;

// Add user-specified number of people to vector<Person> people;
void getPeople()
{
    int numPeople;
    cout << "\nHow many people are there? ";
    cin >> numPeople;
    cout << '\n';

    for (int i = 1; i <= numPeople; ++i) 
    {
        Person person(i, 0);
        people.push_back(person);
    }

    for (auto& element : people) 
    {
        element.getPancakesConsumed(element);       // Person.cpp
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
    std::ifstream out ("outFiles/2020-10-25-2151.txt");
    string line;
    if (out.is_open()) 
    {
        while (std::getline(out, line)) 
        {
            cout << line << '\n';
        }
        out.close();
    }
    
    else 
    {
        std::cerr << "Error opening file!" << std::endl;
    }
}

vector<Person> editEntries(vector<Person>& vec) 
{
    int personToEdit;
    cout << "Please type the number of the person to edit: ";
    cin >> personToEdit;
    cout << '\n';

    people[personToEdit].getPancakesConsumed(people[personToEdit - 1]);

    return people;
}